#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<functional>
#define N 6300
using namespace std;
int a[N],ans=1;
vector<int> low[N],high[N];
bool visit[N];
vector<int> g[N];
void DFS(int u){
    int v,k,tmp;
    visit[u]=true;
    low[u].push_back(a[u]);
    high[u].push_back(a[u]);
    for(int i=0;i<g[u].size();i++){
        v=g[u][i];
        if(visit[v]) continue;
        DFS(v);
        k=upper_bound(low[v].begin(),low[v].end(),a[u]-1)-low[v].begin();
        if(k==low[v].size()) low[v].push_back(a[u]);
        else low[v][k]=a[u];
        k=upper_bound(high[v].begin(),high[v].end(),a[u]+1,greater<int>())-high[v].begin();
        if(k==high[v].size()) high[v].push_back(a[u]);
        else high[v][k]=a[u];
        for(int j=0;j<low[v].size();j++){
            tmp=(upper_bound(high[u].begin(),high[u].end(),low[v][j]+1,greater<int>())-high[u].begin())+j+1;
            ans=max(tmp,ans);
        }
        for(int j=0;j<high[v].size();j++){
            tmp=(upper_bound(low[u].begin(),low[u].end(),high[v][j]-1)-low[u].begin())+j+1;
            ans=max(tmp,ans);
        }
        for(int j=0;j<high[u].size()||j<high[v].size();j++){
            if(j<high[u].size()&&j<high[v].size()) high[u][j]=max(high[u][j],high[v][j]);
            else if(j<high[v].size()) high[u].push_back(high[v][j]);
        }
        for(int j=0;j<low[u].size()||j<low[v].size();j++){
            if(j<low[u].size()&&j<low[v].size()) low[u][j]=min(low[u][j],low[v][j]);
            else if(j<low[v].size()) low[u].push_back(low[v][j]);
        }
    }
}

int main(){
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1);
    printf("%d\n",ans);
    return 0;
}