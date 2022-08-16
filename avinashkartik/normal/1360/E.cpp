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
typedef  map<pair<pll,pll>,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  55;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,a[N][N];
string s[N];

bool solve(){
    mset(a,0);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>s[i];
    for(int i = 0; i < n; i++){
        a[i][n-1] = s[i][n-1]-'0';
        a[n-1][i] = s[n-1][i]-'0';
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            a[i][j] = (a[i+1][j]|a[i][j+1])&(s[i][j]-'0');
            if(a[i][j] == 0 && s[i][j] == '1') return 0;
        }
    }
    return 1;
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        if(solve() == 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}