#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;     
using namespace std;
#define ll long long
const ll INF_MUL=1e13;
const ll INF_ADD=1e18; 
#define pb push_back                 
#define mp make_pair              
#define nline "\n"                             
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()       
#define vl vector<ll>           
#define vvl vector<vector<ll>>      
#define vvvl vector<vector<vector<ll>>>             
#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);    
#endif     
void _print(ll x){cerr<<x;}  
void _print(char x){cerr<<x;}   
void _print(string x){cerr<<x;}    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());   
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD=754974721;   
const ll MAX=500500;
class ST {
public:
    vector<ll> segs;
    ll size = 0;
    ll ID = -INF_ADD;
 
    ST(ll sz) {
        segs.assign(2 * sz, ID);
        size = sz;  
    }   
   
    ll comb(ll a, ll b) {
        return max(a, b);  
    }
 
    void upd(ll idx, ll val) {
        segs[idx += size] = val;
        for(idx /= 2; idx; idx /= 2) segs[idx] = comb(segs[2 * idx], segs[2 * idx + 1]);
    }
 
    ll query(ll l, ll r) {
        ll lans = ID, rans = ID;
        for(l += size, r += size + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) lans = comb(lans, segs[l++]);
            if(r & 1) rans = comb(segs[--r], rans);
        }
        return comb(lans, rans);
    }
}; 
class ST1 {
public:
    vector<ll> segs;
    ll size = 0;
    ll ID = INF_ADD;
      
    ST1(ll sz) {
        segs.assign(2 * sz, ID);
        size = sz;  
    }   
   
    ll comb(ll a, ll b) {
        return min(a, b);  
    }
 
    void upd(ll idx, ll val) {
        segs[idx += size] = val;
        for(idx /= 2; idx; idx /= 2) segs[idx] = comb(segs[2 * idx], segs[2 * idx + 1]);
    }
 
    ll query(ll l, ll r) {
        ll lans = ID, rans = ID;
        for(l += size, r += size + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) lans = comb(lans, segs[l++]);
            if(r & 1) rans = comb(segs[--r], rans);
        }
        return comb(lans, rans);
    }
}; 
void solve(){
    ll n,a,b; cin>>n>>a>>b;
    vector<ll> p(n+5);
    ST lft(n); 
    ST1 rght(n);  a--,b--; 
    for(ll i=0;i<n;i++){
        cin>>p[i];
        if(i==a){
            continue;
        }
        lft.upd(i,p[i]+i); 
        rght.upd(i,i-p[i]); 
        //debug(mp(i,mp(lft.query(i,i),rght.query(i,i))));
    }
    vector<ll> dp(n+5,INF_ADD);
    dp[a]=0;
    queue<ll> track; track.push(a);
    //ll cur=0;
    while(!track.empty()){
        auto it=track.front();
        track.pop();
        //ll till=0;  
        // debug(it);  
        // debug(dp[it]);
        while(1){
            ll tar=lft.query(max(it-p[it],0LL),it);
            if(tar<it){
                break;
            } 
            ll l=max(it-p[it],0LL),r=it; ll ind=l;
            while(l<=r){
                ll mid=(l+r)/2;
                ll check=lft.query(mid,it);
                if(check==tar){
                    ind=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1; 
                }   
            }
            if(dp[ind]>dp[it]+1){
                dp[ind]=dp[it]+1;
                track.push(ind);
            }  
            lft.upd(ind,-INF_MUL);
            rght.upd(ind,INF_MUL);
        }
        //till=0;  
        while(1){
            ll tar=rght.query(it,min(it+p[it],n-1));
            // debug(tar); 
            // debug(mp(it,min(it+p[it],n-1)));
            // till++;
            // if(till>20){
            //     break;
            // } 
            if(tar>it){  
                break;
            }  
            ll l=it,r=min(it+p[it],n-1); ll ind=r;
            while(l<=r){
                ll mid=(l+r)/2;
                ll check=rght.query(it,mid);
                if(check==tar){
                    ind=mid;
                    r=mid-1;   
                }
                else{
                    l=mid+1; 
                }  
            }
            if(dp[ind]>dp[it]+1){
                dp[ind]=dp[it]+1;
                track.push(ind);
            }  
            //debug(ind); 
            lft.upd(ind,-INF_MUL);
            rght.upd(ind,INF_MUL);
        }
    }
    cout<<dp[b]<<nline;
    return; 
}                                    
int main()                                                                                 
{      
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);                              
    #ifndef ONLINE_JUDGE                 
    freopen("input.txt", "r", stdin);                                              
    freopen("output.txt", "w", stdout);  
    freopen("error.txt", "w", stderr);                          
    #endif         
    ll test_cases=1;               
    cin>>test_cases; 
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
}