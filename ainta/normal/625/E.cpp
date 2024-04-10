#include<stdio.h>
#include<algorithm>
#include<set>
#define pii pair<int,int>
using namespace std;
int n, m, X[101000], P[101000], Ans[101000], Ans_C;
bool chk[101000];
struct A{
    int x, p, num, tx, tt;
    A(){}
    A(int x_,int p_, int num_, int tx_, int tt_){x=x_,p=p_,num=num_, tx=tx_, tt = tt_;}
    bool operator<(const A &q)const{
        return x!=q.x?x<q.x:p<q.p;
    }
};
set<A>Set;
set<pii>Set2;
int Get(A a, A b){
    if(a.num==b.num)return 0;
    int ax,bx,mt = max(a.tt,b.tt);
    if(a.tt < b.tt && a.num > b.num){
        ax = (a.tx + (long long)a.p*(b.tt-a.tt-1))%m;
        bx = b.tx;
        if(ax+a.p<m){
            if(ax<=bx && bx<=ax+a.p)return b.tt;
        }
        else{
            if(ax<=bx)return b.tt;
            if(bx<=(ax+a.p)%m)return b.tt;
        }
    }
    ax = (a.tx + (long long)a.p*(mt-a.tt))%m;
    bx = (b.tx + (long long)b.p*(mt-b.tt))%m;
    int d = bx - ax;
    if(d<0)d += m;
    if(a.p <= b.p){
        if(a.num < b.num && d<=a.p)return mt+1;
        return 0;
    }
    if(a.num < b.num){
        if(d<=a.p)return mt+1;
        return mt+(d-a.p-1)/(a.p-b.p)+2;
    }
    else{
        return mt+(d-1)/(a.p-b.p)+1;
    }
}
void Ins(A a, A b){
    int r = Get(a,b);
    if(r)Set2.insert(pii(r, a.num));
}
void Do(int r, int a){
    A tp;
    tp.x = X[a], tp.p = tp.num = -1;
    set<A>::iterator it, it2;
    it = Set.lower_bound(tp);
    int t, c = 0;
    it2 = it;
    if(it2==Set.begin())it2=Set.end();
    it2--;
    t = Get(*it2, *it);
    if(t)Set2.erase(pii(t, it2->num));
    while(1){
        it2 = it;
        it2++;
        if(it2 == Set.end())it2 = Set.begin();
        t = Get(*it, *it2);
        if(t == r){
            chk[it2->num]=1;
            Set.erase(it2);
            c++;
        }
        else break;
    }
    tp = *it;
    tp.tx = (tp.tx + (long long)tp.p*(r - tp.tt)) % m;
    tp.tt = r;
    tp.p-=c;
    if(tp.p<0)tp.p=0;
    Set.erase(it);
    Set.insert(tp);
    it = Set.find(tp);
    it2 = it;
    it2++;
    if(it2 == Set.end())it2 = Set.begin();
    Ins(*it, *it2);
    it2 = it;
    if(it2 == Set.begin())it2 = Set.end();
    it2--;
    Ins(*it2, *it);
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d%d",&X[i],&P[i]);
        X[i]--;
        Set.insert(A(X[i],P[i],i,X[i],0));
    }
    set<A>::iterator it, it2;
    for(it = Set.begin();it!=Set.end();it++){
        it2 = it;
        it2++;
        if(it2 == Set.end())it2=Set.begin();
        Ins(*it,*it2);
    }
    pii tp;
    while(!Set2.empty()){
        tp = *Set2.begin();
        Set2.erase(tp);
        if(chk[tp.second])continue;
        Do(tp.first, tp.second);
    }
    while(!Set.empty()){
        Ans[Ans_C++] = Set.begin()->num;
        Set.erase(Set.begin());
    }
    printf("%d\n",Ans_C);
    for(i=0;i<Ans_C;i++)printf("%d ",Ans[i]);
}