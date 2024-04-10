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
///#define int long long

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

#define md (ll)(998244353ll)

#define ar (int)(500+10)

int a[ar];
int dp[ar][ar];

int get_dp(int l,int r)
{
    if (l>r){
        return 1;
    }
    if (l==r){
        return 1;
    }
    if (dp[l][r]!=-1){
        return dp[l][r];
    }
    dp[l][r]=0;
    int pos=min_element(a+l,a+r+1)-a;
    int sum1=0;
    int sum2=0;
    for (int k=l;k<=pos;k++){
        sum1+=1ll*get_dp(l,k-1)*get_dp(k,pos-1)%md;
        if (sum1>=md){
            sum1-=md;
        }
    }
    for (int p=pos;p<=r;p++){
        sum2+=1ll*get_dp(pos+1,p)*get_dp(p+1,r)%md;
        if (sum2>=md){
            sum2-=md;
        }
    }
    dp[l][r]=1ll*sum1*sum2%md;
    return dp[l][r];
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<ar;i++){
        for (int j=i;j<ar;j++){
            dp[i][j]=-1;
        }
    }

    int n;
    cin>>n>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<get_dp(1,n)<<"\n";
}