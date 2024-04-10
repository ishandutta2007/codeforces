//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ll x,y,eq,ans,a[3]={2,3,5};
int Sa1378
{ 
    IB
    cin>>x>>y;
    eq=gcd(x,y);
    y/=eq;
    x/=eq;
    for(int i=0;i<3;i++)
    {
        while(!(x%a[i]))
            x/=a[i],ans++;
        while(!(y%a[i]))
            y/=a[i],ans++;  
    }
    if(x!=1 || y!=1)
        cout<<-1;
    else
        cout<<ans;  
    return 0;
}