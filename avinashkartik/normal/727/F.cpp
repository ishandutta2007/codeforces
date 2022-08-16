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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, x, a[N], res[N];
vpll Q;

int ch(ll mid){
    multiset <ll> s;
    ll p = mid, ct = 0;
    for(int i = 0; i < n; i++){
        p += a[i];
        s.insert(a[i]);
        if(p < 0){
            p -= *s.begin();
            s.erase(s.begin());
            ct++;
        }
    }
    return ct;
}

ll bs(int x){
    ll l = 0, r = m-1, ans = INF;
    while(l <= r){
        ll mid = (l+r)/2;
        //deb2(mid,ch(mid))
        if(ch(Q[mid].f) <= x){
            r = mid - 1;
            ans = Q[mid].f;
        }
        else l = mid + 1;
    }
    return ans;
}

void solve(){
    cin>>n>>m;
    vll q(n+1,0);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++){
        ll x;
        cin>>x;
        Q.pb({x,i});
    }
    sort(Q.begin(), Q.end());
    for(int i = 0; i <= n; i++) q[i] = bs(i);
    for(int i = 0; i < m; i++){
        int j = 0;
        for(; j < n; j++){
            if(q[j] <= Q[i].f) break;
        }
        res[Q[i].s] = j;
    }
    for(int i = 0; i < m; i++) cout<<res[i]<<endl;
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