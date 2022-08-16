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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], k;

ll tree[N] = {};

void update(int idx, int val){ 
    idx++;
    while(idx <= n+1){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 

void build(){ 
    for(int i = 0; i < n; i++) 
        update(a[i], 1);
}

ll querry(int idx){
    idx++;
    int sum = 0;
    while(idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

ll bs(int k){
    int l = 1;
    int r = n+1;
    while(l <= r){
        int mid = (r+l)/2;
        if(querry(mid) >= k) r = mid-1;
        else l = mid+1;
    }
    return r == n+1? 0 : r+1;
}

void solve(){
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    build();
    while(k--){
        int x;
        cin>>x;
        if(x > 0) update(x,1);
        else update(bs(-x),-1);
    }
    deb1(bs(1))
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