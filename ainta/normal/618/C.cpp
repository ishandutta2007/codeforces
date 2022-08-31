#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct point{
    long long x,y;
}w[101000];
long long dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
long long ccw(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int n, res[3];
long long MM;
double Mn;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld%lld",&w[i].x,&w[i].y);
    res[0] = 1;
    for(i=2;i<=n;i++){
        if(i==2){
            MM = dist(w[1],w[i]);
            res[1] = i;
        }
        else{
            if(MM>dist(w[1],w[i])){
                MM=dist(w[1],w[i]);
                res[1] = i;
            }
        }
    }
    Mn = 1e15;
    double t;
    for(i=1;i<=n;i++){
        if(i==res[0]||i==res[1])continue;
        t = sqrt((double)dist(w[1],w[i])) + sqrt((double)dist(w[i],w[res[1]]));
        if(Mn>t && ccw(w[1],w[i],w[res[1]])!=0){
            Mn=t;
            res[2] = i;
        }
    }
    for(i=0;i<3;i++)printf("%d ",res[i]);
}