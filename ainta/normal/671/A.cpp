#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct point{
    int x, y;
}w[101000], A, B, T;
double dist(point a, point b){
    return sqrt(((double)a.x-b.x)*(a.x-b.x) +((double)a.y-b.y)*(a.y-b.y));
}
int n;
double Mx1, Mx2, Mx3, Mx4, Res, SS, S1;
int x1, x2, x3, x4;
int main()
{
    int i;
    double t1, t2;
    scanf("%d%d%d%d%d%d",&A.x,&A.y,&B.x,&B.y,&T.x,&T.y);
    Mx1 = Mx2 = Mx3 = Mx4 = -1e13;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
        t1 = dist(T,w[i]) - dist(A,w[i]);
        t2 = dist(T,w[i]) - dist(B,w[i]);
        if(Mx1<t1){
            Mx2 = Mx1; x2 = x1;
            Mx1 = t1; x1 = i;
        }
        else if(Mx2<t1){
            Mx2 = t1; x2 = i;
        }
        if(Mx3<t2){
            Mx4 = Mx3; x4 = x3;
            Mx3 = t2; x3 = i;
        }
        else if(Mx4<t2){
            Mx4 = t2; x4 = i;
        }
    }
    for(i=1;i<=n;i++){
        S1 += dist(T,w[i])*2;
    }
    Res = min(S1 - Mx1, S1 - Mx3);
    if(x1 != x3){
        Res = min(Res, S1 - Mx1 - Mx3);
    }
    else{
        Res = min(Res, S1 - Mx1 - Mx4);
        Res = min(Res, S1 - Mx2 - Mx3);
    }
    printf("%.10lf\n",Res);
}