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

#define md (int)(998244353)

int sum(int a,int b)
{
    a+=b;
    a%=md;
    if (a<0){
        a+=md;
    }
    return a;
}

void add(int& a,int b)
{
    a=sum(a,b);
}

int mult(int a,int b)
{
    return a*b%md;
}

int dp[501][501];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        dp[i][i]=1;
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=i;j++){
            if (dp[i][j]){
                for (int l=i+1;l<=n;l++){
                    add(dp[l][max(j,l-i)],dp[i][j]);
                }
            }
        }
    }
    int ans=0;
    for (int a=1;a<=n;a++){
        for (int b=1;b<=n;b++){
            if (a*b<k){
                add(ans,mult(dp[n][a],dp[n][b]));
            }
        }
    }
    cout<<sum(ans,ans)<<"\n";
}