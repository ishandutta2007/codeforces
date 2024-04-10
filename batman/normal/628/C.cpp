#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (301*1000)

string s;
ll n,p;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>p>>s;
	for(int i=0;i<s.size() && p;i++)
	{
		ll now=s[i]-'a';
		if(now>25-now)
		{
			if(now<=p)s[i]='a',p-=now;
			else s[i]-=p,p=0;
		}
		else
		{
			if(25-now<=p)s[i]='z',p-=25-now;
			else s[i]+=p,p=0;
		}
	}
	if(p!=0)return cout<<-1,0;
	cout<<s;
	return 0;
}