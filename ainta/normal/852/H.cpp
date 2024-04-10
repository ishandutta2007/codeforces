#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
    int x, y;
    bool operator <(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}P[260];
struct point2{
    int x, y;
    bool operator <(const point2 &p)const{
        return 1ll*y*p.x < 1ll*p.y*x;
    }
}w[260];
int ccw(point2 &a, point2 &b, point2 &c){
    long long t = 1ll*(b.x-a.x)*(c.y-a.y) - 1ll*(b.y-a.y)*(c.x-a.x);
    return t>0?1:t<0?-1:0;
}
int Pos[260][260], K;
long long res;
long long D[260][260][60], Area[260][260], R[260];
long long Calc(point2 a, point2 b){
    long long t = 1ll*a.x*b.y - 1ll*a.y*b.x;
    if(t<0)t=-t;
    return t;
}
int chk1[260], chk2[260];
void UDT(int x, int y){
    int i;
    for(i=1;i<=K;i++){
        R[i] = max(R[i], D[x][y][i]);
    }
}
void Do(int n){
    if(n+1<K)return;
    int i, j, k;
    sort(w+1,w+n+1);
    for(i=0;i<=n;i++)for(j=i;j<=n;j++)for(k=0;k<=K;k++)D[i][j][k]=-1e18;
    for(i=1;i<=n;i++)D[0][i][2] = 0;
    for(i=1;i<=n;i++){
        int pv = -1;
        for(j=i+1;j<=n;j++){
            if(pv == -1 || ccw(w[i], w[pv], w[j]) > 0)pv = j, Pos[i][j] = 1;
            else Pos[i][j] = 0;
            Area[i][j] = Calc(w[i],w[j]);
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<=K;j++)R[j] = -1e18;
        for(j=0;j<=n;j++)chk1[j]=chk2[j]=0;
        while(1){
            int pv = -1;
            for(j=i+1;j<=n;j++){
                if(!chk1[j] && Pos[i][j] && (pv==-1 || ccw(w[i], w[pv],w[j]) < 0))pv = j;
            }
            if(pv==-1)break;
            while(1){
                int pp= -1;
                if(!chk2[0]){
                    UDT(0,i);
                    chk2[0] = 1;
                    continue;
                }
                for(j=1;j<i;j++){
                    if(!chk2[j] && Pos[j][i] && (pp==-1 || ccw(w[i],w[pp],w[j]) < 0))pp = j;
                }
                if(pp == -1 || ccw(w[i],w[pp],w[pv]) > 0)break;
                UDT(pp,i);
                chk2[pp] = 1;
            }
            for(j=1;j<K;j++){
                D[i][pv][j+1] = max(D[i][pv][j+1], R[j] + Area[i][pv]);
            }
            chk1[pv] = 1;
        }
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(ccw(w[i],w[j],w[0]) > 0)res = max(res, D[i][j][K]);
        }
    }
}
int main(){
    int n;
    int i, j;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d%d",&P[i].x,&P[i].y);
    }
    sort(P+1,P+n+1);
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            w[j-i] = {P[j].x-P[i].x, P[j].y-P[i].y};
        }
        Do(n-i);
    }
    printf("%lld.%02d",res/2,res%2*50);
}