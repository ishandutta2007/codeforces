#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll a,b,c,ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>c;
    while(1)
    {
    	if(a<1 || b<2 || c<4)break;
    	a-=1;
    	b-=2;
    	c-=4;
    	ans+=7;
	}
    
    cout<<ans;
    return 0;
}