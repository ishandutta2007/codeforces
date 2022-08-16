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
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], ans[N];
vector <pair<string,int>> v[N];

void solve(){
    cin>>n;
    for(int i = 0; i < 2*n-2; i++){
        string x;
        cin>>x;
        v[x.size()].pb({x,i});
    }
    string pre = ""; 
    string suf = "";
    int flag = 0;
    for(int i = 1; i < n; i++){
        if(v[i][0].f == pre+v[i][0].f[i-1] and v[i][1].f == v[i][1].f[0]+suf){
            pre = v[i][0].f;
            suf = v[i][1].f;
            ans[v[i][0].s] = flag;
            ans[v[i][1].s] = flag^1;
        }
        else if(v[i][1].f == pre+v[i][1].f[i-1] and v[i][0].f == v[i][0].f[0]+suf){
            pre = v[i][1].f;
            suf = v[i][0].f;
            ans[v[i][1].s] = flag;
            ans[v[i][0].s] = flag^1;
        }
        else{
            swap(pre,suf);
            i--;
            flag = 1;
        }
    }
    for(int i = 0; i < 2*n-2; i++) (ans[i]^flag)? cout<<"S":cout<<"P";
    cout<<endl;
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