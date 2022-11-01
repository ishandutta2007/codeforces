//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.2 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1111)
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
ll n,m,k,ans,a[N];
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++)
        cin>>a[i];
        
    for(int i=0;i<m;i++)
    {
        ll tmp=a[i]^a[m],tmp2=0;
        while(tmp)
        {
            tmp2+=(tmp%2);
            tmp/=2;
        }
        if(tmp2<=k)
            ans++;
    }
    cout<<ans;
    return 0;
}