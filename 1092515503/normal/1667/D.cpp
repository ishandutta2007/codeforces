/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,head[200100],cnt,deg[200100];
struct node{int to,next;bool eve;}edge[400100];
void ae(int u,int v){
    edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
    edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
    deg[u]++,deg[v]++;
}
bool ok;
void dfs(int x,int fi){
    int sz=0;
    for(int i=head[x];i!=-1;i=edge[i].next)if((i^fi)!=1)
        dfs(edge[i].to,i),sz+=edge[i].eve;
    if(fi!=-1)edge[fi].eve=edge[fi^1].eve=(deg[x]>>1)-sz,sz+=edge[fi].eve;
    if(sz!=(deg[x]>>1))ok=false;
}
vector<int>g[200100];
queue<int>q;int in[200100];
void AE(int x,int y){/*printf("%d->%d\n",x,y),*/g[x].push_back(y),in[y]++;}
void mina(){
    scanf("%d",&n),cnt=0;for(int i=1;i<=n;i++)head[i]=-1,deg[i]=0;
    for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y);
    ok=true,dfs(1,-1);if(!ok){puts("NO");return;}
    // for(int i=0;i<cnt;i+=2)printf("%d\n",edge[i].eve);
    for(int x=1;x<=n;x++){
        static int odd[200100],ODD,eve[200100],EVE;
        for(int i=head[x];i!=-1;i=edge[i].next)
            (edge[i].eve?eve[++EVE]:odd[++ODD])=i>>1;
        // printf("%d:%d,%d\n",x,ODD,EVE);
        // for(int i=1;i<=ODD;i++)printf("%d ",odd[i]);puts("");
        // for(int i=1;i<=EVE;i++)printf("%d ",eve[i]);puts("");
        assert(ODD==EVE||ODD==EVE+1);
        for(int i=1,las=-1;i<=ODD;i++){
            if(las!=-1)AE(odd[i],las);las=odd[i];
            if(i<=EVE)AE(eve[i],las);las=eve[i];
        }
        ODD=EVE=0;
    }
    for(int i=0;i+1<n;i++)if(!in[i])q.push(i);
    puts("YES");
    while(!q.empty()){
        int x=q.front();q.pop();
        printf("%d %d\n",edge[x<<1|1].to,edge[x<<1].to);
        for(auto y:g[x])if(!--in[y])q.push(y);g[x].clear();
    }
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}
/*
1
4
1 2
2 3
3 4
*/