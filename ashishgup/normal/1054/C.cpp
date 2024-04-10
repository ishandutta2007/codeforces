#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int l[N], r[N], vis[N], ans[N], pref[N], suf[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	for(int i=1;i<=n;i++)
		cin>>r[i];
	int cnt=0, cur=n;
	for(int turn=1;turn<=n;turn++)
	{
		memset(pref, 0, sizeof(pref));
		memset(suf, 0, sizeof(suf));
		for(int i=1;i<=n;i++)
		{
			if(l[i]==0 && r[i]==0 && !vis[i])
			{
				vis[i]=1;
				cnt++;
				ans[i]=cur;
				pref[i]=1;
				suf[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
			pref[i]+=pref[i-1];
		for(int i=n;i>=1;i--)
			suf[i]+=suf[i+1];
		for(int i=1;i<=n;i++)
		{
			l[i]-=pref[i];
			r[i]-=suf[i];
		}
		cur--;
	}
	if(cnt==n)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" ";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}