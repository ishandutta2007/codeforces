#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  4e+5+3;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,u,v,a[N],p[N];
um m;
set <pll> s;

ll check(ll xx){
    ll i = sqrt(xx);
    while(xx%i != 0) i--;
    return i;
}

int main(){
    fastio;
    
    cin>>n;
    for(ll i = 0; i < n; i++) cin>>a[i], m[a[i]]++;
    for(ll i = 0; i < n; i++) s.insert({m[a[i]],a[i]});
    ll l,r;
    while(true){
        auto it = s.end();
        it--;
        ll maxx = (*it).x;
        u = (*it).y;
        s.erase(it);
        r = check(n);
        if(maxx > r){
            s.insert({maxx-1,u});
        }
        else{
            s.insert({maxx,u});
            l = n/r;
            break;
        }
        n--;
    }
    cout<<n<<endl;
    cout<<r<<" "<<l<<endl;
    ll ans[r][l], ind[r];
    for(ll i = 0; i < r; i++) for(ll j = 0; j < l; j++) ans[i][j] = 0;
    for(ll i = 0; i < r; i++) ind[i] = i;
    ll i = 0;
    for (auto rit = s.rbegin(); rit != s.rend(); rit++){
        u = (*rit).x;
        v = (*rit).y;
        while(u > 0){
            if(ind[i] == i && ans[i][ind[i]] != 0){
                i++;
                continue;
            }
            ans[i][ind[i]++] = v;
            ind[i] %= l;
            i++;
            i %= r;
            u--;
        }
    }
    
    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < l; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}