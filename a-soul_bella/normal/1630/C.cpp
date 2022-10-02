#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[200005],b[200005];
pair <int,int> a[200005];
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}

struct stree
{
	int mx,l,r;
}t[1100005];
const int QWQ=262144;
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r) return ;
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
}
inline void change(int now,int x,int d)
{
	if(t[now].l==t[now].r)
	{
		t[now].mx=d;
		return ;
	}
	if(t[now*2].r>=x) change(now*2,x,d);
	else change(now*2+1,x,d);
	t[now].mx=max(t[now*2].mx,t[now*2+1].mx);
}
inline int query(int now,int l,int r)
{
	if(l>r) return -1e9;
	if(t[now].l==l&&t[now].r==r) return t[now].mx;
	if(t[now*2].r>=r) return query(now*2,l,r);
	else if(t[now*2+1].l<=l) return query(now*2+1,l,r);
	return max(query(now*2,l,t[now*2].r),query(now*2+1,t[now*2+1].l,r));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
		if(!a[b[i]].first) a[b[i]].first=i;
		a[b[i]].second=i;
	}
	build(1,0,n+QWQ);
	for(int i=0;i<=n;i++) change(1,i,-1),change(1,i+QWQ,-i-1);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
//.	cout << query(1,0,a[i].first-1)+a[i].second-a[i].first << "  ";
//		cout << a[i].first << " " << a[i].second-1 << " " << query(1,a[i].first+QWQ,a[i].second-1+QWQ) << "\n";
		dp[a[i].second]=max(query(1,0,a[i].first-1)+a[i].second-a[i].first,query(1,a[i].first+QWQ,a[i].second-1+QWQ)+a[i].second);
		change(1,a[i].second,dp[a[i].second]-1);
		change(1,a[i].second+QWQ,dp[a[i].second]-1-a[i].second);
	/*	for(int j=0;j<a[i].first;j++)
			dp[a[i].second]=max(dp[a[i].second],dp[j]+a[i].second-a[i].first-1);
		for(int j=a[i].first;j<a[i].second;j++)
			dp[a[i].second]=max(dp[a[i].second],dp[j]+a[i].second-j-1);*/
	}
//	for(int i=0;i<=n;i++)
//	{
//		cout << dp[i] << " ";
//	}
	int mx=0;
	for(int i=0;i<=n;i++) mx=max(mx,dp[i]);
	cout << mx;
	return 0;
}