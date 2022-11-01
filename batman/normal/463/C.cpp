/*
ID: sa.13781
PROG: subset
LANG: C++
*/
//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.1 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (4400)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] > a[y]; }
ifstream fin("subset.in");
ofstream fout("subset.out");
ll n,a[N][N],d[2][N],ans[2]={-1,-1};
pair <ll,ll> p[2];
int main()
{
    IB
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j],d[0][i+j]+=a[i][j],d[1][i+n-j]+=a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(d[0][i+j]+d[1][i+n-j]-a[i][j]>ans[(i+j) & 1])
            {
                ans[(i+j) & 1]=d[0][i+j]+d[1][i+n-j]-a[i][j];
                p[(i+j) & 1].first=i+1;
                p[(i+j) & 1].second=j+1;
            }
    cout<<ans[0]+ans[1]<<endl;
    sort(p,p+2);
    cout<<p[0].first<<" "<<p[0].second<<" "<<p[1].first<<" "<<p[1].second;
    return 0;
}