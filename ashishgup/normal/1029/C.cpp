#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n;
int l[N], r[N];
int prefl[N], prefr[N], sufl[N], sufr[N];

int32_t main()
{
	IOS;
	cin>>n;
	prefl[0]=sufl[n+1]=-1, prefr[0]=sufr[n+1]=1e9+1;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		prefl[i]=max(l[i], prefl[i-1]);
		prefr[i]=min(r[i], prefr[i-1]);
	}
	for(int i=n;i>=1;i--)
	{
		sufl[i]=max(l[i], sufl[i+1]);
		sufr[i]=min(r[i], sufr[i+1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int curl=max(prefl[i-1], sufl[i+1]);
		int curr=min(prefr[i-1], sufr[i+1]);
		ans=max(ans, max(0LL, curr-curl));
	}
	cout<<ans;
	return 0;
}