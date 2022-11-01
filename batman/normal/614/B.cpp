#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll n,ans;
string res;
bool mark;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s="";
		cin>>s;
		ll num=0,ex=0;
		if((ll)s.size()==1 && s[0]=='0')return cout<<0,0;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]!='0')
			{
				if(s[j]=='1')num++;
				else ex++;
			}
		}
		if(ex || num>1){mark=1;res=s;continue;}
		ans+=(ll)s.size()-1;
	}
	if(mark)cout<<res;
	else cout<<1;
	for(int i=0;i<ans;i++)cout<<0;
    return 0;
}