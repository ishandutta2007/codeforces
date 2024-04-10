#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, w;
char a[N];
int pref[N];

int32_t main()
{
	IOS;
	cin>>n>>k>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=(a[i]=='1');
		if(i-k>=1)
			pref[i]+=pref[i-k];
	}	
	for(int i=1;i<=w;i++)
	{
		int l, r;
		cin>>l>>r;
		int len=(r-l+1)/k;
		int ans=len - (pref[r] - pref[l-1]);
		for(int j=0;j<k-1;j++)
		{
			ans+=(pref[l+j+(len-1)*k]);
			if(l+j-k>=0)
				ans-=pref[l+j-k];
		}
		cout<<ans<<endl;
	}
	return 0;
}