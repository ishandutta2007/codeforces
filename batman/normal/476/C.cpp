//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ll a,b,ans;
int Sa1378
{ 
    cin>>a>>b;
    const ll m=((b*(b-1))/2ll)%MOD;
    for(int i=1;i<=a;i++)
    {
        ans+=((i%MOD)*(b%MOD)+1ll)%MOD*(m);
        ans%=MOD;
    }   
    
    cout<<ans%(MOD);
    return 0;
}