//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
 
#define arr (int)(1e6+10)
 
int d[ar][ar];
int last[arr];
int p[arr];
int dp[arr];
int from[arr];
 
main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
 
    fast;
 
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin>>c;
            if (c=='1'){
                d[i][j]=1;
            }
            else{
                d[i][j]=1e9;
            }
        }
        d[i][i]=0;
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>p[i];
    }
    for (int i=1;i<=n;i++){
        last[i]=-1;
    }
    dp[0]=1;
    from[0]=-1;
    last[p[0]]=0;
    for (int i=1;i<m;i++){
        dp[i]=1e9;
        from[i]=-1;
        for (int ll=1;ll<=n;ll++){
            if (ll!=p[i]){
                if (last[ll]!=-1){
//                    cout<<i<<" "<<ll<<" "<<p[i]<<" "<<d[ll][p[i]]<<"\n";
                    if (i-last[ll]==d[ll][p[i]]){
                        if (dp[i]>dp[last[ll]]+1){
                            dp[i]=dp[last[ll]]+1;
                            from[i]=last[ll];
                        }
                    }
                }
            }
        }
        last[p[i]]=i;
    }
    vi ans(0);
    int cur=m-1;
    while (cur!=-1){
        ans.pb(p[cur]);
        cur=from[cur];
    }
    reverse(all(ans));
 
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}