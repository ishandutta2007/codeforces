#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
 
vector <int> adj[500005];
int a[100005],b[100005],c[100005],vis[100005];
ll m[6] = {};
ll ct = 0;
int f[100005];

void dfs(ll x,int i, int j){
    for(auto it : adj[x]){
        if(vis[it] == 0){
            vis[it] = 1;
            //cout<<it<<" "<<i<<endl;
            if(i == 1)
                m[ct] += a[it];
            else if(i == 2)
                m[ct] += b[it];
            else
                m[ct] += c[it];
            f[it] = i;
            dfs(it,(i+j)%3,j);
        }        
    }
}

int main(){
    ll t,n,u,v;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) cin>>b[i];
    for(int i = 1;i<=n;i++) cin>>c[i];
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll st;
    for(int i = 1;i<=n;i++){
        //cout<<i<<" "<<adj[i].size();
        if(adj[i].size() > 2){
            cout<<"-1\n";
            exit(0);
        }
        if(adj[i].size() == 1)
            st = i;
    }
    ll min = 1e15;
    int mi = 0, I = 0, J = 0;
    for(int i = 1;i<4;i++){
        for(int i = 1;i<100005;i++) vis[i] = 0;
        if(i == 1)
            m[ct] += a[st];
        else if(i == 2)
            m[ct] += b[st];
        else
            m[ct] += c[st];
        vis[st] = 1;
        dfs(st,(i+1)%3,1);
        if(m[ct] < min){
            min = m[ct];
            mi = ct;
            I = i;
            J = 1;
        }
        ct++;

        for(int i = 1;i<100005;i++) vis[i] = 0;
        if(i == 1)
            m[ct] += a[st];
        else if(i == 2)
            m[ct] += b[st];
        else
            m[ct] += c[st];
        vis[st] = 1;
        dfs(st,(i+2)%3,2);
        if(m[ct] < min){
            min = m[ct];
            mi = ct;
            I = i;
            J = 2;
        }
        ct++;
    }
    cout<<m[mi]<<endl;
    for(int i = 1;i<100005;i++) vis[i] = 0;
    vis[st] = 1;
    f[st] = I;
    //cout<<I<<J;
    dfs(st,(I+J)%3,J);
    for(int i = 1;i<=n;i++){
        if(f[i] == 0)
            cout<<3<<" ";
        else
            cout<<f[i]<<" ";
    }
}