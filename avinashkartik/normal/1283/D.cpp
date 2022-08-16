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
 
const ll   N     =  3e+5+7;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,m,a[N];
vpll l,r;
vll ans;

int main(){
    fastio;
    ll t;
    cin>>n>>m;
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a,a+n);
    for(int i = 0; i < n; i++){
        if(i == 0){
            l.push_back({1e9,a[i]});
        }
        else{
            l.push_back({ceil((a[i]-a[i-1]-1)/2.0),a[i]});
        }
        if(i == 0){
            r.push_back({1e9,a[n-1]});
        }
        else{
            r.push_back({(a[i]-a[i-1]-1)/2,a[i-1]});
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    ll l1 = 0, r1 = 0;
    ll ct = 1;
    ll res = 0;
    //for(auto it: l) cout<<it.x<<" "<<it.y<<endl;
    while(m > 0){
        for(ll it = l1; it < n; it++){
            if(m == 0) break;
            if(l[it].x <= 0) l1++;
            else{
                ans.push_back(l[it].y-ct);
                l[it].x--;
                res += ct;
                m--;
            }
        }
        for(ll it = r1; it < n; it++){
            if(m == 0) break;
            //cout<<r[it].x<<" "<<r[it].y<<endl;
            if(r[it].x <= 0) r1++;
            else{
                ans.push_back(r[it].y+ct);
                r[it].x--;
                res += ct;
                m--;
            }
        }
        ct++;
    }
    cout<<res<<endl;
    for(auto it : ans) cout<<it<<" ";
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}