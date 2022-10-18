#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

#define ar (int)(5e3+10)

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

int dp[ar][ar];

void add(int& a,int b)
{
    a+=b;
    if (a>md){
        a-=md;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;

    dp[0][0]=1;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=min(n,k);j++){
            add(dp[i][j],dp[i-1][j-1]*(n-j+1)%md); /// now unical
            add(dp[i][j],dp[i-1][j]*(j)%md); /// now not unical
        }
    }

    int ans=0;
    for (int i=1;i<=min(n,k);i++){
        int cur=dp[k][i]*bpow(2,n-i)%md;
        add(ans,cur);
    }
    cout<<ans<<"\n";
}