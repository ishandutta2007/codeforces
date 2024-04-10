//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (100*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll a[N],b[N];
int Sa1378
{
    IB
    ll n;
    cin>>n;
    for (ll i=0;i<(1<<n+1)-2;i++)
        cin>>a[i+2];
    ll ans=0;
    for (ll i=n;i>0;i--)
    {
        ll start=(1<<i),end=(1<<i+1)-1;
        for (ll j=start;j<end;j+=2)
        {
            if (a[j]+b[j]>a[j+1]+b[j+1])
                ans+=a[j]+b[j]-b[j+1]-a[j+1],a[j+1]=a[j]+b[j]-b[j+1];
            else
                ans+=a[j+1]+b[j+1]-b[j]-a[j],a[j]=a[j+1]+b[j+1]-b[j];
            b[j/2]=a[j]+b[j];
        }
    }
    cout<<ans;
    return 0;
}