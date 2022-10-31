#include<cstdio>
#include<cmath>
#define N 1010
using namespace std;
double r[N],p[N][N],d[N];
bool del[N];
bool one(double x){
    return fabs(x-1)<1e-7;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++) d[i]=1e10,r[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lf",&p[i][j]);
            p[i][j]/=100;
        }
    }
    d[n]=0;
    for(int i=1;i<=n;i++){
        int now=-1;
        for(int j=1;j<=n;j++){
            if(del[j]) continue;
            if(now==-1||d[j]<d[now]) now=j;
        }
        del[now]=true;
        for(int j=1;j<=n;j++){
            if(del[j]) continue;
            double nr=r[j]*(1-p[j][now]);
            if(one(r[j])) d[j]=0;
            else d[j]-=1/(1-r[j]);
            d[j]=(d[j]*(1-r[j])+p[j][now]*r[j]*d[now]+1)/(1-nr);
            r[j]=nr;
        }
    }
    printf("%.12f\n",d[1]);
    return 0;
}