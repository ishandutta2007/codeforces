#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, k, p, q, sz1, sz2;
int a[N], pref[N];
int cache[5002][5002];

int dp(int cnt1, int cnt2)
{	
	if(cnt1>p)
		return 1e15;
	if(cnt2>q)
		return 1e15;
	if(cnt1==p && cnt2==q)
		return 0;
	int &ans=cache[cnt1][cnt2];
	if(ans!=-1)
		return ans;
	ans=1e15;
	int idx=cnt1*sz1 + cnt2*sz2 + 1;
	ans=min(ans, pref[idx+sz1-2] - pref[idx-1] + dp(cnt1+1, cnt2));
	ans=min(ans, pref[idx+sz2-2] - pref[idx-1] + dp(cnt1, cnt2+1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n-1;i++)
		pref[i]=pref[i-1] + abs(a[i]-a[i+1]);
	int large=n%k;
	p=k-large;
	q=large;
	sz1=n/k;
	sz2=n/k + 1;
	int ans=dp(0, 0);
	cout<<ans;
	return 0;
}