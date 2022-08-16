#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 3e+5 + 5;

ll cnt[2][N],vis[2][N],visup[2][N];
ll n,m,k,x,u,v,ans,ct;
vector <pair<ll,ll>> adj[N];
string s;
queue <pair<ll,ll>> q;

void dfs(ll i,int key){
    if(!vis[key][i]){
        vis[key][i] = 1;
        ct += 1;
        for(auto it: adj[i]){
            if(it.second == key)
                dfs(it.first,key);
        }
    }
}

void dfsup(ll i,int key){
    if(!visup[key][i]){
        visup[key][i] = 1;
        cnt[key][i] = ct;
        for(auto it: adj[i]){
            if(it.second == key)
                dfsup(it.first,key);
        }
    }
}

int main(){
    cin>>n;
    for(int i = 1; i<=n-1; i++){
        cin>>u>>v>>x;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }
    for(int i = 1; i <= n; i++){
        ct = 0;
        if(!vis[0][i]){
            dfs(i,0);
            dfsup(i,0);
        }
        ans += ct*(ct-1);
        ct = 0;
        if(!vis[1][i]){
            dfs(i,1);
            dfsup(i,1);
        }
        ans += ct*(ct-1);
    }
    for(int i = 1; i <= n; i++){
        //cout<<cnt[0][i]<<" "<<cnt[1][i]<<endl;
        //ans += cnt[0][i]*(cnt[0][i]-1);
        //ans += cnt[1][i]*(cnt[1][i]-1);
        ans += (cnt[0][i]-1)*(cnt[1][i]-1);
    }
    cout<<ans<<endl;
}