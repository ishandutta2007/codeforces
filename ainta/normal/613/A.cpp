#include<stdio.h>
#include<algorithm>
#define PI 3.14159265359
using namespace std;
struct point{
    double x, y;
}w[101000], P;
int n;
long long Dis(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double Mn, Mx, t, A, B, C;
int main(){
    int i, x, y;
    scanf("%d%lf%lf",&n,&P.x,&P.y);
    for(i=0;i<n;i++){
        scanf("%lf%lf",&w[i].x,&w[i].y);
        t = Dis(w[i],P);
        if(i == 0 || Mn > t)Mn = t;
        if(i == 0 || Mx < t)Mx = t;
    }
    w[n] = w[0];
    for(i=0;i<n;i++){
        if((w[i+1].x-w[i].x)*(P.x-w[i].x)+(w[i+1].y-w[i].y)*(P.y-w[i].y)<=0)continue;
        if((w[i].x-w[i+1].x)*(P.x-w[i+1].x)+(w[i].y-w[i+1].y)*(P.y-w[i+1].y)<=0)continue;
        A = w[i].y - w[i+1].y;
        B = w[i+1].x - w[i].x;
        C = w[i].x*w[i+1].y - w[i].y*w[i+1].x;
        t = (A*P.x+B*P.y+C)*(A*P.x+B*P.y+C) / (A*A+B*B);
        Mn = min(Mn, t);
    }
    printf("%lf\n",(Mx-Mn)*PI);
}