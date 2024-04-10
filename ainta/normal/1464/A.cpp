#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int A[101000], Deg[101000], Q[101000], vis[101000];
void Solve(){
    int i;
    scanf("%d%d",&n,&m);
    int head=0,tail=0, res = 0;
    for(i=1;i<=n;i++)Deg[i]=A[i]=vis[i]=0;
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        A[x]=y;
        Deg[y]++;
    }
    for(i=1;i<=n;i++)if(!Deg[i])Q[++tail]=i;
    while(head < tail){
        int x = Q[++head];
        vis[x]=1;
        if(!A[x])continue;
        res++;
        Deg[A[x]]--;
        if(!Deg[A[x]])Q[++tail]=A[x];
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            if(A[i]==i)continue;
            int x = i;
            int cc=0;
            while(1){
                vis[x]=1;
                cc++;
                x=A[x];
                if(x==i)break;
            }
            res += cc+1;
        }
    }
    printf("%d\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}