#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
vector<int>g[maxn];
int n,q,a[maxn],tin[maxn],tout[maxn],timer;
void dfs(int v){
    tin[v]=++timer;
    a[timer]=v;
    for(auto to:g[v])
        dfs(to);
    tout[v]=timer;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS          
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].pb(i);
    }
    dfs(1);
    while(q--){
        int v,x;
        cin>>v>>x;
        if(tout[v]-tin[v]+1<x)
            cout<<-1<<endl;
        else
            cout<<a[tin[v]+x-1]<<endl;
    }
}