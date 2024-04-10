#include<stdio.h>
#include<algorithm>
#define INF 1000000000
using namespace std;
int n, Q;
struct SegTree{
    SegTree *c1, *c2;
    int M;
    SegTree(){
        c1=c2=NULL;
        M=0;
    }
};
SegTree *rootX, *rootY;
void Add(SegTree *nd, int t){
    nd->M=max(nd->M,t);
}
void spread(SegTree *nd){
    nd->c1->M=max(nd->c1->M, nd->M);
    nd->c2->M=max(nd->c2->M, nd->M);
}
void Ins(SegTree *nd, int b, int e, int s, int l, int t){
    if(b==s && e==l){
        Add(nd, t);
        return;
    }
    if(!nd->c1){
        nd->c1 = new SegTree();
        nd->c2 = new SegTree();
    }
    spread(nd);
    int m = (b+e)>>1;
    if(s <= m) Ins(nd->c1,b,m,s,min(m,l),t);
    if(m < l) Ins(nd->c2,m+1,e,max(m+1,s),l,t);
}
int Gap(SegTree *nd, int b, int e, int x){
    if(b==e)return nd->M;
    if(!nd->c1){
        nd->c1 = new SegTree();
        nd->c2 = new SegTree();
    }
    spread(nd);
    int m = (b+e)>>1;
    if(x<=m)return Gap(nd->c1,b,m,x);
    return Gap(nd->c2,m+1,e,x);
}
int main()
{
    int x, y, t;
    char p[2];
    scanf("%d%d",&n,&Q);
    rootX = new SegTree();
    rootY = new SegTree();
    while(Q--){
        scanf("%d%d",&y,&x);
        scanf("%s",p);
        if(p[0]=='L'){
            t = y - Gap(rootX, 1, INF, x);
            printf("%d\n",t);
            if(t){
                Ins(rootY, 1, INF, y-t+1, y, x);
                Ins(rootX, 1, INF, x, x, y);
            }
        }
        else{
            t = x - Gap(rootY, 1, INF, y);
            printf("%d\n",t);
            if(t){
                Ins(rootX, 1, INF, x-t+1, x, y);
                Ins(rootY, 1, INF, y, y, x);
            }
        }
    }
}