#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 200005;
static ll n, k;
static ll uni[MAX];
static vector<vector<ll>> adj;
static ll vis[MAX];
static ll s[MAX];
ll dfs(ll src){
    vis[src] = 1;
    ll fin = 0;
    if(uni[src] == 1){
        fin += 1;
    }
    for(ll x: adj[src]){
        if(vis[x] == 0){
            fin += dfs(x);
        }
    }
    s[src] = fin;
    return fin;
}

int main(){
    cin >>n>> k;
    for(ll i =0 ; i<2*k; i++){
        ll d;
        cin >> d;
        d -= 1;
        uni[d] = 1;
    }
    for(ll i = 0; i<n; i++){
        vector<ll> temp;
        adj.emplace_back(temp);
    }
    for(ll i =0 ; i<n-1; i++){
        ll x, y;
        cin >> x >> y;
        x-= 1;
        y -= 1;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    dfs(0);
    //preprocess();
    //cout << endl;
    ll fin = 0;
    for(ll i = 0; i<n; i++){
        //cout << i + 1 << " " << s[i] << endl;
        fin += min(s[i], 2*k - s[i]);
    }
    cout << fin << endl;
    return 0;
}