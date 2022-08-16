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
 
const ll   N     =  55;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

int test=1,sum,lim,m=0,tot=0;
set <ll> s[20];
vll ans;

void solve(){
    cin>>sum>>lim;
    for(int i = 1; i <= lim; i++){
        for(int j = 0; j < 20; j++){
            int x = (1<<j);
            if(x&i){
                tot += x;
                m = max(m,j);
                s[j].insert(i);
                break;
            }
        }
    }
    if(tot < sum){
        deb1(-1)
        return;
    }
    while(sum){
        if(s[m].size() == 0) m--;
        for(int i = m; i >= 0; i--){
            int x = (1<<i);
            if(sum >= x){
                sum -= x;
                auto it = s[i].begin();
                ans.pb(*it);
                s[i].erase(*it);
                break;
            }
        }
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