/***************************************** START OF TEMPLATE *********************************************/
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define  SPEED           ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT      mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)      for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)      for(ll i = (a); i >= n; i--)
#define  fo(i,n)         for(ll i = 0; i < n; i++)
#define  newl            cout<<"\n";
#define  f               first
#define  s               second
#define  pb              push_back
#define  mp              make_pair
#define  sym(s)          s="#"+s+"#";
#define  sqr(v)          v*v;
#define  all(x)          (x).begin(),(x).end()
#define  alll(x,n)       x+1, x+n+1
#define  uniq(a)         a.resize(unique(a.begin(), a.end()) - a.begin());
#define  mset(x,val)     memset(x,val,sizeof(x))
#define  mset1d(a,n,v)   foo(i,0,n+5)a[i]=v;
#define  mset2d(a,n,m,v) foo(i,0,n+5)foo(j,0,m+5)a[i][j]=v;
#define  deb1(a)         cout<<a<<"\n";
#define  deb2(a,b)       cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)     cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  debp(a)         cout<<a.f<<" "<<a.s<<"\n";
#define  debv(a)         for(auto it: a)cout<<it<<" ";newl;
#define  debm(a)         for(auto it: a)cout<<"{"<<it.f<<","<<it.s<<"}, ";newl;
#define  deb1d(a,n)      foo(i,1,n)cout<<a[i]<<" ";newl;
#define  deb2d(a,n,m)    foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}    

template <typename T> 
using  ordered_set =  tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
using  ll          =  long long;
using  ull         =  unsigned long long;
using  ld          =  long double;
using  pll         =  pair<ll,ll>;
using  vll         =  vector<ll>;
using  vpll        =  vector<pll>;

const ld   PI    =  3.14159265358979323846; 
const ll   MOD   =  1e+9+7;
const ll   INF   =  LLONG_MAX;
const int  INFi  =  INT_MAX;
const ll   N     =  2e+5+8;

vll adj[N]; ll vis[N];
ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

ll test_cases = 1; randomINIT;

/*********************************************************************************************************/
/***************************************** VARIABLE DECLARATIONS *****************************************/
ll n;
string s;
map<ld,ll> cnt;
vector<pair<ll,pll>> v;
/***************************************** FUNCTION IMPLEMENTATIONS **************************************/


/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN(ll tc){
    cin>>n;
    for(int i=1; i<=n; i++){
        string a, b, c;
        cin>>s;
        sym(s);
        int j=2;
        for(;s[j]!='+'; j++){
            a += s[j];
        }
        int k = j+1;
        for(;s[k]!=')'; k++){
            b += s[k];
        }
        int l = k+2;
        for(;l<=s.size()-2; l++){
            c += s[l];
        }
        //deb3(a,b,c);
        ll a1 = stoll(a), b1 = stoll(b), c1 = stoll(c);
        ld p = (ld)(a1+b1)/c1;
        cnt[p]++;
        v.pb({a1,{b1,c1}});
    }

    for(auto it: v){
        ll a = it.f, b = it.s.f, c = it.s.s;
        ld p = (ld)(a+b)/c;
        cout<<cnt[p]<<" ";
    }

}

int main(){
    SPEED;

    //cin>>test_cases;
    foo(i,1,test_cases){
        MAIN(i);
    }
}