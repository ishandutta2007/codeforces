#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, m, ans=0;
char a[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	a[0]=a[n+1]='?';
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		ans+=(a[i]=='.' && a[i+1]=='.');
	while(m--)
	{
		int x;
		char ch;
		cin>>x>>ch;
		if(ch=='.' && a[x]!=ch)
		{
			a[x]='.';
			ans+=(a[x-1]=='.');
			ans+=(a[x+1]=='.');
		}
		else if(ch!='.' && a[x]=='.')
		{
			a[x]=ch;
			ans-=(a[x-1]=='.');
			ans-=(a[x+1]=='.');
		}
		cout<<ans<<endl;
	}
	return 0;
}