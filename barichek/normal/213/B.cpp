#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

void add(int& a,int b)
{
    a+=b;
    a%=md;
    if (a<0){
        a+=md;
    }
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int dp[10][101];
int n;
int a[10];

int f[arr];
int rf[arr];

int solve()
{
    memset(dp,0,sizeof(dp));
    for (int c0=max(0ll,a[0]);c0<=n-1;c0++){
        dp[0][c0]=rf[c0];
    }
    for (int i=0;i+1<10;i++){
        for (int j=0;j<=n-1;j++){
            for (int k=0;j+k<=n-1;k++){
                if (k>=a[i+1]){
                    add(dp[i+1][j+k],dp[i][j]*rf[k]%md);
                }
            }
        }
    }
    int res=0;
    for (int k=0;k<=n-1;k++){
        add(res,f[k]*dp[9][k]%md);
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }
    rf[arr-1]=inv(f[arr-1]);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }

    cin>>n;
    for (int i=0;i<10;i++){
        cin>>a[i];
    }

    int ans=0;
    for (int first=1;first<=9;first++){
        a[first]--;
        add(ans,solve());
        a[first]++;
    }
    cout<<ans<<"\n";
}