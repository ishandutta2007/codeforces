#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, ww[4][4], Q[1010000], h, t, D[3][1010][1010];
char p[1010][1010];
void Add(int pv, int x, int y, int d){
    if(p[x][y]!='.'&&(p[x][y]<'1'||p[x][y]>'3'))return;
    if(D[pv][x][y]<=d)return;
    D[pv][x][y]=d;
    Q[++t] = x*1010+y;
}
int main(){
    int i, j, k, x, y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
    }
    for(i=1;i<=3;i++)for(j=1;j<=3;j++)ww[i][j]=99999999;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(p[i][j]>='1'&&p[i][j]<='3'){
                if(p[i][j+1]>='1'&&p[i][j+1]<='3'){
                    ww[p[i][j]-'0'][p[i][j+1]-'0'] = 0;
                }
                if(p[i+1][j]>='1'&&p[i+1][j]<='3'){
                    ww[p[i][j]-'0'][p[i+1][j]-'0'] = 0;
                }
            }
        }
    }
    for(i=1;i<=3;i++)for(j=1;j<=3;j++)if(!ww[i][j])ww[j][i]=0;
    for(i=1;i<=3;i++){
        h=t=0;
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                D[i-1][j][k] = 99999999;
                if(p[j][k]=='0'+i){
                    Add(i-1,j,k,0);
                }
            }
        }
        while(h<t){
            h++;
            x = Q[h]/1010, y = Q[h]%1010;
            Add(i-1,x+1,y,D[i-1][x][y]+1);
            Add(i-1,x-1,y,D[i-1][x][y]+1);
            Add(i-1,x,y+1,D[i-1][x][y]+1);
            Add(i-1,x,y-1,D[i-1][x][y]+1);
        }
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                if(p[j][k]>='1'&&p[j][k]<='3'){
                    ww[i][p[j][k]-'0']=min(ww[i][p[j][k]-'0'],D[i-1][j][k]-1);
                }
            }
        }
    }
    int r = min(min(ww[1][2]+ww[1][3],ww[1][2]+ww[2][3]),ww[1][3]+ww[2][3]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(p[i][j]=='.'){
                r=min(r,D[0][i][j]+D[1][i][j]+D[2][i][j]-2);
            }
        }
    }
    printf("%d\n",r<=1000000?r:-1);
}