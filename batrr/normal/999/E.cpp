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

const ll maxn=1e5+123,inf=1e18,mod=1e9+7,N=360360;

vector < int > g[maxn];
vector < pair<int,int> > vec;
int n,m,s,ans,cnt[maxn];
bitset<10000>used;

void dfs(int v,int p,bool flag) {
    if(flag)     
        cnt[p]++;
    used[v]=1;
    for(auto to:g[v])
        if(!used[to])
            dfs(to,p,flag);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    
    cin>>n>>m>>s;
    while(m--){
        int v,u;
        cin>>v>>u;
        g[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        dfs(i,i,1);
        used=0;
        vec.pb(mp(-cnt[i],i));
    }
    dfs(s,s,1);
    sort(vec.begin(),vec.end());
    for(auto v:vec)
        if(!used[v.s]) {
            dfs(v.s,v.s,1);
            ans++;
        }
    cout<<ans;
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}