#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[16][N], F[16][16], l[16][16], dp[(1<<16)][16][16];

ll mem(ll msk, ll first, ll last){
    if(msk == (1<<n)-1){
        return l[first][last];
    }
    if(first != -1 and dp[msk][first][last] != -1) return dp[msk][first][last];
    ll ans = 0, nf = first, s = INF;
    for(int i = 0; i < n; i++){
        ll x = (1<<i);
        if(last == -1) nf = i;
        else s = F[last][i];
        if((msk&x) == 0){
            ans = max(ans,min(s,mem(msk+x,nf,i)));
        }
    }
    if(first == -1) return ans;
    return dp[msk][first][last] = ans;
}

void solve(){
    mset(dp,-1);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll ct = INF;
            for(int k = 0; k < m; k++){
                ct = min(ct,abs(a[i][k]-a[j][k]));
            }
            F[i][j] = ct;
            ct = INF;
            for(int k = 1; k < m; k++){
                ct = min(ct,abs(a[i][k]-a[j][k-1]));
            }
            l[i][j] = ct;
        }
    }
    deb1(mem(0,-1,-1));
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}