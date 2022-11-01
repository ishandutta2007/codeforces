#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1111)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

char c[3];
ll ans=INF;

void calc(vector <ll> v,ll p)
{
	if(p==3)
	{
		ans=min(ans,v[0]);
		return ;
	}
	for(int i=0;i<v.size();i++)
		for(int j=i+1;j<v.size();j++)
		{
			vector <ll> ex;
			for(int q=0;q<v.size();q++)
				if(q!=i && q!=j)
					ex.push_back(v[q]);
			if(c[p]=='+')ex.push_back(v[i]+v[j]);
			else ex.push_back(v[i]*v[j]);
			calc(ex,p+1);		
		}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector <ll> v;
	for(int i=0;i<4;i++)
	{
		ll a;
		cin>>a;
		v.push_back(a);
	}
	cin>>c[0]>>c[1]>>c[2];
	calc(v,0);
	cout<<ans;
    return 0;
}