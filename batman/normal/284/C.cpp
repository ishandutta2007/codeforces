//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (301*1000)
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
ll n,sum,p=1,dp[N];

int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll a,x;
            cin>>a>>x;
            dp[a-1]-=x;
            sum+=a*x;
        }
        else if(t==2)
        {
            ll k;
            cin>>k;
            dp[p]-=k;
            dp[p-1]+=k;
            p++;
            sum+=k;
        }
        else
        {
            sum+=dp[p-1];
            dp[p-2]+=dp[p-1];
            dp[p-1]=0;
            p--;
            
        }
        double ans=(double)sum/(double)p;
        
        printf("%6f \n",ans);
    }
    return 0;
}