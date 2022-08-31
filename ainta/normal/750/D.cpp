#include<stdio.h>
#include<algorithm>
using namespace std;
int w[1000][1000], cnt, Tcnt, n, Res;
int dx[8] = {1,1,1,0,-1,-1,-1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
bool v[1000][1000][8];
struct point{
    int x, y, d;
}P[1010000], TP[1010000];
void Ins(int x, int y, int d){
    if(v[x][y][d])return;
    Tcnt++;
    TP[Tcnt].x = x, TP[Tcnt].y = y, TP[Tcnt].d = d;
    v[x][y][d]=true;
}
void Col(int x, int y, int d, int z){
    int i;
    for(i=0;i<z;i++){
        x+=dx[d];
        y+=dy[d];
        w[500+x][500+y] = 1;
    }
    Ins(x,y,d);
}
int main(){
    int i, j, a;
    scanf("%d",&n);
    cnt=1;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(i==1){
            for(j=1;j<=a;j++){
                w[500][500+j] = 1;
            }
            Ins(0,a,3);
        }
        else{
            for(j=1;j<=cnt;j++){
                Col(P[j].x,P[j].y,(P[j].d+1)%8, a);
                Col(P[j].x,P[j].y,(P[j].d+7)%8, a);
            }
        }
        for(j=1;j<=Tcnt;j++){
            v[TP[j].x][TP[j].y][TP[j].d] = false;
            P[j] = TP[j];
        }
        cnt = Tcnt;
        Tcnt = 0;
    }
    for(i=0;i<1000;i++)for(j=0;j<1000;j++)if(w[i][j])Res++;
    printf("%d\n",Res);
}