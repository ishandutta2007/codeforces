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
ll n, m;
ll xr[N], yr[N], xb[N], yb[N];
vector<pair<pll,pll>> seg;
/***************************************** FUNCTION IMPLEMENTATIONS **************************************/
bool onSegment(pll p, pll q, pll r) 
{ 
    if (q.f <= max(p.f, r.f) && q.f >= min(p.f, r.f) && 
        q.s <= max(p.s, r.s) && q.s >= min(p.s, r.s)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(pll p, pll q, pll r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-plls/ 
    // for details of below formula. 
    int val = (q.s - p.s) * (r.f - q.f) - 
              (q.f - p.f) * (r.s - q.s); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(pll p1, pll q1, pll p2, pll q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

ll chk(){
    if(seg.size()<2) return 0;
    pair<pll,pll> a = seg.back();
    ll n  = seg.size()-2;
    for(int i=0; i<=n; i++){
        pair<pll,pll> b = seg[i];
        ll ret = doIntersect(a.f,a.s,b.f,b.s);
        if(ret==1){
            return 1;
        }
    }
    return 0;
}

ll solve(ll i, ll mask){
    if(chk()==1)
        return 0;
    if(i>n)
        return 1;

    ll ans = 0;
    for(int j=1; j<=m; j++){
        ll p2 = (1LL<<j);
        if(mask&p2) continue;
        // make connection between i and j
        seg.pb({{xr[i],yr[i]},{xb[j],yb[j]}});
        ans |= solve(i+1, mask|p2);
        seg.pop_back();
    }

    return ans;
}

/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN(ll tc){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>xr[i]>>yr[i];
    }
    for(int i=1; i<=m; i++){
        cin>>xb[i]>>yb[i];
    }

    if(n!=m){
        cout<<"No";
        return;
    }

    solve(1,0)?cout<<"Yes":cout<<"No";
}

int main(){
    SPEED;

    //cin>>test_cases;
    foo(i,1,test_cases){
        MAIN(i);
    }
}