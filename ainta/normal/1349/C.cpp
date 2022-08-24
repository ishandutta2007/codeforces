#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, m, v[1010][1010], cnt, C[1010000];
long long D[1010][1010];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct point{
    int x,y;
}Q[1010000], TQ[1010000];
int head, tail, nt;
char w[1010][1010];
int main(){
    int i, j, QC;
    scanf("%d%d%d",&n,&m,&QC);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)D[i][j]=2e18;
    for(i=1;i<=n;i++){
        scanf("%s",w[i]+1);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(j!=m && w[i][j]==w[i][j+1]){
                D[i][j]=D[i][j+1]=0;
            }
            if(i!=n && w[i][j]==w[i+1][j]){
                D[i][j]=D[i+1][j]=0;
            }
        }
    }
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(!D[i][j])Q[++tail]={i,j};
    for(int d=0;;d++){
        int c=0;
        for(i=1;i<=tail;i++){
            point t = Q[i];
            for(int j=0;j<4;j++){
                int tx = t.x+dx[j], ty=t.y+dy[j];
                if(tx<1||tx>n||ty<1||ty>m)continue;
                if(D[tx][ty]>D[t.x][t.y]+1){
                    D[tx][ty]=D[t.x][t.y]+1;
                    TQ[++c] = {tx,ty};
                }
            }
        }
        tail=c;
        for(i=1;i<=c;i++)Q[i]=TQ[i];
        if(!tail)break;
    }
    while(QC--){
        int x,y;
        long long t;
        scanf("%d%d%lld",&x,&y,&t);
        int z = w[x][y]-'0';
        if(D[x][y]<t){
            if((t-D[x][y])%2)z^=1;
        }
        printf("%d\n",z);
    }
}