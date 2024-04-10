#include<stdio.h>
#include<algorithm>
using namespace std;
int w[510][510], n, m, C[510];
void DFS(int a, int ck){
    int i;
    C[a] = ck;
    for(i=1;i<=n;i++){
        if(!C[i] && w[a][i]){
            DFS(i,3-ck);
        }
    }
}
int main(){
    int a, b, i, j, chk = 0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j)w[i][j]=1;
        }
    }
    while(m--){
        scanf("%d%d",&a,&b);
        w[a][b]=w[b][a]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(w[i][j]==1)break;
        }
        if(j!=n+1)break;
    }
    if(i!=n+1){
        DFS(i,1);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(w[i][j]==0 && C[i]+C[j]==3)chk = 1;
                if(w[i][j]==1 && C[i]+C[j]!=3)chk = 1;
            }
        }
    }
    if(chk){
        printf("No\n");
    }
    else{
        printf("Yes\n");
        for(i=1;i<=n;i++){
            if(C[i]==1)printf("a");
            else if(C[i]==2)printf("c");
            else printf("b");
        }
    }
}