#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[301000], V[301000];
int n, m, Col[301000], Res, Num[301000], v[301000];
void DFS(int a, int pp){
    int i, x;
    for(i=0;i<V[a].size();i++){
        x = V[a][i];
        if(Num[x])v[Num[x]] = 1;
    }
    int pv = 1;
    for(i=0;i<V[a].size();i++){
        x = V[a][i];
        if(!Num[x]){
            while(v[pv])pv++;
            v[pv] = 1;
            Num[x] = pv;
        }
    }
    for(i=0;i<V[a].size();i++)v[Num[V[a][i]]]=0;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)DFS(E[a][i], a);
    }
}
int main(){
    int i, c, j, a, b, rt = 0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        for(j=0;j<c;j++){
            scanf("%d",&a);
            V[i].push_back(a);
        }
        if(c==0){
            c++;
        }
        if(Res < c){
            rt = i;
            Res = c;
        }
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(rt, 0);
    printf("%d\n",Res);
    for(i=1;i<=m;i++){
        if(!Num[i])Num[i] = 1;
        printf("%d ",Num[i]);
    }
}