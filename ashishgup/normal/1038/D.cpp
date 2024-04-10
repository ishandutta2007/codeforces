#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, minval=1e9, ans=0;
int a[N];
bool checkpos=0, checkneg=0;

int32_t main()
{
	IOS;
	cin>>n;
	if(n==1)
	{
	    int k;
	    cin>>k;
	    cout<<k;
	    exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minval=min(abs(a[i]), minval);
		checkpos|=(a[i]>=0);
		checkneg|=(a[i]<=0);
		ans+=abs(a[i]);
	}
	if(checkpos&&checkneg)
		cout<<ans;
	else
		cout<<ans-2*minval;
	return 0;
}