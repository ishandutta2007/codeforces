#include<stdio.h>
#include<algorithm>
#define SZ 131072
using namespace std;
struct point{
    int x, y;
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}w[101000];
int n;
long long Res = 1e18;
struct IdxTree{
    int Mn, Mx;
}IT[SZ+SZ+2];
void Ins(int a, int y){
    a+=SZ;
    IT[a].Mx = IT[a].Mn = y;
    while(a!=1){
        a>>=1;
        IT[a].Mx = max(IT[a*2].Mx,IT[a*2+1].Mx);
        IT[a].Mn = min(IT[a*2].Mn,IT[a*2+1].Mn);
    }
}
IdxTree Get(int b, int e){
    IdxTree r;
    r.Mn=r.Mx=0;
    b+=SZ,e+=SZ;
    while(b<=e){
        r.Mn=min(r.Mn,IT[b].Mn);
        r.Mn=min(r.Mn,IT[e].Mn);
        r.Mx=max(r.Mx,IT[b].Mx);
        r.Mx=max(r.Mx,IT[e].Mx);
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
void Do(){
    long long be = 0, ed = 1e18, mid, pv, Mx, Mn, MM, t1, t2;
    int i;
    IdxTree tp, tp2;
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        Ins(i, w[i].y);
    }
    while(be<=ed){
        mid = (be+ed)/2;
        pv = 1;
        for(i=1;i<=n;i++){
            while(pv<n && ((long long)w[pv+1].x-w[i].x)*(w[pv+1].x-w[i].x) <= mid){
                pv++;
            }
            if(i==1 && pv == n)break;
            tp = Get(1,i-1);
            tp2 = Get(pv+1, n);
            Mx = max(tp.Mx, tp2.Mx);
            Mn = min(tp.Mn, tp2.Mn);
            t1 = max(abs(Mx),abs(Mn));
            t2 = max(abs(w[pv].x), abs(w[i].x));
            MM = max((Mx-Mn)*(Mx-Mn), t1*t1+t2*t2);
            if(MM<=mid)break;
        }
        if(i!=n+1){
            if(Res>mid)Res=mid;
            ed = mid - 1;
        }
        else{
            be = mid + 1;
        }
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
    }
    Do();
    for(i=1;i<=n;i++){
        w[i].x = -w[i].x;
    }
    Do();
    for(i=1;i<=n;i++){
        swap(w[i].x,w[i].y);
    }
    Do();
    for(i=1;i<=n;i++){
        w[i].x = -w[i].x;
    }
    Do();
    printf("%lld\n",Res);
}