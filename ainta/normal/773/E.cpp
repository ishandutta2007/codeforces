#include<cstdio>
#include<algorithm>
#define SZ 1048576
#define BS 524288
using namespace std;
int n;
struct Tree{
    int M, K;
}IT[SZ+SZ];
int TT[SZ+SZ];
void init(int nd, int b, int e){
    if(b==e){
        IT[nd].M = b-BS;
        return;
    }
    int m = (b+e)>>1;
    init(nd*2, b, m);
    init(nd*2+1, m+1, e);
    IT[nd].M = min(IT[nd*2].M, IT[nd*2+1].M);
}
void Add(int nd, int x){
    IT[nd].K += x;
    IT[nd].M += x;
}
void Spread(int nd){
    Add(nd*2, IT[nd].K);
    Add(nd*2+1, IT[nd].K);
    IT[nd].K = 0;
}
void Ins(int nd, int b, int e, int s, int l, int x){
    if(b==s && e==l){
        Add(nd, x);
        return;
    }
    int m = (b+e)>>1;
    Spread(nd);
    if(s<=m)Ins(nd*2,b,m,s,min(m,l),x);
    if(l>m)Ins(nd*2+1,m+1,e,max(m+1,s),l,x);
    IT[nd].M = min(IT[nd*2].M, IT[nd*2+1].M);
}
void Ins2(int a){
    a+=SZ;
    while(a){
        TT[a]++;
        a>>=1;
    }
}
int Find(){
    int nd = 1, b = 0, e = SZ-1, c = 0, m;
    while(nd < SZ){
        m=(b+e)>>1;
        nd*=2;
        if(c + TT[nd] < -(m-BS)){
            c += TT[nd];
            nd++;
            b = m+1;
        }
        else e = m;
    }
    return -(nd-SZ-BS);
}
int Min(int nd, int b, int e, int s, int l){
    if(b==s&&e==l)return IT[nd].M;
    Spread(nd);
    int r = 1e9;
    int m = (b+e)>>1;
    if(s<=m)r = min(r, Min(nd*2,b,m,s,min(m,l)));
    if(l>m)r = min(r, Min(nd*2+1,m+1,e,max(m+1,s),l));
    return r;
}
int main(){
    int i, a;
    scanf("%d",&n);
    init(1, 0, SZ-1);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        Ins(1, 0, SZ-1, BS+a, SZ-1, -1);
        Ins2(BS+a);
        int x = Find();
//        printf("%d\n",x);
        int M = min(-x*2, Min(1, 0, SZ-1, -x+BS, SZ-1));
        printf("%d\n",M+i);
    }
}