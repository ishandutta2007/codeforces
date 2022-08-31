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

int test = 1, m, k, CT[26], b[100];
string s;

void solve(){
    mset(CT,0);
    cin>>s>>m;
    for(int i = 0; i < m; i++) cin>>b[i];
    int n = s.size();
    for(int i = 0; i < n; i++) CT[s[i]-'a']++;
    int mx = 25, cnt = 0;
    string t = string(m,'.');
    while(cnt < m){
        int ct = 0;
        vll v;
        for(int i = 0; i < m; i++){
            if(b[i] == 0) ct++, v.pb(i);
        }
        int ind = mx;
        for(int j = mx; j >= 0; j--){
            if(CT[j] >= ct){
                ind = j;
                mx = j-1;
                break;
            }
        }
        for(int i = 0; i <= m; i++){
            if(b[i] == 0){
                b[i] = -1;
                t[i] = ind+'a';
            }
            if(b[i] != -1){
                for(auto it : v) b[i] -= abs(i-it);
            }
        }
        cnt += ct;

    }
    cout<<t<<endl;
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