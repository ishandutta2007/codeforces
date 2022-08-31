#include<stdio.h>
#include<algorithm>
#define INF 1999999999
#define SZ 262144
using namespace std;
struct Order{
    int x, y, num;
    bool operator<(const Order &p)const{
        return x!=p.x?x<p.x:y!=p.y?y<p.y:num<p.num;
    }
}ord[201000];
int n, Q[101000], head, tail, D[101000], Path[101000];
struct A{
    int x1,y1,x2,y2;
}w[101000];
struct IdxTree{
    int Mn, num;
}IT[SZ+SZ+1];
void UDT(int nd){
    while(nd != 1){
        nd>>=1;
        if(IT[nd*2].Mn < IT[nd*2+1].Mn)IT[nd] = IT[nd*2];
        else IT[nd] = IT[nd*2+1];
    }
}
void Ins(int num, int x, int y){
    x+=SZ;
    IT[x].num = num, IT[x].Mn = y;
    UDT(x);
}
int Get(int b, int e){
    int Mn = INF, x = 0;
    b+=SZ,e+=SZ;
    while(b<=e){
        if(Mn>IT[b].Mn)Mn=IT[b].Mn, x = IT[b].num;
        if(Mn>IT[e].Mn)Mn=IT[e].Mn, x = IT[e].num;
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return x;
}
void Make(int x, int y, int p){
    int t;
    while(1){
        t = Get(1, x);
        if(t == 0 || w[t].y1 > y)break;
        Q[++tail] = t;
        Ins(0, w[t].x1, INF);
        D[t] = D[p] + 1;
        Path[t] = p;
    }
}
int Ans[101000], Ans_C;
int main(){
    int i, t, bb;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&ord[i].x,&ord[i].y,&ord[i+n].x,&ord[i+n].y);
        ord[i].num=i,ord[i+n].num=i+n;
    }
    sort(ord+1,ord+2*n+1);
    bb=-1;
    for(i=1;i<=2*n;i++){
        t = ord[i].num;
        if(ord[i].x != 0 && bb == -1)bb = i-1;
        if(t<=n){
            w[t].x1 = i, w[t].y1 = ord[i].y;
        }
        else{
            t-=n;
            w[t].x2 = i, w[t].y2 = ord[i].y;
        }
    }
    if(bb==-1)bb=2*n;
    for(i=1;i<SZ+SZ;i++)IT[i].Mn = INF;
    for(i=1;i<=n;i++){
        Ins(i, w[i].x1,w[i].y1);
    }
    Make(bb,0,0);
    while(head<tail){
        head++;
        t = Q[head];
        Make(w[t].x2, w[t].y2, t);
    }
    if(!D[n]){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",D[n]);
    t = n;
    while(t){
        Ans[++Ans_C] = t;
        t = Path[t];
    }
    for(i=Ans_C;i>=1;i--)printf("%d ",Ans[i]);
}