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

#define md (ll)(998244353ll)
#define ar (int)(5000+10)

int dp[ar][ar];
int pref[ar][ar];
int cnt[arr];

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

int inver[ar];
int cnt_and_bigger[ar];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<ar;i++){
        inver[i]=inv(i);
    }

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    for (int i=n;i>=1;i--){
        cnt_and_bigger[i]=cnt_and_bigger[i+1]+cnt[i];
    }
    for (int i=1;i<=n;i++){
        dp[i][1]=cnt[i]*inver[n]%md;
        pref[i][1]=(pref[i-1][1]+dp[i][1])%md;
    }
    for (int j=2;j<=n;j++){
        for (int i=1;i<=n;i++){
            if (cnt_and_bigger[i]<=n-j+1){
                dp[i][j]=cnt[i]*inver[n-j+1]%md*pref[i-1][j-1]%md;
            }
            pref[i][j]=(pref[i-1][j]+dp[i][j]);
            if (pref[i][j]>=md){
                pref[i][j]-=md;
            }
        }
    }
    int ans=0;
    for (int i=1;i<n;i++){
        for (int j=1;j<=n;j++){
            ans+=dp[j][i]*(cnt[j]-1)%md*inver[n-i]%md;
            ans%=md;
        }
    }
    cout<<ans<<"\n";
}