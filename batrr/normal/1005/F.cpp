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
vector<int>g[maxn],vec[maxn];
int n,m,k,depth[maxn],was[maxn];
map<int,int>id[maxn];
string ans;
vector<string>ANS;
void rec(int v){
    if(v==n+1){
        ANS.pb(ans);
        k--;
        if(k==0){
            cout<<ANS.size()<<endl;
            for(int i=0;i<ANS.size();i++)
                cout<<ANS[i]<<endl;
            exit(0);
        }
    }
    for(auto x:vec[v]){
        ans[x]='1';
        rec(v+1);
        ans[x]='0';
    }
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int v,u;
        cin>>v>>u;
        g[v].pb(u);
        g[u].pb(v);
        id[v][u]=i;
        id[u][v]=i;
    }
    queue<int>q;
    was[1]=1;
    q.push(1);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto to:g[v])
            if(!was[to]){
                was[to]=1;
                depth[to]=depth[v]+1;
                q.push(to);
            }
    }
    for(int v=2;v<=n;v++){
        for(auto to:g[v])
            if(depth[to]==depth[v]-1)
                vec[v].pb(id[to][v]);    
    }
    for(int i=0;i<m;i++)
        ans+='0';
    rec(2);
    cout<<ANS.size()<<endl;
    for(int i=0;i<ANS.size();i++)
        cout<<ANS[i]<<endl;
}