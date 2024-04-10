#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100010
using namespace std;
vector<int> g[N];
vector<int> ans;
int diff[N];
int DFS(int now,int from,int odd,int even){
    int i,count=diff[now]^odd;
    if(count) ans.push_back(now);
    for(i=0;i<g[now].size();i++){
        if(g[now][i]==from) continue;
        count+=DFS(g[now][i],now,even,diff[now]);
    }
    return count;
}
int main(){
    int n,i,x,y;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(i=1;i<=n;i++) scanf("%d",&diff[i]);
    for(i=1;i<=n;i++) scanf("%d",&x),diff[i]^=x;
    printf("%d\n",DFS(1,0,0,0));
    for(i=0;i<ans.size();i++) printf("%d\n",ans[i]);
    return 0;
}