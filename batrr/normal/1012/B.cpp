#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
vector<int> g[2][maxn];
bool used[2][maxn];
int n,m,q,ans;
void dfs(int v,int k){
    if(used[k][v])
        return;
    used[k][v]=1;
    for(auto to:g[k][v])
        dfs(to,1-k);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;  
        g[0][x].pb(y);
        g[1][y].pb(x);
    }
    for(int i=1;i<=n;i++)
        if(!used[0][i]){
            dfs(i,0);
            ans++;
            }
    for(int i=1;i<=m;i++)
        if(!used[1][i]){
            dfs(i,1);
            ans++;
            }
    cout<<ans-1;
}