#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
#define N_ 301000
using namespace std;
int n, rx, ry;
struct point{
    int x, y;
}w[301000];
char p[501000];
bool Pos(int K){
    int i;
    int mx=-1e9,Mx=1e9, my=-1e9,My=1e9, mxy = -1e9, Mxy=1e9;
    for(i=1;i<=n;i++){
        Mxy=min(Mxy,w[i].x-w[i].y+K);
        mxy=max(mxy,w[i].x-w[i].y-K);
        Mx = min(Mx, w[i].x+K);
        mx = max(mx, w[i].x-K);
        My = min(My, w[i].y+K);
        my = max(my, w[i].y-K);
    }
    if(Mxy<mxy||Mx<mx||My<my)return false;
    for(i=mx;i<=Mx;i++){
        rx = i, ry = My;
        if(mxy<=rx-ry && rx-ry<=Mxy)return true;
    }
    for(i=My;i>=my;i--){
        rx = Mx, ry = i;
        if(mxy<=rx-ry && rx-ry<=Mxy)return true;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    int i, j;
    for(i=1;i<=n;i++){
        scanf("%s",p);
        for(j=0;p[j];j++){
            if(p[j]=='B')w[i].x++;
            else w[i].y++;
        }
    }
    int b = 0, e = 1e6, mid, r=1e6;
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid)){
            r=mid;
            e=mid-1;
        }
        else b=mid+1;
    }
    Pos(r);
    printf("%d\n",r);
    for(i=0;i<rx;i++)printf("B");
    for(i=0;i<ry;i++)printf("N");
    puts("");
}