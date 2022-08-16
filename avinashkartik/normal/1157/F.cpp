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
 
const ll   N     =  1e6+8;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, a[N], ct[N];

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i], ct[a[i]]++;
    int mx = 0, st = -1, en = -1;
    for(int i = 0; i < 2e5+2; i++){
        int cnt = 0, s = i;
        if(ct[i] >= 1) cnt += ct[i++];
        while(ct[i] >= 2) cnt += ct[i++];
        cnt += ct[i];
        if(cnt > mx){
            mx = cnt;
            st = s;
            en = i;
        }
        if(s != i) i--;
    }
    vll ans;
    for(int i = st; i <= en; i++){
        if(ct[i]) ans.pb(i), ct[i]--;
    }
    for(int i = en; i >= st; i--){
        while(ct[i] > 0) ans.pb(i), ct[i]--;
    }
    deb1(ans.size())
    debv(ans)
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