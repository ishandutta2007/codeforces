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

ll test=1, n, k, ct[N];
string s;

void solve(){
    cin>>n>>k;
    cin>>s;
    int tot = 0;
    for(int i = 0; i < n; i++){
        ct[i%k] += s[i]-'0';
        tot += s[i]-'0';
    }
    int ans = tot;
    for(int i = 0; i < k; i++){
        int off = tot-ct[i];
        int on = 0;
        int mx = 0, tmx = 0, st = i, en = -1, fst = -1;
        for(int j = i; j < n; j += k){
            int val = s[j] == '0'? -1:1;
            mx += val;
            if(mx < 0){
                mx = 0;
                st = j+1;
            }
            if(mx > tmx){
                tmx = mx;
                fst = st;
                en = j;
            }
        }
        for(int j = i; j < n; j += k){
            if(j < fst || j > en){
                if(s[j] == '1') off++;
            }
            else{
                if(s[j] == '0') on++;
            }
        }
        ans = min(ans,on+off);
        //deb4(i,ct[i],fst,en)
    }
    deb1(ans);
    for(int i = 0; i < n; i++){
        ct[i] = 0;
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