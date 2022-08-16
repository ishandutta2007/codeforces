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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   M     =  55;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, m, a[M][M], b[M][M], res[M][M] = {};

void mula(){
    ll c[M][M] = {};
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < m; k++)
                c[i][j] = (c[i][j] + a[i][k]*a[k][j])%mod;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = c[i][j];
}

void mulres(){
    ll c[M][M] = {};
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < m; k++)
                c[i][j] = (c[i][j] + res[i][k]*a[k][j])%mod;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            res[i][j] = c[i][j];
}

int getind(char x){
    if(x >= 'A' && x <= 'Z') return x-'A'+26;
    else return x-'a';
}

void fastmod(ll y){
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            if(i == j) res[i][j] = 1;
    while(y){
        if(y&1) mulres();
        mula();
        y /= 2;
    }
}

void solve(){
    cin>>n>>m>>k;
    if(n == 1){
        deb1(m);
        return;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == j) b[i][j] = 1;
            a[i][j] = 1;
        }
    }
    while(k--){
        string x;
        cin>>x;
        int ind1 = getind(x[0]);
        int ind2 = getind(x[1]);
        a[ind1][ind2] = 0;
    }
    fastmod(n-1);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            ans += res[i][j];
            ans %= mod;
        }
    }
    deb1(ans) 
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
        string txt;
        cin>>txt;
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}