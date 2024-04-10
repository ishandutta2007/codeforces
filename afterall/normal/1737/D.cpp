//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=510;
ll id[N][N];
pii b[N*N];
ll yal[N][N];
vector <int> y[N];
ll dis[N*N];
void bfs(ll n){
    for (int i=0;i<=n*n;i++){
        dis[i]=(ll)1e15;
    }
    dis[id[1][n]]=0;
    dis[id[n][1]]=0;
    queue <int> q;
    q.push(id[1][n]);
    q.push(id[n][1]);
    while(q.size()){
        ll V=q.front();
       // cout << v << " eerf " << dis[v] << endl;
        q.pop();
        ll v=b[V].F;
        ll u=b[V].S;
        for (int i=1;i<=n;i++){
            if (yal[i][v]!=(ll)1e15 || v==u){
                if (dis[id[i][u]]>dis[V]+1){
                    dis[id[i][u]]=dis[V]+1;
                    q.push(id[i][u]);
                }
            }
            if (yal[i][u]!=(ll)1e15 || v==u){
                if (dis[id[i][v]]>dis[V]+1){
                    dis[id[i][v]]=dis[V]+1;
                    q.push(id[i][v]);
                }
            }
        }
    }
}
void Main(){
    ll n,m;
    cin >> n >> m;
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            yal[i][j]=(ll)1e15;
        }
    }
    for (int i=1;i<=n;i++) y[i].clear();
    ll cnt=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            id[i][j]=cnt;
            b[cnt]={i,j};
            cnt++;
        }
    }
    for (int i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        yal[u][v]=min(yal[u][v],w);
        yal[v][u]=yal[u][v];
        y[u].pb(v);
        y[v].pb(u);
    }
    
    bfs(n);
    ll ans=(ll)1e15;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
          //  cout << i << " " << j << " " << dis[id[i][j]] << endl;
            ans=min(ans,(dis[id[i][j]]+1)*yal[i][j]);
            
        }
    }
    cout << ans << endl;
   // cout << dis[id[2][6]] << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();

    
}
/*
 1
 3
 1 1 1 2 2 2
 2 3
 */