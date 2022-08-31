#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
    int x, p;
    bool operator<(const point &p)const{
        return x<p.x;
    }
}w[201000];
int n, L, m, st[200100], top, Next[201000], F, Mn, Mx;
long long Res;
int main(){
    int i, t, tt;
    scanf("%d%d%d",&L,&m,&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].p);
    }
    sort(w+1,w+n+1);
    for(i=n;i>=1;i--){
        while(top && w[st[top]].p >= w[i].p)top--;
        if(top)Next[i] = st[top];
        st[++top] = i;
    }
    F = m;
    for(i=1;i<=n;i++){
        t = w[i].x-w[i-1].x;
        F-=t;
        if(F<0){
            printf("-1\n");
            return 0;
        }
        tt = min(m-F,L-w[i].x-F);
        if(!Next[i] || w[Next[i]].x - w[i].x >= tt+F){
            Res += (long long)tt*w[i].p;
            F += tt;
        }
        else{
            if(F < w[Next[i]].x - w[i].x){
                Res += (long long)(w[Next[i]].x - w[i].x - F)*w[i].p;
                F = w[Next[i]].x - w[i].x;
            }
        }
    }
    if(F<L-w[n].x)printf("-1\n");
    else printf("%lld\n",Res);
}