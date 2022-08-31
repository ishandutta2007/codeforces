#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, QQ, D[1010][1010];
struct Edge{
    int a, b;
}w[201000];
struct Query{
    int l, r, a, b, num;
    bool operator<(const Query &p)const{
        return l<p.l;
    }
}Q[201000];
int Res[201000];
int main(){
    int i, j;
    scanf("%d%d%d",&n,&m,&QQ);
    for(i=1;i<=m;i++){
        scanf("%d%d",&w[i].a,&w[i].b);
    }
    for(i=0;i<QQ;i++){
        scanf("%d%d%d%d",&Q[i].l,&Q[i].r,&Q[i].a,&Q[i].b);
        Q[i].num=i;
    }
    sort(Q,Q+QQ);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)D[i][j] = m+1;
    int pv = m;
    for(i=QQ-1;i>=0;i--){
        while(pv >= 1 && pv >= Q[i].l){
            D[w[pv].a][w[pv].b] = D[w[pv].b][w[pv].a] = pv;
            for(j=1;j<=n;j++){
                D[w[pv].b][j] = D[w[pv].a][j] = min(D[w[pv].a][j],D[w[pv].b][j]);
            }
            pv--;
        }
        if(D[Q[i].a][Q[i].b] <= Q[i].r){
            Res[Q[i].num] = 1;
        }
    }
    for(i=0;i<QQ;i++){
        printf(Res[i]?"Yes\n":"No\n");
    }
}