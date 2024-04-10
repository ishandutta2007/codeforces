#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll t1,t2,s;

pair<ll,ll> calc(ll p,ll x1,ll d)
{
	ll first;
	if((x1>=p && d==1) || (x1<=p && d==-1))first=abs(x1-p)*t1;
    else
    {
    	if(d==-1)first=p*t1+x1*t1,d=1;
    	else first=(s-p)*t1+(s-x1)*t1,d=-1;
	}
	return {first,d};
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll x1,x2,p,d;
    cin>>s>>x1>>x2;
    cin>>t1>>t2;
    cin>>p>>d;
    ll ans=abs(x1-x2)*t2;
    ll first=calc(p,x1,d).first;
    d=calc(p,x1,d).second;
	ll second=calc(x1,x2,d).first;
	cout<<min(ans,first+second);
    return 0;
}