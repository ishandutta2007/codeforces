#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5,M=3e6,inf=(ll)1e9;
int from[M],to[M],cap[M],ptr[N],head[N],prv[M],ecnt=0,dis[N];
vector <int> g[N];
void add_edge(int v,int u,int ca){
    from[ecnt]=v,to[ecnt]=u,cap[ecnt]=ca,prv[ecnt]=head[v],head[v]=ecnt++;
    from[ecnt]=u,to[ecnt]=v,cap[ecnt]=0,prv[ecnt]=head[u],head[u]=ecnt++;
    g[u].pb(ecnt-1);
}
void del(int v){
    for (auto yal : g[v]){
        if (cap[yal]>0){
            cap[yal]--;
          //  cout << from[yal] << " yal " << to[yal] << endl;
            cap[yal ^ 1]++;
            del(to[yal]);
            break;
        }
    }
}
inline bool bfs(int source,int sink){
    memset(dis,31,sizeof dis);
    dis[source]=0;
    queue <int> q;
    q.push(source);
    while(q.size()){
        int v=q.front();
     //   cout << v << endl;
        q.pop();
        if (v==sink) return 1;
        for (auto yal=head[v];yal>-1;yal=prv[yal]){
            int u=to[yal];
            if (cap[yal]==0) continue;
            if (dis[u]>dis[v]+1){
                dis[u]=dis[v]+1;
                q.push(u);
            }
        }
    }
    return 0;
}
int dfs(int v,int sink,int f){
    if (sink==v || f==0) return f;
    int ans=0;
    for (auto &yal=ptr[v];yal>-1;yal=prv[yal]){
        int u=to[yal];
        if (cap[yal]==0 || dis[u]!=dis[v]+1) continue;
        int z=dfs(u,sink,min(f,cap[yal]));
        f-=z;
        ans+=z;
        cap[yal]-=z;
        cap[yal ^ 1]+=z;
        if (f==0) break;
    }
    return ans;
}
int maxflow(ll source,ll sink){
    int ans=0;
    while(bfs(source,sink)){
        for (int i=0;i<N;i++) ptr[i]=head[i];
        dfs(source,sink,inf);
    }
    for (int i=0;i<ecnt;i+=2) if (from[i]==N-2) ans+=cap[i^1];
    return ans;
}
int a[300][300];
int ras[300][300];
int32_t main(){
    sync;
    memset(head,-1,sizeof head);
    int n;
    cin >> n ;
    memset(ras,-1,sizeof ras);
    vector <pii> b;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j]!=-1) ras[i][j]=i*n+j;
            if (a[i][j]>0) b.pb({a[i][j],ras[i][j]}),add_edge(ras[i][j],N-1,inf);
        }
    }
    sort(b.begin(),b.end());
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ras[i][j]==-1) continue;
            for (int k=-1;k<=1;k++){
                for (int l=-1;l<=1;l++){
                    if (ras[i+k][j+l]==-1 || (k+l)%2==0) continue;
                    add_edge(ras[i+k][j+l],ras[i][j],1);
                }
            }
        }
    }
    ll ans=0;
    for (int i=0;i<b.size()-1;i++){
        int v=b[i].S;

        for (int i=0;i<ecnt;i+=2){
            if (from[i]==v && to[i]==N-1){
                for (int j=1;j<=cap[i^1];j++){
                    del(v);
                }
                cap[i]=0;
                cap[i^1]=0;
            }
        }

        add_edge(N-2,v,inf);
        int jav=maxflow(N-2,N-1);
       // cout << v << " " << jav << endl;
        ans+=1ll * jav * (b[i+1].F-b[i].F);

    }
    kill(ans);


}

/*
5
1 1 1 1 2
1 -1 0 0 1
1 0 0 -1 1
2 -1 0 0 1
1 2 1 1 1
*/