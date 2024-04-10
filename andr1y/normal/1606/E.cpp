//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 505;
const ll M = 998244353;

ll dp[N][N];

ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (a*bpm(a*a, b>>1))%M;
    else return bpm(a*a, b>>1);
}

ll f[N], of[N];

ll c(ll n, ll k){
    return f[n]*of[k]%M*of[n-k]%M;
}

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    f[0]=1;
    for(ll i = 1;i<N;i++) f[i]=i*f[i-1]%M;
    of[N-1]=bpm(f[N-1], M-2);
    for(ll i = N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M;
    assert(f[0]*of[0]%M==1);
    ll n, x;
    cin >> n >> x;
    for(ll i = 1;i<=x;i++){
        dp[2][i]=i;
        dp[0][i]=1;
    }
    for(ll ti=3;ti<=n;ti++){
        for(ll j = 1;j<ti;j++){
            dp[ti][j]=bpm(j, ti);
        }
        for(ll maxval=ti;maxval<=x;maxval++){
            // fi - count of >=n
            for(ll fi=0;fi<=ti;fi++){
                if(fi==1) continue;
                dp[ti][maxval]+=c(ti, fi)*(bpm(ti-1, ti-fi)*dp[fi][maxval-ti+1]%M)%M;
                if(dp[ti][maxval]>=M) dp[ti][maxval]-=M;
            }
        }
    }
    ll res=dp[n][x];
    cout<<res;
}