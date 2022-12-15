#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

struct edge{
    int u,v,w;
}arr[300001];

vector<int> adj[300001];
lli dist[300001];
int n,m,k,vis[300001],pr[300001];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0,u,v,w;i<m;i++){
        scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w);
        adj[arr[i].u].push_back(i);
        adj[arr[i].v].push_back(i);
    }

    priority_queue<pli,vector<pli>,greater<pli>>que;
    que.push(pli(0,1));
    for(int i=1;i<=n;i++) dist[i]=1e15;
    dist[1]=0;
    memset(pr,-1,sizeof(pr));

    vector<int>ans;
    while(!que.empty() && k){
        lli cost=que.top().fi;
        int cur=que.top().se;
        que.pop();
        if(vis[cur])continue;
        vis[cur]=1;
        if(pr[cur]!=-1) ans.push_back(pr[cur]+1),k--;
        for(auto &it:adj[cur]){
            int c=arr[it].w,v=arr[it].u^arr[it].v^cur;

            if(!vis[v]&&dist[v]>cost+c){

                dist[v]=cost+c;
                pr[v]=it;
                que.push(pli(dist[v],v));
            }
        }
    }

    printf("%d\n",sz(ans));
    sort(ans.begin(),ans.end());
    for(auto &it:ans)
        printf("%d ",it);

    return 0;
}