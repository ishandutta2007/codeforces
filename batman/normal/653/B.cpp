#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (50)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e15)

ll n,q,ans;
map <string,bool> mp;
string s[N];
char c[N];

void build(ll x,string p="")
{
	if(x==0)
	{
		if(mp[p]==1)
		{
			//cout<<p<<"\n";
			string ex="";
			for(int i=0;i<q;i++)
				if(p[0]==c[i])
				{
					ex=s[i];
					for(int j=1;j<p.size();j++)ex+=p[j];
					//cout<<ex<<"\n";
					mp[ex]=1;
				}
		}
		return ;
	}
	for(int i=0;i<6;i++)
		build(x-1,p+(char)(i+'a'));
}

void build2(ll x,string p="")
{
	if(x==0)
	{
		if(mp[p]==1)
			ans++;
		return ;
	}
	for(int i=0;i<6;i++)
		build2(x-1,p+(char)(i+'a'));
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<q;i++)
		cin>>s[i]>>c[i];
	mp["a"]=1;
	for(int i=1;i<=n;i++)
		build(i);
	build2(n);
	cout<<ans;
	return 0;
}