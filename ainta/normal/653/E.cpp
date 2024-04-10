#include<stdio.h>
#include<algorithm>
using namespace std;
int UF[301000], Deg[301000], n, K, m;
int w[301000][2];
bool chk[301000], v[301000], v2[301000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
void Merge(int a, int b){
    a = Find(a), b = Find(b);
    if(a!=b)UF[a]=b;
}
int main(){
    int i, j, x;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++)UF[i]=i;
    for(i=1;i<=m;i++){
        scanf("%d%d",&w[i][0],&w[i][1]);
        if(w[i][0]==1||w[i][1]==1)continue;
        Deg[w[i][0]]++,Deg[w[i][1]]++;
    }
    for(i=2;i<=n;i++){
        if(Deg[i]*2 >= n-1){
            chk[i] = true;
            for(j=1;j<=m;j++){
                if(w[j][0]!=1 && w[j][1]!=1){
                    if(w[j][0]==i||w[j][1]==i)v[w[j][0]]=v[w[j][1]]=true;
                }
            }
            for(j=2;j<=n;j++){
                if(j!=i && !v[j]){
                    Merge(i,j);
                }
                v[j]=false;
            }
        }
    }
    for(i=2;i<=n;i++)if(!chk[i])break;
    x = i;
    if(x!=n+1){
        for(i=2;i<=n;i++){
            if(!chk[i])Merge(x,i);
        }
    }
    for(i=1;i<=n;i++)v[i]=false;
    for(i=1;i<=m;i++){
        if(w[i][0]==1||w[i][1]==1){
            Deg[w[i][0]]++,Deg[w[i][1]]++;
            v[w[i][0]]=v[w[i][1]]=true;
        }
    }
    if(n - 1 - Deg[1] < K){
        printf("impossible\n");
        return 0;
    }
    int cc = 0;
    for(i=2;i<=n;i++){
        if(!v[i]){
            if(!v2[Find(i)]){
                cc++;
                v2[Find(i)] = true;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(!v2[Find(i)])break;
    }
    if(i!=n+1 || cc > K){
        printf("impossible\n");
        return 0;
    }
    printf("possible\n");
}