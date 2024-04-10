#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, store=0;
int a[N], b[N], ans[N], ans2[N], finans[N];
char s[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
		cin>>s[i];
	ans[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i-1]=='R')
			ans[i]=ans[i-1]+1;
		else if(s[i-1]=='=')
			ans[i]=ans[i-1];
		else
			ans[i]=1;
	}
	ans2[n]=1;
	finans[n]=ans[n];
	for(int i=n-1;i>=1;i--)
	{
		if(s[i]=='L')
			ans2[i]=ans2[i+1]+1;
		else if(s[i]=='=')
			ans2[i]=ans2[i+1];
		else
			ans2[i]=1;
		finans[i]=max(ans[i], ans2[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<finans[i]<<" ";
	return 0;
}