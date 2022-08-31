#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Num[101000],C1,C2;
vector<int>E[101000];
void DFS(int a, int c){
    Num[a] = c;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!Num[E[a][i]]){
            DFS(E[a][i],3-c);
        }
    }
}
int main(){
    int i, a, b, j, ck = 0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!Num[i]){
            DFS(i,1);
        }
    }
    for(i=1;i<=n;i++){
        if(Num[i]==1)C1++;
        if(Num[i]==2)C2++;
        for(j=0;j<E[i].size();j++){
            if(Num[i] + Num[E[i][j]]!=3)ck=1;
        }
    }
    if(ck)printf("-1\n");
    else{
        printf("%d\n",C1);
        for(i=1;i<=n;i++)if(Num[i]==1)printf("%d ",i);
        printf("\n");
        printf("%d\n",C2);
        for(i=1;i<=n;i++)if(Num[i]==2)printf("%d ",i);
        printf("\n");
    }
}