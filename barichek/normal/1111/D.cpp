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

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

inline void add(int& a,const int& b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

#define arr (int)(1e5+10)

int a[arr];
int cnt[arr];
const int S=52;

int dp1[S+2][arr/2];

int dp2[2][S+2][arr/2];

int f[arr];
int rf[arr];

int ans[ar][ar];
int res[ar][ar];
int lol[S+1][arr/2];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=1ll*f[i-1]*i%md;
    }
    rf[arr-1]=inv(f[arr-1]);
    for (int i=arr-2;i>=0;i--){
        rf[i]=1ll*rf[i+1]*(i+1)%md;
    }

    string s;
    cin>>s;
    int n;
    n=len(s);
    for (int i=0;i<n;i++){
        if (s[i]>='a'&&s[i]<='z'){
            a[i]=s[i]-'a'+1;
        }
        else{
            a[i]='z'-'a'+1+s[i]-'A'+1;
        }
    }
    for (int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    dp1[0][0]=1;
    for (int i=0;i<S;i++){
        for (int sum=0;sum<=n/2;sum++){
//            cout<<"dp1["<<i<<"]["<<sum<<"] :: "<<dp1[i][sum]<<"\n";
            int val=1ll*dp1[i][sum]*rf[cnt[i+1]]%md;
            /// if not take
            add(dp1[i+1][sum],val);
            /// if take
            if (cnt[i+1]!=0&&sum+cnt[i+1]<=n/2){
                add(dp1[i+1][sum+cnt[i+1]],val);
            }
        }
    }
    for (int i=1;i<=S;i++){
        for (int j=0;j<=n/2;j++){
            lol[i][j]=1ll*dp1[i-2][j]*rf[cnt[i-1]]%md;
        }
    }
    int ans_all=1ll*dp1[S][n/2]*f[n/2]%md*f[n/2]%md;
//    cout<<ans_all<<" !!\n";
    for (int i=1;i<=S;i++){
        dp2[0][i][0]=1;
    }
    int cur=0;
    for (int i=S;i>=2;i--){
        for (int j=1;j<=S;j++){
            for (int sum=0;sum<=n/2;sum++){
                dp2[cur^1][j][sum]=0;
            }
        }
        for (int j=1;j<=S;j++){
            for (int sum=0;sum<=n/2;sum++){
                int val=1ll*dp2[cur][j][sum]*rf[cnt[i]]%md;
                /// if not take
                add(dp2[cur^1][j][sum],val);
                /// if take
                if (i!=j&&cnt[i]!=0&&sum+cnt[i]<=n/2){
                    add(dp2[cur^1][j][sum+cnt[i]],val);
                }
            }
        }
        /// dp2[cur^!][...][...] now is real value
        for (int j=i;j<=S;j++){
            for (int sum=0;sum+cnt[i-1]<=n/2;sum++){
//                if (dp1[i-2][sum]*rf[cnt[i-1]]%md*dp2[1][j][n/2-sum-cnt[i-1]]%md){
//                    if (i-1==1&&j==3){
//                        cout<<sum<<" "<<dp1[i-2][sum]<<" "<<dp2[1][j][n/2-sum-cnt[i-1]]<<"\n";
//                    }
//                }
                int val=1ll*lol[i][sum]*dp2[cur^1][j][n/2-sum-cnt[i-1]]%md;
                add(ans[i-1][j],val);
            }
        }
        /// push dp2[cur^1] to dp2[cur]
        for (int j=1;j<=S;j++){
            for (int sum=0;sum<=n/2;sum++){
                dp2[cur][j][sum]=dp2[cur^1][j][sum];
            }
        }
        cur^=1;
    }
    for (int i=1;i<=S;i++){
        for (int j=i;j<=S;j++){
//            cout<<"ans["<<i<<"]["<<j<<"] :: "<<ans[i][j]<<"\n";
            if (i==j){
                res[i][j]=ans_all;
            }
            else{
                res[i][j]=((ans_all-2ll*ans[i][j]%md*f[n/2]%md*f[n/2]%md)%md+md)%md;
            }
        }
    }
    int q;
    cin>>q;
    while (q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        x=a[x];
        y=a[y];
        if (x>y){
            swap(x,y);
        }
        cout<<res[x][y]<<"\n";
    }
}