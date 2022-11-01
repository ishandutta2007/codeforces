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
#define N (300*1000)
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
int n,m,dp[N],x,ex,ans;
int Sa1378
{ 
    cin>>n>>m;
    ex=n+m;
    for(x=0;(x+1)*x/2<=ex;x++);
    ex=max(n,m);
    x--;
    dp[0]=1;
    for(int i=1;i<=x;i++)
        for(int j=ex;j>=i;j--)
            dp[j]+=dp[j-i],dp[j]%=MOD;
    for(int i=0;i<=n;i++)
        if(i+m>=(x+1)*x/2)
            ans+=dp[i],ans%=MOD;    
    cout<<ans;
            
    
    return 0;
}