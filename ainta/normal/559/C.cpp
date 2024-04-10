#include<stdio.h>
#include<algorithm>
using namespace std;
int H, W, n;
struct point{
    int x, y;
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}w[2010];
long long Mod = 1000000007, F[201000], InvF[201000], D[2010], Res;
long long Inv(long long a)
{
    long long r = 1, b = Mod - 2;
    while(b){
        if(b%2==1)r =r*a%Mod;
        a=a*a%Mod;
        b/=2;
    }
    return r;
}
long long Comb(int a, int b){
    return F[a]* InvF[b]%Mod*InvF[a-b]%Mod;
}
int main(){
    int i, j;
    scanf("%d%d%d",&H,&W,&n);
    F[0] = 1;
    for(i=1;i<=H+W;i++){
        F[i] = F[i-1]*i%Mod;
    }
    for(i=0;i<=H+W;i++)InvF[i] = Inv(F[i]);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        D[i] = Comb(w[i].x-1+w[i].y-1, w[i].x-1);
        for(j=1;j<i;j++){
            if(w[j].x > w[i].x || w[j].y > w[i].y)continue;
            D[i] -= D[j] * Comb(w[i].x-w[j].x+w[i].y-w[j].y, w[i].x-w[j].x) % Mod;
            D[i] = (D[i] + Mod)%Mod;
        }
    }
    Res = Comb(H-1+W-1,W-1);
    for(i=1;i<=n;i++){
        Res = (Res + Mod - D[i] * Comb(H - w[i].x + W - w[i].y, H - w[i].x)%Mod)%Mod;
    }
    printf("%lld\n",Res);
}