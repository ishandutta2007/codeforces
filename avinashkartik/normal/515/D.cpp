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
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2005;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m;
string s[N];
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};

int deg(int i, int j){
    int ct = 0;
    if(s[i+1][j] == '.') ct++;
    if(s[i-1][j] == '.') ct++;
    if(s[i][j+1] == '.') ct++;
    if(s[i][j-1] == '.') ct++;
    return ct;
}

void dfs(int i, int j){
    if(deg(i,j) == 1){
        int dx = i, dy = j;
        if(s[i+1][j] == '.') s[i][j] = '^', s[i+1][j] = 'v', dx++;
        if(s[i-1][j] == '.') s[i][j] = 'v', s[i-1][j] = '^', dx--;
        if(s[i][j+1] == '.') s[i][j] = '<', s[i][j+1] = '>', dy++;
        if(s[i][j-1] == '.') s[i][j] = '>', s[i][j-1] = '<', dy--;
        for(int i = 0; i < 4; i++){
            int x = i+X[i], y = j+Y[i];
            if(s[x][y] == '.') dfs(x,y);
        }
        for(int i = 0; i < 4; i++){
            int x = dx+X[i], y = dy+Y[i];
            if(s[x][y] == '.') dfs(x,y);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        string x;
        cin>>x;
        s[i] = '*'+x+'*';
    }
    s[0] = s[n+1] = string(m+2,'*');
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i][j] == '.') dfs(i,j);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '.'){
                cout<<"Not unique"<<endl;
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<s[i][j];
        }
        cout<<endl;
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