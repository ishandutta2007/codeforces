//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (333)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){ll p=1ll;for(ll i=0;i<b;i++)p*=(ll)a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] < a[y]; }
ll h,n,ans;
bool rightside=0;
int Sa1378
{ 
    cin>>h>>n;
    for(ll i=tavan(2ll,h-1);i>=1;i/=2)
    {
        if((n>i && rightside) || (n<=i && !rightside))
        {
            rightside=1-rightside;
            if(!rightside)
                n-=i;
        }
            
        else
        {
            ans+=(i*2ll)-1ll;
            if(!rightside)
                n-=i;
        }
        ans++;  
    }   
    cout<<ans;  
    return 0;
}