#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 131072
using namespace std;
struct SegTree{
    int LM, RM, MM;
}IT[SZ+SZ+2];
int n, Res[101000];
struct point{
    int h, x;
    bool operator<(const point &p)const{
        return h<p.h;
    }
}w[101000];
struct Query{
    int b, e, x, num;
};
void UDT(int nd, int b, int e, int m){
    int c1 = nd+nd, c2 = nd+nd+1;
    if(IT[c1].LM != m-b+1)IT[nd].LM = IT[c1].LM;
    else IT[nd].LM = IT[c1].LM + IT[c2].LM;
    if(IT[c2].RM != e-m)IT[nd].RM = IT[c2].RM;
    else IT[nd].RM = IT[c2].RM + IT[c1].RM;
    IT[nd].MM = max(max(IT[c1].MM,IT[c2].MM),IT[c1].RM + IT[c2].LM);
}
void Ins(int nd, int b, int e, int x, int k){
    if(b==e){
        IT[nd].LM+=k;
        IT[nd].RM+=k;
        IT[nd].MM+=k;
        return;
    }
    int m = (b+e)>>1;
    if(x<=m)Ins(nd*2,b,m,x,k);
    else Ins(nd*2+1,m+1,e,x,k);
    UDT(nd, b, e, m);
}
SegTree Get(int nd, int b, int e, int s, int l){
    if(b==s && e==l)return IT[nd];
    int m = (b+e)>>1;
    SegTree r, tp, tp2;
    r.MM=r.LM=r.RM=0;
    if(s<=m){
        tp = Get(nd*2,b,m,s,min(m,l));
        if(l<=m)r=tp;
    }
    if(l>m){
        tp2 = Get(nd*2+1,m+1,e,max(m+1,s),l);
        if(s>m)r=tp2;
    }
    if(s<=m && l>m){
        r.MM = max(max(tp.MM,tp2.MM),tp.RM+tp2.LM);
        if(tp.LM == m-b+1) r.LM = tp.LM + tp2.LM;
        else r.LM = tp.LM;
        if(tp2.RM == e-m) r.RM = tp2.RM + tp.RM;
        else r.RM = tp2.RM;
    }
    return r;
}
bool Chk(Query tp){
    if(Get(1, 1, n, tp.b, tp.e).MM >= tp.x)return true;
    return false;
}
void Do(int b, int e, vector<Query> A){
    if(b>e)return;
    int m = (b+e)>>1, i;
    for(i=m;i<=e;i++){
        Ins(1, 1, n, w[i].x, 1);
    }
    vector<Query> V1, V2;
    for(int i=0;i<A.size();i++){
        if(Chk(A[i])){
            V1.push_back(A[i]);
            Res[A[i].num] = w[m].h;
        }
        else V2.push_back(A[i]);
    }
    if(b==e){
        for(i=m;i<=e;i++){
            Ins(1, 1, n, w[i].x, -1);
        }
        return;
    }
    Do(b,m-1,V2);
    for(i=m;i<=e;i++){
        Ins(1, 1, n, w[i].x, -1);
    }
    Do(m+1,e,V1);
}
int main(){
    int i, CQ;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i].h);
        w[i].x = i;
    }
    scanf("%d",&CQ);
    vector<Query>Q(CQ);
    Query tp;
    for(i=0;i<CQ;i++){
        scanf("%d%d%d",&tp.b,&tp.e,&tp.x);
        tp.num=i;
        Q[i] = tp;
    }
    sort(w+1,w+n+1);
    Do(1,n,Q);
    for(i=0;i<CQ;i++)printf("%d\n",Res[i]);
}