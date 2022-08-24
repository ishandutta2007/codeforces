#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[5010], X[5010], pv, Num[5010];
long long A[5010], B[5010];
struct point{
    int x,num;
    bool operator<(const point &p)const{
        return x<p.x;
    }
}ord[5010];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&w[i]);
        w[i]-=i;
        ord[i].x=w[i],ord[i].num = i;
    }
    sort(ord+1,ord+n+1);
    for(i=1;i<=n;i++){
        X[i] = ord[i].x;
        Num[ord[i].num] = i;
    }
    for(i=1;i<=n+1;i++){
        long long MM = 9e18, t;
        for(j=1;j<=n;j++){
            t = X[j]*A[j]+B[j];
            if(MM>t)MM=t,pv=j;
        }
        if(i==n+1){
            printf("%lld\n",MM);
        }
        int x = Num[i];
        if(x <= pv){
            for(j=0;j<x;j++){
                A[j] -= 1;
                B[j] += w[i];
            }
            for(j=x;j<pv;j++){
                A[j] += 1;
                B[j] -= w[i];
            }
            t = A[pv-1]*X[pv]+B[pv-1];
            for(j=pv;j<=n;j++){
                A[j] = 1;
                B[j] = t - X[pv];
            }
        }
        else{
            for(j=0;j<pv;j++){
                A[j] -= 1;
                B[j] += w[i];
            }
            t = A[pv-1]*X[pv]+B[pv-1];
            for(j=pv;j<x;j++){
                A[j] = -1;
                B[j] = t + X[pv];
            }
            t = A[x-1]*X[x]+B[x-1];
            for(j=x;j<=n;j++){
                A[j] = 1;
                B[j] = t - X[x];
            }
        }
    }
}