#include<bits/stdc++.h>
using namespace std;
int x[101010];
int r[101010];
int sf[101010];
vector<int> f[10101];
int N, K;

bool cmp(int a, int b)
{
	if(r[a]>r[b]) return true;
	if(r[a]<r[b]) return false;
	return a>b;
}

struct Node
{
	Node *left;
	Node *right;
	int ans;
}wtf[15000000]; //200MB?


int tp = 0;
Node* bl()
{
	Node* ret = wtf+tp;
	++tp;
	ret->left=NULL;
	ret->right=NULL;
	ret->ans = 0;
	return ret;
}
void memfree()
{
	tp = 0;
}
int _s, _e;
int calc(Node *x, int l, int r)
{
	if(!(x->ans)) return 0;
	if(_e<l || r<_s) return 0;
	if(_s<=l && r<=_e) return x->ans;
	int m=(l+r)/2;
	if(!(x->left)) x->left=bl();
	if(!(x->right)) x->right=bl();
	return calc(x->left,l,m)+calc(x->right,m+1,r);
}
void push(Node *x, int l, int r, int v)
{
	if(l==v && v==r)
	{
		x->ans ++;
		return;
	}
	int m = (l+r)/2;
	if(v<=m)
	{
		if(!(x->left))x->left=bl();
		push(x->left,l,m,v);
	}
	else
	{
		if(!(x->right))x->right=bl();
		push(x->right, m+1, r, v);
	}
	x->ans = 0;
	if(x->left) x->ans += x->left->ans;
	if(x->right) x->ans += x->right->ans;
	//printf("%d %d %d\n",l,r,x->ans);
}
const int inf = 1e9+10;

long long int solve(int tF) // for targetF
{
	long long ans= 0 ;
	//tF-K ~ tF+K
	vector<int> tot;
	for(int i=tF-K; i<=tF+K; i++)
		for(int x: f[i])
			tot.push_back(x);
	sort(tot.begin(), tot.end(), cmp);
	Node *allF = bl();
	Node *onlyF = bl();
	for(int i: tot)
	{
		//printf("%d: %d\n",i,tF);
		if(sf[i]==tF)
		{
			//calc for allF
			int le = max(0, x[i]-r[i]);
			int re = min(inf, x[i]+r[i]);
			_s=le; _e=re;
			ans += calc(allF,0, inf);
			ans += calc(onlyF,0,inf);//wtf??
			//push for onlyF
			push(onlyF, 0,inf,x[i]);
			//push for allF
			push(allF, 0,inf,x[i]);
			//printf("%d\n",calc(allF,0,inf,0,inf));
		}
		else
		{
			//calc for onlyF
			int le = max(0, x[i]-r[i]);
			int re = min(inf, x[i]+r[i]);
			_s=le; _e=re;
			ans += calc(onlyF,0,inf);
			//printf("--%d %d %d\n",calc(onlyF,0,inf,le,re),le,re);
			//push for allF
			push(allF, 0,inf,x[i]);
		}
	}
	memfree();
	//if(ans)
	//printf("@%d, ret%lld\n",tF,ans);
	return ans;
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++)
	{
		scanf("%d%d%d",x+i,r+i,sf+i);
		sf[i] += 20;
		f[sf[i]].push_back(i);
	}
	long long int ans = 0;
	for(int i=15; i<10050; i++)
		ans += solve(i);
	//printf("asdf");
	printf("%lld",ans/2);
}