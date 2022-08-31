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
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  map<pair<pll,pll>,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  55;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m;
string s[N];

bool check(string t){
    for(int i = 0; i < n; i++){
        int ct = 0;
        for(int j = 0; j < m; j++){
            if(t[j] != s[i][j]) ct++;
        }
        if(ct > 1) return 0;
    }
    return 1;
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>s[i];
    int ct = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 26; j++){
            string t = s[0];
            t[i] = 'a'+j;
            if(check(t) == 1){
                deb1(t)
                return;
            }
        }
    }
    deb1(-1);
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