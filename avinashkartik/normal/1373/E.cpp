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
 
const ll   N     =  1e6+5;
const ll   MAXN  =  1e7+1;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k;
ll dig[19] = {0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};

ll val(int x, int f){
    deque <ll> v;
    while(x > 16){
        v.pb(9);
        x -= 9;
    }
    if(f == 1){
        if(x > 8) v.push_front(x-8), v.pb(8);
        else v.pb(x);
    }
    else{
        if(x > 9) v.push_front(x-9), v.pb(9);
        else v.pb(x);
    }
    ll res = 0;
    if(f == 0) sort(v.begin(), v.end());
    for(auto it : v) res = res*10+it;
    return res;
}

void solve(){
    ll ans = INF;
    cin>>n>>k;
    for(int i = 0; i <= 10; i++){
        int y = 0, f = 0;
        for(int j = i; j <= i+k; j++){
            y += dig[j];
            if(j >= 10) f = 1;
        }
        if(y > n) continue;
        if((n-y)%(k+1) == 0){
            ll res = val((n-y)/(k+1),f)*10 + i;
            ans = min(ans,res);
        }
    }
    for(int m = 1; m < 18; m++){
        if(m*9 > n) break;
        for(int i = 0; i <= 10; i++){
            int y = 0, x = 0;
            for(int j = i; j <= i+k; j++){
                y += dig[j];
                if(j < 10) x++;
            }
            if(n-x*m*9 != y) continue;
            ans = min(ans,(ll)(pow(10,m)-1)*10 + i);
        }
    }
    if(ans == INF) ans = -1;
    deb1(ans)
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