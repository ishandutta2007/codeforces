//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (500*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(ll x,ll y){ return a[x] > a[y]; }
 
ll a,b,ans;
int Sa1378
{   
    IB
    cin>>a>>b;
    while(b!=0)
    {
        ans+=(a/b);
        a=a%b;
        
        if(b>a)
            swap(a,b);
    }         
    cout<<ans;  
    return 0;
}