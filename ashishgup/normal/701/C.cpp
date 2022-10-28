#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ct=0, cur=0, ans;
char a[N];
int reqd[N], have[N];

int32_t main()
{
	IOS;
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(!reqd[a[i]])
			ct++;
		reqd[a[i]]++;
	}
	int l=1;
	for(int r=1;r<=n;r++)
	{
		if(!have[a[r]])
			cur++;
		have[a[r]]++;
		while(l<=r && have[a[l]]>1)
		{
			have[a[l]]--;
			l++;
		}
		if(cur==ct)
			ans=min(ans, r-l+1);
	}
	cout<<ans;
	return 0;
}