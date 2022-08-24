#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<set>
#define BSZ 400
#define SZ 150000
using namespace std;
struct SegTree{
    int S, K;
    SegTree *c1, *c2;
    SegTree(){
        S=K=0;
        c1=NULL,c2=NULL;
    }
};
SegTree *Root[151000];
int w[151000], D[410][410], n, Q, P, DF[410];
struct A{
    int b, e, c;
    A(){}
    A(int b_, int e_, int c_){
        b=b_,e=e_,c=c_;
    }
    bool operator<(const A &p)const{
        return b<p.b;
    }
};
set<A>Set;
void spreadB(int a){
    if(!DF[a])return;
    int i;
    for(i=0;i<BSZ;i++)D[a][i] = DF[a];
    DF[a]=0;
}
void InsB(int a, int b, int e, int x){
    int i;
    for(i=b;i<=e;i++)D[a][i] = x;
}
void Spread(SegTree *nd, int b, int e, int m){
    nd->c1->K += nd->K;
    nd->c2->K += nd->K;
    nd->c1->S += nd->K*(m-b+1);
    nd->c2->S += nd->K*(e-m);
    nd->K = 0;
}
void Ins(SegTree *nd, int b, int e, int s, int l, int x){
    if(b==s && e==l){
        nd->S+=(e-b+1)*x;
        nd->K+=x;
        return;
    }
    int m = (b+e)>>1;
    if(!nd->c1){
        nd->c1 = new SegTree();
        nd->c2 = new SegTree();
    }
    Spread(nd,b,e,m);
    if(s<=m) Ins(nd->c1, b, m, s, min(m,l),x );
    if(l>m) Ins(nd->c2, m+1, e, max(m+1,s), l, x);
    nd->S = nd->c1->S + nd->c2->S;
}
int Gap(SegTree *nd, int b, int e, int s, int l){
    if(!nd)return 0;
    if(b==s && e==l){
        return nd->S;
    }
    if(!nd->c1) return (l-s+1)*nd->K;
    int m = (b+e)>>1, r = 0;
    Spread(nd,b,e,m);
    if(s<=m) r += Gap(nd->c1, b, m, s, min(m,l));
    if(l>m) r += Gap(nd->c2, m+1, e, max(m+1,s), l);
    return r;
}
void Del(int b, int e, int c){
    Set.erase(A(b,e,c));
    if(!Root[c])Root[c] = new SegTree();
    Ins(Root[c], 1, SZ, b, e, -1);
}
void Make(int b, int e, int c){
    if(b>e)return;
    Set.insert(A(b,e,c));
    if(!Root[c])Root[c] = new SegTree();
    Ins(Root[c], 1, SZ, b, e, 1);
}
void Do(int b, int e, int c){
    A tp = A(b,b,0);
    set<A>::iterator it, it2, it3;
    it = Set.lower_bound(tp);
    while(it!=Set.begin()){
        it2 = it;
        it2--;
        if(it2->e < b)break;
        it = it2;
    }
    if(it->e >= e){
        tp = *it;
        Del(tp.b,tp.e,tp.c);
        Make(tp.b,b-1,tp.c);
        Make(e+1,tp.e,tp.c);
        Make(b,e,c);
        return;
    }
    it2 = it;
    while(1){
        it3 = it2;it3++;
        if(it3==Set.end() || it3->b > e)break;
        it2 = it3;
    }
    it3=it;
    it3++;
    while(it3!=it2){
        tp = *it3;
        it3++;
        Del(tp.b,tp.e,tp.c);
    }
    tp = *it;
    Del(tp.b,tp.e,tp.c);
    Make(tp.b,b-1,tp.c);
    tp = *it2;
    Del(tp.b,tp.e,tp.c);
    Make(e+1,tp.e,tp.c);
    Make(b,e,c);
}
int CC[151000], TT[110], ct, Ans[10], AC;
struct BB{
    int x, num;
    bool operator<(const BB &p)const{
        return x<p.x;
    }
}TT2[110];
int main(){
    int i, ck, b, e, c, x;
    srand(1879);
    scanf("%d%d%d",&n,&Q,&P);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Set.insert(A(i,i,w[i]));
        if(!Root[w[i]])Root[w[i]] = new SegTree();
        Ins(Root[w[i]], 1, SZ, i,i, 1);
        D[i/BSZ][i%BSZ]=w[i];
    }
    while(Q--){
        scanf("%d%d%d",&ck,&b,&e);
        if(ck == 1){
            scanf("%d",&c);
            if(b/BSZ == e/BSZ){
                spreadB(b/BSZ);
                InsB(b/BSZ,b%BSZ,e%BSZ,c);
            }
            else{
                spreadB(b/BSZ);
                spreadB(e/BSZ);
                InsB(b/BSZ,b%BSZ,BSZ-1,c);
                InsB(e/BSZ,0,e%BSZ,c);
                for(i=b/BSZ+1;i<e/BSZ;i++)DF[i] = c;
            }
            Do(b,e,c);
            continue;
        }
        for(i=1;i<=80;i++){
            x = b + ((long long)rand()*10000+rand())%(e-b+1);
            if(DF[x/BSZ]){
                TT[i] = DF[x/BSZ];
            }
            else{
                TT[i] = D[x/BSZ][x%BSZ];
            }
            CC[TT[i]]++;
        }
        ct = 0;
        for(i=1;i<=80;i++){
            if(CC[TT[i]]){
                TT2[ct].x = CC[TT[i]], TT2[ct].num = TT[i];
                ct++;
                CC[TT[i]]=0;
            }
        }
        sort(TT2,TT2+ct);
        AC=0;
        for(i=ct-1;i>=0 && i>=ct-20;i--){
            if(Gap(Root[TT2[i].num], 1, SZ, b, e) * 100 >= P * (e-b+1)){
                Ans[AC++] = TT2[i].num;
            }
        }
        printf("%d ",AC);
        for(i=0;i<AC;i++)printf("%d ",Ans[i]);
        printf("\n");
    }
}