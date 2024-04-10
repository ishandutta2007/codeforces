#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tofan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m;
char ans[30];
string s;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<26;i++)
		ans[i]=i+'a';
	for(int i=0;i<m;i++)
	{
		char a,b;
		cin>>a>>b;
		for(int j=0;j<26;j++)
		{
			if(ans[j]==a)
				ans[j]=b;
			else if(ans[j]==b)
				ans[j]=a;	
		}
	}
	string xx=s;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[j]==i+'a')
				xx[j]=ans[i];
		}
	}
	cout<<xx;
    return 0;
}