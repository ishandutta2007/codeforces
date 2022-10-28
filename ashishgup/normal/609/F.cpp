#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, m;
int cnt[N];
long long len[N];
int st[4*N];
pair<int, long long> v[N];
map<int, int> tmp;
int posn[N];
multiset<pair<int, int> > s;

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=v[L].second+v[L].first;
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=max(st[node*2], st[node*2+1]);
}

int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return -1e9;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)/2;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return max(left, right);
}

void update(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st[node]+=val;
		st[node]=min(st[node], (int)1e9+5);
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update(node*2, L, M, pos, val);
	else
		update(node*2 + 1, M+1, R, pos, val);
	st[node]=max(st[node*2], st[node*2 + 1]);
}

int check(int x, int i, int j)
{
	return query(1, 1, n, i, j) >= x;
}

int binsearch(int x, int lo, int hi)
{
	if(hi<lo)
		return -1e9;
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(x, lo, mid))	
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

bool check2(int idx)
{
	if(!s.size())
		return 0;
	int range=v[idx].first + v[idx].second;
	auto it=s.upper_bound({range, 2e9});	
	if(it!=s.begin())
	{
		it--;
		if(it->first<v[idx].first || it->first-v[idx].first>v[idx].second)
			return 0;
		update(1, 1, n, idx, it->second);
		v[idx].second+=it->second;
		cnt[posn[idx]]++;
		len[posn[idx]]+=it->second;
		s.erase(it);
		return 1;
	}
	return 0;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i].first>>v[i].second;
		tmp[v[i].first]=i;
		len[i]=v[i].second;
	}
	sort(v+1, v+n+1);
	for(int i=1;i<=n;i++)
		posn[i]=tmp[v[i].first];
	build(1, 1, n);
	while(m--)
	{
		int pos, sz;
		cin>>pos>>sz;
		pair<int, long long> p = {pos, 2e9};
		auto it=upper_bound(v+1, v+n+1, p) - v - 1;
		int idx=binsearch(pos, 1, it);
		if(it<1 || !check(pos, idx, idx))
			s.insert({pos, sz});
		else
		{
			update(1, 1, n, idx, sz);
			v[idx].second+=sz;
			cnt[posn[idx]]++;
			len[posn[idx]]+=sz;
			while(check2(idx));
		}	
	}
	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<" "<<len[i]<<endl;
	return 0;
}