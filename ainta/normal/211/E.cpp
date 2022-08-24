#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[5010], D[5010], chk[5010];
vector<int>E[5010];
void DFS(int a, int pp){
    C[a]=1;
    int i, j;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            DFS(E[a][i],a);
            C[a]+=C[E[a][i]];
        }
    }
    for(i=0;i<=n;i++)D[i] = 0;
    D[0]=1;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]==pp)continue;
        int x = C[E[a][i]];
        for(j=C[a];j>=0;j--){
            if(D[j])D[j+x]=1;
        }
    }
    int x = n - C[a];
    for(j=C[a];j>=0;j--){
        if(D[j])D[j+x]=1;
    }
    for(i=0;i<=n;i++)chk[i]|=D[i];
}
int main(){
    int i, a, b, res = 0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    for(i=1;i<n-1;i++){
        if(chk[i])res++;
    }
    printf("%d\n",res);
    for(i=1;i<n-1;i++){
        if(chk[i])printf("%d %d\n",i,n-1-i);
    }
}