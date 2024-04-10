#include<stdio.h>
int n, m, Q[4000100][2], h, t, i, j;
char p[2010][2010];
void Add(int a, int b){
    t++;
    Q[t][0]=a;
    Q[t][1]=b;
    p[a][b]='.';
}
bool Chk(int a, int b){
    if(p[a][b]=='.')return false;
    if(a==1||a==n||b==1||b==m)return false;
    int c = 0, c2 = 0;
    if(p[a+1][b]=='.'&&p[a][b+1]=='.'&&p[a+1][b+1]=='.')return true;
    if(p[a-1][b]=='.'&&p[a][b+1]=='.'&&p[a-1][b+1]=='.')return true;
    if(p[a+1][b]=='.'&&p[a][b-1]=='.'&&p[a+1][b-1]=='.')return true;
    if(p[a-1][b]=='.'&&p[a][b-1]=='.'&&p[a-1][b-1]=='.')return true;
    return false;
}
int main(){
    int x, a, b;
    scanf("%d%d",&n,&m);
    n+=2,m+=2;
    for(i=2;i<n;i++){
        scanf("%s",p[i]+2);
    }
    for(i=1;i<=n;i++)p[i][1]=p[i][m]='*';
    for(i=1;i<=m;i++)p[1][i]=p[n][i]='*';
    for(i=2;i<n;i++){
        for(j=2;j<m;j++){
            if(Chk(i,j)){
                Add(i,j);
            }
        }
    }
    int i, j;
    while(h<t){
        h++;
        a=Q[h][0],b=Q[h][1];
        for(i=-1;i<=1;i++)for(j=-1;j<=1;j++)if(Chk(a+i,b+j))Add(a+i,b+j);
    }
    for(i=1;i<=n;i++)p[i][1]=p[i][m]=0;
    for(i=1;i<=m;i++)p[1][i]=p[n][i]=0;
    for(i=2;i<n;i++){
        printf("%s\n",p[i]+2);
    }
}