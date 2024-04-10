#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n;
int a[N], b[N], p[N];
string s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];	
	cin>>s;
	s="*"+s;
	int finans=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B')
			finans+=p[i];
	}
	int sum=finans;
	ans=finans;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='A')
			ans+=p[i];
		else
			ans-=p[i];
		finans=max(finans, ans);
	}
	ans=sum;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='A')
			ans+=p[i];
		else
			ans-=p[i];
		finans=max(finans, ans);
	}
	cout<<finans;
	return 0;
}