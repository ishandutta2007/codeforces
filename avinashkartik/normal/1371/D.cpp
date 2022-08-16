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
 
const ll   N     =  305;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, k, a[N][N], R[N], C[N];

void solve(){
    cin>>n>>k;
    if(k){
        for(int i = 0; i < n; i++){
            ll x = k/n;
            if(i < k%n) x++;
            for(int j = i; j < i+x; j++){
                a[i][j%n] = 1;
            }
        }
    }
    int mxr = 0, mnr = n, mxc = 0, mnc = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            R[i] += a[i][j];
            C[j] += a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        mxr = max(mxr,R[i]);
        mnr = min(mnr,R[i]);
        mxc = max(mxc,C[i]);
        mnc = min(mnc,C[i]);
    }
    deb1((mxr-mnr)*(mxr-mnr)+(mxc-mnc)*(mxc-mnc))
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j];
            a[i][j] = 0;
        }
        cout<<endl;
        R[i] = 0;
        C[i] = 0;
    }
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}