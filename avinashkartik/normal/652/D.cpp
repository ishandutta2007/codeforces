#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  GODSPEED         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;
 
const ll   N     =  4e5+5;
const ll   M     =  1e8;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, l[N], r[N], subt[N];
map <ll, ll> add, rem;

ll tree[N] = {};

void update(int idx, int val){ 
    idx++;
    while(idx <= N-2){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 

ll query(int idx){
    idx++;
    ll sum = 0;
    while(idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

void compress(){
    map <ll, ll> ind;
    vll points;
    for(int i = 1; i <= n; i++) points.pb(l[i]), points.pb(r[i]);
    sort(all(points));
    for(int i = 0; i < 2*n; i++) ind[points[i]] = i;
    for(int i = 1; i <= n; i++) l[i] = ind[l[i]], r[i] = ind[r[i]];
}

void solve(){
    vll points, R;
    set <ll> active;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>l[i]>>r[i];
    compress();
    for(int i = 1; i <= n; i++){
        cin>>l[i]>>r[i];
        add[l[i]] = i;
        rem[r[i]] = i;
        points.pb(l[i]); points.pb(r[i]); R.pb(r[i]);
    }
    sort(all(points)); sort(all(R));
    for(auto it : points){
        if(add[it]){
            subt[add[it]] = query(r[add[it]]);
            update(r[add[it]],1);
            active.insert(add[it]);
        }
        else{
            update(r[rem[it]],-1);
            active.erase(rem[it]); 
        }
    }
    for(int i = 1; i <= n; i++){
        ll ans = lower_bound(all(R),r[i]) - lower_bound(all(R),l[i]);
        deb1(ans-subt[i])
    }
}

int main(){
    GODSPEED;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}