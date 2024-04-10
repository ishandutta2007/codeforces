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
const ll MAX=1001000;
vector<ll> parent(MAX),height(MAX);
ll find_set(ll a){
    if(parent[a]==a)
        return a;
    return find_set(parent[a]);
}
void precompute(){
    for(ll i=1;i<MAX;i++)
        parent[i]=i,height[i]=1;
}
void union_set(ll a,ll b){
    a=find_set(a),b=find_set(b);
    if(a==b)
        return;
    if(height[a]<height[b])
        swap(a,b);
    height[a]+=height[b];
    parent[b]=a;
}
ll comp(ll r,ll d){
    return d*70+r;
}
void solve(){
    ll n; cin>>n;
    vector<vector<ll>> blocked(729,vector<ll>(60,0));
    for(ll i=1;i<=n;i++){
        char c; cin>>c;
        if(c=='C'){
            ll r,o1,o2; cin>>r>>o1>>o2;
            while(o1!=o2){
                blocked[2*o1][2*r]=1;
                blocked[2*o1+1][2*r]=1;
                blocked[2*o1+2][2*r]=1;
                o1=(o1+1)%360;
            }
        }
        else{
            ll r1,r2,o; cin>>r1>>r2>>o;
            while(r1!=r2){
                blocked[2*o][2*r1]=1;
                blocked[2*o][2*r1+1]=1;
                blocked[2*o][2*r1+2]=1;
                r1++;
            }
        }
    }
    precompute();
    for(ll i=0;i<=50;i++){   
        for(ll j=0;j<=720;j++){
            if(blocked[j][i]){
                continue;
            }
            ll x=i;
            ll y=j; j=j%720;
            if(blocked[j][i+1]==0){
                union_set(comp(i,y),comp(i+1,j));
            }
            if(blocked[(j+1)%720][i]==0){
                union_set(comp(i,j),comp(i,(j+1)%720));
            }
            j=y; 
        }
    }
    if(find_set(comp(0,0))==find_set(comp(45,0))){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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