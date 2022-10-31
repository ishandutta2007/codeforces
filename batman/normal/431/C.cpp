//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (2200)
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
ifstream fin("input.txt");
ll n,k,d,dp_0[110],dp_1[110];
int Sa1378
{ 
    IB
    cin>>n>>k>>d;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=min(k,i-1);j++)
            dp_0[i]+=dp_0[i-j]%MOD;
        if(i<=k)    
            dp_0[i]++;  
        if(i>=d)
        {
            for(ll j=1;j<d;j++)
                dp_1[i]+=dp_1[i-j]%MOD;
            for(ll j=d;j<=min(k,i-1);j++)
                dp_1[i]+=dp_0[i-j]%MOD; 
            if(i<=k)
                dp_1[i]++;  
        }
        dp_0[i]%=MOD;
        dp_1[i]%=MOD;
    }   
    cout<<dp_1[n];
    return 0;
}