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

const ll   MAXN  =  1e+6+7;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

priority_queue <ll, vector<ll>, greater<ll>> s;
int n,k,u,v1;
vpll v;

int main(){
    fastio;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>u>>v1;
        v.push_back({v1,u});
    }
    sort(v.begin(),v.end(),greater<pll>());
    ll ans = 0;
    ll sum = 0;
    ll m = 0;
    for(int i = 0; i < n; i++){
        m = v[i].first;
        if(i < k){
            s.push(v[i].second);
            sum += v[i].second;
        }
        else{
            ll it = s.top();
            sum -= (it);
            sum += v[i].second;
            s.pop();
            s.push(v[i].second);
        }
        ans = max(ans,sum*m);
    }
    //while(!s.empty()){cout << '\t' << s.top()<<endl; s.pop(); }
    cout<<ans<<endl;
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}