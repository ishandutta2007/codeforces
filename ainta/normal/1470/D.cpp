#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define N_ 301000
using namespace std;
int n, m, vis[N_], ord[N_], cnt, CK[N_], vv[N_];
vector<int>E[N_];
void DFS(int a){
    ord[++cnt]=a;
    vis[a]=1;
    for(auto &x : E[a]){
        if(!vis[x])DFS(x);
    }
}
void Solve(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        vis[i]=CK[i]=vv[i]=0;
        E[i].clear();
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    cnt = 0;
    DFS(1);
    if(cnt!=n){
        puts("NO");
        return;
    }
    //reverse(ord+1,ord+n+1);
    vector<int>Ans;
    for(int ii=0;ii<3;ii++){
        for(i=1;i<=n;i++){
            int x = ord[i];
            //printf("%d\n",x);
            if(CK[x]||vv[x])continue;
            int ck=0;
            for(auto &t : E[x]){
                ck|=CK[t];
            }
            if(!ck && i!=1)continue;
            Ans.push_back(x);
            vv[x]=1;
            for(auto &t : E[x])CK[t]=1;
        }
    }
    puts("YES");
    printf("%d\n",Ans.size());
    for(auto &x : Ans)printf("%d ",x);
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}