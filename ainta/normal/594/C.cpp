#include<stdio.h>
#include<algorithm>
#define INF 2000000000
using namespace std;
int n, K;
struct point{
    int x, y, num;
    bool operator<(const point &p)const{
        return x<p.x;
    }
}w[101000], w2[101000], ori[101000];
long long Res = 8999999999999999999LL;
bool v[101000];
int cnt;
void Do(){
    int i;
    long long mxx, mnx, mxy, mny, dx, dy, xx, yy;
    mxx=mxy=0;
    mnx=mny=INF;
    for(i=1;i<=n;i++){
        if(!v[i]){
            xx = ori[i].x, yy = ori[i].y;
            mxx = max(mxx,xx);
            mxy = max(mxy,yy);
            mnx = min(mnx,xx);
            mny = min(mny,yy);
        }
    }
    dx = (mxx-mnx+1)/2, dy = (mxy-mny+1)/2;
    if(dx<1)dx=1;
    if(dy<1)dy=1;
    Res = min(Res,dx*dy);
}
void DFS4(int a){
    int i, ww[12]={0}, cc=0;
    if(a==K){
        Do();
        return;
    }
    for(i=n;i>=1;i--){
        if(!v[w2[i].num]){
            v[w2[i].num]=true;
            ww[cc++] = w2[i].num;
            if(a+cc==K)break;
        }
    }
    Do();
    for(i=0;i<cc;i++)v[ww[i]]=false;
}
void DFS3(int a){
    int i, ww[12]={0}, cc=0;
    DFS4(a);
    for(i=1;i<=n;i++){
        if(!v[w2[i].num]){
            v[w2[i].num]=true;
            ww[cc++] = w2[i].num;
            if(a+cc>K)break;
            DFS4(a+cc);
        }
    }
    for(i=0;i<cc;i++)v[ww[i]]=false;
}
void DFS2(int a){
    int i, ww[12]={0}, cc=0;
    DFS3(a);
    for(i=n;i>=1;i--){
        if(!v[w[i].num]){
            v[w[i].num]=true;
            ww[cc++] = w[i].num;
            if(a+cc>K)break;
            DFS3(a+cc);
        }
    }
    for(i=0;i<cc;i++)v[ww[i]]=false;
}
void DFS1(int a){
    int i, ww[12]={0}, cc=0;
    DFS2(a);
    for(i=1;i<=n;i++){
        if(!v[w[i].num]){
            v[w[i].num]=true;
            ww[cc++] = w[i].num;
            if(a+cc>K)break;
            DFS2(a+cc);
        }
    }
    for(i=0;i<cc;i++)v[ww[i]]=false;
}
int main(){
    int i, j, k, l, ii,a,b,c,d;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        w[i].x=a+c,w[i].y=b+d;
        w[i].num = i;
        w2[i] = w[i];
        ori[i] = w[i];
        swap(w2[i].x,w2[i].y);
    }
    sort(w+1,w+n+1);
    sort(w2+1,w2+n+1);
    for(i=1;i<=n;i++)swap(w2[i].x,w2[i].y);
    DFS1(0);
    printf("%lld\n",Res);
}