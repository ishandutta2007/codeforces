#include<cstdio>
#include<cstring>
#define N 510
#define inf 1023456789
using namespace std;
int len[N][N]={0};
int ori[N][N]={0};
int pass[N][N]={0};
int main(){
     int n,m,i,j,k,x,y,l,a[N],b[N],ans=0;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            len[i][j]=inf;
        }
        len[i][i]=0;
    }
     while(m--){
        scanf("%d%d%d",&x,&y,&l);
        len[x][y]=len[y][x]=ori[x][y]=ori[y][x]=l;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j==i) continue;
            for(k=1;k<=n;k++){
                if(k==i||k==j) continue;
                if(len[j][i]+len[i][k]<len[j][k]){
                    len[j][k]=len[j][i]+len[i][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j==i) continue;
            for(k=1;k<=n;k++){
                if(k==j) continue;
                if(ori[k][j]&&len[i][k]+ori[k][j]==len[i][j]) pass[i][j]++;
            }
        }
    }
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            ans=0;
            for(k=1;k<=n;k++){
                if(len[i][k]+len[k][j]==len[i][j]) ans+=pass[i][k];
            }
            printf("%d",ans);
            if(i==n-1&&j==n) putchar('\n');
            else putchar(' ');
        }
    }
    return 0;
}