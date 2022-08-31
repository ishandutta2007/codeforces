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
 
const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, a[N][N], r[N][N], c[N][N], R[N], C[N];

void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        vpll b;
        for(int j = 0; j < m; j++)
            b.pb({a[i][j],j});
        sort(b.begin(), b.end());
        int ct = 0;
        for(int j = 0; j < m; j++){
            if(ct == 0 or b[j].f > b[j-1].f) ct += 1;
            r[i][b[j].s] = ct;
        }
        R[i] = ct;
    }
    for(int i = 0; i < m; i++){
        vpll b;
        for(int j = 0; j < n; j++)
            b.pb({a[j][i],j});
        sort(b.begin(), b.end());
        int ct = 0;
        for(int j = 0; j < n; j++){
            if(ct == 0 or b[j].f > b[j-1].f) ct += 1;
            c[b[j].s][i] = ct;
        }
        C[i] = ct;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll maxx = max(r[i][j],c[i][j]);
            ll x = max(R[i]-r[i][j]+maxx,C[j]-c[i][j]+maxx);
            cout<<x<<" ";
        }
        cout<<endl;
    }
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