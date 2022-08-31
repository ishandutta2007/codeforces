#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
struct point{
    long long x, y, z;
}w[1010];
point Seg(point a, point b){
    return {b.y-a.y, a.x-b.x, a.y*b.x-a.x*b.y};
}
double Dist(point a, point b, point c){
    point tp = Seg(a,b);
    double t = (tp.x*c.x + tp.y*c.y + tp.z)/ sqrt(tp.x*tp.x+tp.y*tp.y);
    return t<0?-t:t;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&w[i].x,&w[i].y);
    }
    w[n]=w[0],w[n+1]=w[1];
    double res = 1e18;
    for(i=1;i<=n;i++){
        res = min(res, Dist(w[i-1], w[i+1], w[i])/2);
    }
    printf("%.10f\n",res);
}