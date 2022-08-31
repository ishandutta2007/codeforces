#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<pll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test=1, n, m, ans = 0;
set <int> s;
string t;

void solve(){
    cin>>n>>m>>t;
    t = '.'+t+'.';
    s.insert(0);
    s.insert(n+1);
    int ct = 0;
    for(int i = 1; i <= n; i++){
        if(t[i] == '.') ct++;
        else{
            ans += max(0,ct-1);
            ct = 0;
            s.insert(i);
        }
    }
    ans += max(0,ct-1);
    int x;
    char c;
    while(m--){
        cin>>x>>c;
        if(c != '.' and s.find(x) != s.end()){ deb1(ans) ;continue; }
        if(c == '.' and s.find(x) == s.end()){ deb1(ans) ;continue; }
        auto lb = s.lower_bound(x); lb--;
        auto rb = s.upper_bound(x);
        if(c != '.'){
            ans -= (max(0,*rb-*lb-2));
            ans += (max(0,x-*lb-2)+max(0,*rb-x-2));
            s.insert(x);
        }
        else{
            ans -= (max(0,x-*lb-2)+max(0,*rb-x-2));
            ans += (max(0,*rb-*lb-2));
            s.erase(x); 
        }
        deb1(ans)
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