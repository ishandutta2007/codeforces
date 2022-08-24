#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define double long double
int n;
long long K;
struct point{
    double x, y;
    double SZ(){
        return sqrtl(x*x+y*y);
    }
}w[101000];
const double PI = acosl(-1.0);
void Go(double &t){
    while(t<-PI)t+=PI*2;
    while(t>PI)t-=PI*2;
}
struct AA{
    double d;
    int num;
    bool operator <(const AA &p)const{
        return d<p.d;
    }
}U[201000];
int BB[101000][2], CC[101000];
int BIT[201000];
void init(){
    for(int i=0;i<201000;i++)BIT[i]=0;
}
void Add(int a, int b){
    a++;
    while(a<201000){
        BIT[a]+=b;
        a+=(a&-a);
    }
}
int Sum(int a){
    a++;
    int r=0;
    while(a){
        r+=BIT[a];
        a-=(a&-a);
    }
    return r;
}
long long Get(double r){
    int i;
    int c =0 ;
    for(i=1;i<=n;i++){
        double d = w[i].SZ();
        if(d<=r)continue;
        double an = atan2l(w[i].y,w[i].x);
        double z = acosl(r/d);
        double b = an-z, e = an+z;
        Go(b);
        Go(e);
        U[c++]={b,i};
        U[c++]={e,i};
    }
    sort(U,U+c);
    for(i=1;i<=n;i++)CC[i]=0;
    for(i=0;i<c;i++){
        BB[U[i].num][CC[U[i].num]++] = i;
    }
    init();
    long long s = 0;
    for(i=0;i<c;i++){
        int x = U[i].num;
        if(BB[x][0]==i){
            s += Sum(BB[x][1])-Sum(i);
            Add(BB[x][1], 1);
        }
    }
    return 1ll*n*(n-1)/2 - s;
}
void Solve(){
    int i, j;
    scanf("%d%lld",&n,&K);
    for(i=1;i<=n;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        w[i].x=x,w[i].y=y;
    }
    double b = 0.0, e = 1e5;
    for(i=0;i<50;i++){
        double mid = (b+e)*0.5;
        if(Get(mid)>=K){
            e=mid;
        }
        else b=mid;
    }
    printf("%.10Lf\n",(b+e)*0.5);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}