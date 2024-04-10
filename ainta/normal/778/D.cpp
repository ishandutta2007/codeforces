#include<cstdio>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
int w[60][60], cnt, ck, n, m;
char p[60][60], q[60][60];
bool v[60][60];
bool Check(int x, int y){
    if(x<1||x>=n||y<1||y>=m)return false;
    if(w[x][y]==w[x+1][y] && w[x][y+1]==w[x+1][y+1])return true;
    if(w[x][y]==w[x][y+1] && w[x+1][y]==w[x+1][y+1])return true;
    return false;
}
int C[2];
pii Ans[2][101000];
void Make(int x, int y, int ck){
    swap(w[x+1][y],w[x][y+1]);
    Ans[ck][C[ck]++] = {x,y};
}
void Do(int chk){
    int i, j;
    while(1){
        int ck = 0;
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)v[i][j]=false;
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(Check(i,j)&&!v[i][j]&&!v[i][j+1]){
                    v[i][j]=v[i+1][j]=v[i][j+1]=v[i+1][j+1]=true;
                    Make(i,j,chk);
                }
                else if((i&1) && (j&1)) ck = 1;
            }
        }
        if(!ck)break;
    }
    for(i=1;i<n;i+=2){
        for(j=1;j<m;j+=2){
            if(w[i][j]!=w[i][j+1])Make(i,j,chk);
        }
    }
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
        for(j=1;j<=m;j++){
            if(p[i][j]=='L')w[i][j] = w[i][j+1] = ++cnt;
            if(p[i][j]=='U')w[i][j] = w[i+1][j] = ++cnt;
        }
    }
    Do(0);
    cnt = 0;
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
        for(j=1;j<=m;j++){
            if(p[i][j]=='L')w[i][j] = w[i][j+1] = ++cnt;
            if(p[i][j]=='U')w[i][j] = w[i+1][j] = ++cnt;
        }
    }
    Do(1);
    printf("%d\n",C[0]+C[1]);
    for(i=0;i<C[0];i++)printf("%d %d\n",Ans[0][i].first, Ans[0][i].second);
    for(i=C[1]-1;i>=0;i--)printf("%d %d\n",Ans[1][i].first, Ans[1][i].second);
}