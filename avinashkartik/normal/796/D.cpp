#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 3e+5 + 5;

ll a[N],vis[N];
ll n,m,k,x,u,v;
vector <pair<ll,ll>> adj[N];
set <ll> ans;
string s;
queue <pair<ll,ll>> q;

void bfs(){
    while(!q.empty()){
        ll i = q.front().first;
        ll j = q.front().second;
        q.pop();
        if(!vis[i]){
            vis[i] = 1;
            for(auto it: adj[i]){
                if(it.first == j) continue;
                //cout<<it.first<<" "<<vis[it.first]<<endl;
                if(vis[it.first] == 0)
                    q.push({it.first,i});
                else
                    ans.insert(it.second);
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        cin>>x;
        a[x] = 1;
        q.push({x,0});
    }
    for(int i = 1; i<=n-1; i++){
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    bfs();
    cout<<ans.size()<<endl;
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
}