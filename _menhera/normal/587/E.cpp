#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
const int MAXN = 1 << 18;
const int SZBASIS = 32;
int N, Q;
int basis[2*MAXN][SZBASIS];
int sz[2*MAXN];
bool zero[2*MAXN]; //most wtf part, can make 0 by xoring odd bases
int lazy[2*MAXN];

pair<vector<int> , bool> resolve(vector<int> arr, bool z)
{
	//this will find basis and kill you.
	int n=arr.size();
	bool wtf[64];
	for(int i=0;i<64;i++) wtf[i]=true;
	
	int mbit = 30;
	int bcnt = 0;
	for(int j=mbit; j>=0; j--)
	{
		int v = 1<<j;
		for(int i=bcnt; i<n; i++)
		{
			if(arr[i] & v)
			{
				int t=arr[i]; arr[i]=arr[bcnt]; arr[bcnt]=t;
				bool x=wtf[i]; wtf[i]=wtf[bcnt]; wtf[bcnt] = x;
				for(int k=bcnt+1; k<n; k++)
				{
					if(v&arr[k])
					{
						arr[k]^=arr[bcnt];
						wtf[k]^=wtf[bcnt];
					}
				}
				bcnt++;
				break;
			}
		}
	}
	vector<int> res;
	for(int i=0; i<bcnt; i++)
	{
		if(wtf[i]) res.push_back(arr[i]);
		else res.push_back(arr[i]^arr[0]);
	}
	for(int i=bcnt; i<n; i++)
		if(wtf[i])
			z = true;
	return make_pair(res, z);
} 


void merge(int a)
{
	vector<int> r;
	int u=2*a, v=2*a+1;
	for(int i=0; i<sz[u]; i++) r.push_back(basis[u][i]);
	for(int i=0; i<sz[v]; i++) r.push_back(basis[v][i]);
	bool z = zero[u] || zero[v];
	pair<vector<int> , bool> x= resolve(r, z);
	sz[a] = x.first.size();
	for(int i=0;i<sz[a];i++)
		basis[a][i]=x.first[i];
	zero[a] = x.second; 
	
}

void unlocklazy(int a)
{
	if(!lazy[a]) return;
	int v = lazy[a];
	lazy[a] = 0;
	vector<int> r;
	for(int i=0; i<sz[a]; i++)
		r.push_back(basis[a][i]^v);
	if(zero[a])
		r.push_back(v);
	pair<vector<int> , bool> x = resolve(r, false);
	sz[a] = x.first.size();
	for(int i=0;i<sz[a];i++)
		basis[a][i]=x.first[i];
	zero[a] = x.second; 
	if(a<MAXN) lazy[2*a]^=v, lazy[2*a+1]^=v;
	return;
}

void buildSegtree()
{
	for(int i = MAXN-1; i>=0; i--)
		merge(i);
}

void segtree(int a, int s, int e, int l, int r, int k)
{
	unlocklazy(a);
	if(e<l || r<s) return;
	if(l<=s && e<=r)
	{
		lazy[a] ^= k;
		unlocklazy(a);
		return;
	}
	int m = (s+e)/2;
	segtree(2*a, s, m, l, r, k);
	segtree(2*a+1, m+1, e, l, r, k);
	merge(a);
	return;
}

void query1(int l, int r,int k)
{
	segtree(1, 0, MAXN-1, l, r, k);
}

vector<int> wt;


void pint(int a,int s,int e, int l, int r)
{
	if(e<l || r<s) return;
	
	unlocklazy(a);
	if(l<= s && e<=r) 
	{
		wt.push_back(a);
		return;
	}
	int m = (s+e)/2;
	pint(2*a,s,m,l,r);
	pint(2*a+1,m+1,e,l,r);
}

int query2(int l, int r)
{
	wt.clear();
	pint(1, 0, MAXN-1, l, r);
	vector<int> rr;
	for(int i=0; i<wt.size();i++)
	{
		for(int j=0; j<sz[wt[i]]; j++)
			rr.push_back(basis[wt[i]][j]);
		rr = resolve(rr, false).first;
	}
	return 1<<rr.size();
}

int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=0; i<N; i++)
	{
		int t;
		scanf("%d", &t);
		if(t)
			basis[MAXN+i][sz[MAXN+i]++] = t;
		else 
			zero[MAXN+i] = true;
	}
	
	buildSegtree();
	
	for(int i=0; i<Q; i++)
	{
		int t;
		scanf("%d", &t);
		if(t==1)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			l--;
			r--;
			query1(l,r,k);
		}
		else
		{
			int l, r;
			scanf("%d%d",&l,&r);
			l--;
			r--;
			printf("%d\n",query2(l,r));
		}
	}
	return 0;
}