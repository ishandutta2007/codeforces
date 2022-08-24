#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int c, a, b;
    bool operator<(const point &p)const{
        return b-a<p.b-p.a;
    }
}w[101000], ww[101000];
int n, S;
long long sum, R1;
void Calc(long long c1, long long c2){
    if(c1<0||c2<0)return;
    c1*=S,c2*=S;
    long long ss = 0;
    int i;
    for(i=1;i<=n;i++)ww[i]=w[i];
    for(i=1;i<=n;i++){
        if(w[i].a > w[i].b){
            if(c1 >= w[i].c){
                ss += 1ll*w[i].c*w[i].a;
                c1 -= w[i].c;
                w[i].c = 0;
            }
            else{
                ss += 1ll*c1*w[i].a;
                w[i].c -= c1;
                c1 = 0;
            }
        }
    }
    for(i=n;i>=1;i--){
        if(w[i].a < w[i].b){
            if(c2 >= w[i].c){
                ss += 1ll*w[i].c*w[i].b;
                c2 -= w[i].c;
                w[i].c = 0;
            }
            else{
                ss += 1ll*c2*w[i].b;
                w[i].c -= c2;
                c2 = 0;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(c1){
            ss += 1ll*w[i].a*w[i].c;
        }
        else{
            ss += 1ll*w[i].b*w[i].c;
        }
    }
    R1 = max(R1, ss);
    for(i=1;i<=n;i++)w[i]=ww[i];
}
int main(){
    scanf("%d%d",&n,&S);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&w[i].c,&w[i].a,&w[i].b);
        sum += w[i].c;
    }
    long long C = (sum+S-1)/S, ss = 0;
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++)if(w[i].a <= w[i].b)break;
    int x = i;
    for(i=1;i<x;i++)ss += w[i].c;
    for(i=-5;i<=5;i++){
        Calc(ss/S+i,C-ss/S-i);
    }
    printf("%lld\n",R1);
}