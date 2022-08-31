#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
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
 
const ll   N     =  5e+5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,m,l,r,c,res = INF;
vector <pair<ll,pll>> v;
vpll adj[N];
 
int main(){
    fastio;

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>l>>r>>c;
        v.push_back({l,{r,c}});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        ll ind = v[i].y.x - v[i].x + 1;
        adj[ind].push_back({v[i].x,v[i].y.y});
    }
    for(int i=0;i<N;i++){
        for(int j = adj[i].size()-2;j>=0;j--){
            adj[i][j].y = min(adj[i][j].y, adj[i][j+1].y);
        }
    }

    for(int i = 0; i < n; i++){
        ll x1 = m - (v[i].y.x - v[i].x + 1);
        if(x1 <= 0 or adj[x1].size() == 0)
            continue;

        r = v[i].y.x;
        c = v[i].y.y;
        ll low = 0 ,high = adj[x1].size()-1,ind = -1;
        while(low <= high){
            ll mid  = (low+high)/2;
            //cout<<x1<<" "<<low<<" "<<high<<endl;
            if(adj[x1][mid].x > r){
                ind = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ind == -1) continue;
        else{
            res = min(res,c + adj[x1][ind].y);
        }
    }

    if(res == INF) cout<<-1<<endl;
    else cout<<res<<endl;
}