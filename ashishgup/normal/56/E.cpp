#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ctr=0;
int st[4*N], st2[4*N], ans[N];
map<int, int> m, rm;
map<int, int> idx;
pair<int, int> a[N];
vector<int> v;

void update(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st[node]=val;
		st2[node]=L;
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update(node*2, L, M, pos, val);
	else
		update(node*2+1, M+1, R, pos, val);
	st[node]=max(st[node*2], st[node*2+1]);
	if(st[node]==st[node*2])
		st2[node]=st2[node*2];
	else
		st2[node]=st2[node*2+1];
}

pair<int, int> query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return {-1e9, 0};
	if(i<=L && R<=j)
		return {st[node], st2[node]};
	int M=(L+R)/2;
	pair<int, int> left=query(node*2, L, M, i, j);
	pair<int, int> right=query(node*2+1, M+1, R, i, j);
	if(left.first>right.first)
		return left;
	return right;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		idx[a[i].first]=i;
		m[a[i].first];
		v.push_back(a[i].first);
	}
	sort(v.begin(), v.end());
	for(auto &it:m)
		it.second=++ctr;
	sort(a+1, a+n+1);
	for(int i=n;i>=1;i--)
	{
		int cur=a[i].first;
		int nxt=a[i].first+a[i].second;
		auto it=lower_bound(v.begin(), v.end(), nxt);
		it--;
		int maxidx=m[*it];
		pair<int, int> p = query(1, 1, n, i, maxidx);
		int curans;
		if(p.first==0)
			curans=1;
		else
			curans=p.first - i;
		update(1, 1, n, i, i+curans);
		ans[idx[a[i].first]]=curans;
	}	
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}