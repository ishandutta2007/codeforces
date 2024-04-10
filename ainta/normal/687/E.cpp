#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[6010], F[6010];
int n, m, ord[6010], cnt, SCC[6010], SZ[6010], M[6010], Res, Q[6010], head, tail, D[6010];
bool v[6010], chk[6010];
void DFS(int a){
    v[a]=true;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
    ord[++cnt] = a;
}
void DFS2(int a){
    SCC[a] = cnt;
    SZ[cnt]++;
    int i;
    for(i=0;i<F[a].size();i++){
        if(!SCC[F[a][i]])DFS2(F[a][i]);
    }
}
int Gap(int a){
    int i, x;
    head = 0, tail = 0;
    for(i=1;i<=n;i++)D[i]=0;
    Q[++tail] = a;
    while(1){
        x = Q[++head];
        if(x==a && D[x])break;
        for(i=0;i<E[x].size();i++){
            if(!D[E[x][i]]){
                Q[++tail] = E[x][i];
                D[E[x][i]] = D[x]+1;
            }
        }
    }
    return D[a];
}
int main(){
    int i, a, b, j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        F[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!v[i]){
            DFS(i);
        }
    }
    cnt = 0;
    for(i=n;i>=1;i--){
        if(!SCC[ord[i]]){
            cnt++;
            DFS2(ord[i]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<E[i].size();j++){
            if(SCC[i]!=SCC[E[i][j]]){
                chk[SCC[i]] = true;
            }
        }
    }
    for(i=1;i<=n;i++)M[i] = n+1;
    for(i=1;i<=n;i++){
        if(!chk[SCC[i]] && SZ[SCC[i]] != 1){
            a = Gap(i);
            if(M[SCC[i]] > a)M[SCC[i]] = a;
        }
    }
    Res = n;
    for(i=1;i<=cnt;i++){
        if(!chk[i] && SZ[i]!=1){
            Res += M[i]*998+1;
        }
    }
    printf("%d\n",Res);
}