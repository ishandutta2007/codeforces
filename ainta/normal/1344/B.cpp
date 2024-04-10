#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
char p[1010][1010];
int w[1010][1010], vis[1010][1010];
void DFS(int x, int y){
    if(!w[x][y])return;
    vis[x][y]=1;
    if(!vis[x+1][y])DFS(x+1,y);
    if(!vis[x-1][y])DFS(x-1,y);
    if(!vis[x][y+1])DFS(x,y+1);
    if(!vis[x][y-1])DFS(x,y-1);
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
    }
    int ck=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(p[i][j]=='#')w[i][j]=1,ck=1;
        }
    }
    if(!ck){
        puts("0");
        return 0;
    }
    int c1=0,c2=0;
    for(i=1;i<=n;i++){
        int c=0;
        for(j=1;j<=m;j++){
            if(w[i][j-1]==0 && w[i][j]==1){
                c++;
            }
        }
        if(c>=2){
            puts("-1");
            return 0;
        }
        if(c==0)c1++;
    }
    for(i=1;i<=m;i++){
        int c=0;
        for(j=1;j<=n;j++){
            if(w[j-1][i]==0 && w[j][i]==1){
                c++;
            }
        }
        if(c>=2){
            puts("-1");
            return 0;
        }
        if(c==0)c2++;
    }
    if((!c1)!=(!c2)){
        puts("-1");
        return 0;
    }
    int res=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!vis[i][j] && w[i][j]==1){
                DFS(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
}