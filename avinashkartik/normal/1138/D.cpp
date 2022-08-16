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

ll test=1;
string s,t;

vll computeLPS(string pat, int M){
    int len = 0;
    vll lps(M,0);
    int i = 1; 
    while (i < M){ 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else{ 
            if(len != 0)
                len = lps[len - 1];
            else{ 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
    return lps;
} 

void solve(){
    cin>>s>>t;
    int z = 0, o = 0, zt = 0, ot = 0, ol = 0, zl = 0;
    int n = s.size(), m = t.size();
    for(int i = 0; i < n; i++) if(s[i] == '1') o++; else z++;
    for(int i = 0; i < m; i++) if(t[i] == '1') ot++; else zt++;
    vll lps = computeLPS(t,m);
    if(zt > z or ot > o){
        deb1(s);
        return;
    }
    string ans = t, last = "";
    z -= zt;
    o -= ot;
    for(int i = lps[m-1]; i < m; i++) last += t[i];
    m = last.size();
    for(int i = 0; i < m; i++) if(last[i] == '1') ol++; else zl++;
    while(z >= zl and o >= ol){
        ans += last;
        z -= zl;
        o -= ol;
    }
    while(o > 0) ans += '1', o--;
    while(z > 0) ans += '0', z--;
    deb1(ans)
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