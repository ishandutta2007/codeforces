#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
#define N (int)3e3+3

ll n,m,u,v;
vector <ll> adj[N];
ll a[N][N],ct[N],ans;

int main(){ 
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        a[u][v] = 1;
    }
    for(int i = 1; i <= n; i++){
        fill_n(ct,N,0);
        for(auto it : adj[i]){
            for(auto it1 : adj[it]){
                ct[it1]++;
            }
        }
        //for(int j = 1; j <= n; j++) cout<<ct[j]<<" ";
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            ans += ct[j]*(ct[j]-1)/2;
        }
        //cout<<endl;
    }
    cout<<ans;
}