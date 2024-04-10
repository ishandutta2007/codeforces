#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int pref[N], ans[N];
string s;

void quit()
{
	cout<<"-1";
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
	{
		pref[i]=pref[i-1] + ((s[i-1]=='(')?1:-1);
		ans[i]=(s[i-1]=='#');
		if(pref[i]<0)
			quit();
	}
	int extra=pref[n];
	for(int i=n;i>=1;i--)
	{
		if(s[i-1]=='#')
		{
			int adjust=min(extra, pref[i]);
			ans[i]+=adjust;
			extra-=adjust;
			pref[i]-=adjust;
			for(int j=i+1;j<=n;j++)
			{
				pref[j]=pref[j-1] + ((s[j-1]=='(')?1:-1);
				if(pref[j]<0)
					quit();
			}
			if(pref[n]!=0)
				quit();
			break;
		}
	}
	if(extra>0)
		quit();
	for(int i=1;i<=n;i++)
		if(s[i-1]=='#')
			cout<<ans[i]<<endl;
	return 0;
}