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
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
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

ll test=1,n,m,q,t[N][N],vis[N][N];
string s[N];

char conv(char x){
    if(x == '0') return '1';
    else return '0';
}

void bfs(){
    queue <pll> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1][j] == s[i][j]) t[i-1][j] = 1, q.push({i-1,j});
            if(s[i+1][j] == s[i][j]) t[i+1][j] = 1, q.push({i+1,j});
            if(s[i][j-1] == s[i][j]) t[i][j-1] = 1, q.push({i,j-1});
            if(s[i][j+1] == s[i][j]) t[i][j+1] = 1, q.push({i,j+1});
        }
    }
    while(q.size()){
        pll p = q.front();
        q.pop();
        int i = p.f, j = p.s;
        if(vis[i][j] == 1) continue;
        vis[i][j] = 1;
        s[i][j] = conv(s[i][j]);
        if(s[i-1][j] == s[i][j] and t[i-1][j] == -1) t[i-1][j] = t[i][j]+1, q.push({i-1,j});
        if(s[i+1][j] == s[i][j] and t[i+1][j] == -1) t[i+1][j] = t[i][j]+1, q.push({i+1,j});
        if(s[i][j-1] == s[i][j] and t[i][j-1] == -1) t[i][j-1] = t[i][j]+1, q.push({i,j-1});
        if(s[i][j+1] == s[i][j] and t[i][j+1] == -1) t[i][j+1] = t[i][j]+1, q.push({i,j+1});
    }
}

void solve(){
    cin>>n>>m>>q;
    int l = n+1,r = 0,f = 0;
    for(int i = 1; i <= n; i++) cin>>s[i], s[i] = '.'+s[i]+'.';
    s[0] = s[n+1] = string(m+2,'.');
    mset(t,-1);
    bfs();
    while(q--){
        ll i,j,p;
        cin>>i>>j>>p;
        if(t[i][j] == -1) deb1(s[i][j])
        else if(t[i][j] <= p and t[i][j]%2 == p%2) deb1(s[i][j])
        else deb1(conv(s[i][j]))
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