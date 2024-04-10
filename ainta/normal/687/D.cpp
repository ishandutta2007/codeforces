#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int UF[101000], UD[101000], dep, n, m, TC;
bool chk[501000];
struct Edge{
    int a, b, c;
    bool operator<(const Edge &p)const{
        return c<p.c;
    }
}w[501000], TP[501000];
vector<Edge>E[1100000];
int Find(int a){
    if(a==UF[a])return a;
    dep ^= UD[a];
    int t = UF[a];
    UF[a] = Find(UF[a]);
    UD[a] ^= UD[t];
    return UF[a];
}
int Do(){
    int i, a, b, pa, pb, da, db, res = -1;
    sort(TP+1,TP+TC+1);
    for(i=1;i<=TC;i++)chk[i] = false;
    for(i=TC;i>=1;i--){
        a = TP[i].a, b = TP[i].b;
        dep = 0;
        pa = Find(a);
        da = dep;
        dep = 0;
        pb = Find(b);
        db = dep;
        if(pa == pb){
            if(da == db){
                res = TP[i].c;
                for(i=i-1;i>=1;i--){
                    chk[i]=true;
                }
                break;
            }
            else{
                chk[i]=true;
            }
            continue;
        }
        UF[pa] = pb;
        UD[pa] = (da^db^1);
    }
    for(i=1;i<=TC;i++){
        UF[TP[i].a] = TP[i].a;
        UF[TP[i].b] = TP[i].b;
        UD[TP[i].a] = UD[TP[i].b]=0;
    }
    return res;
}
void init(int nd, int b, int e){
    int i;
    TC = 0;
    for(i=b;i<=e;i++){
        TP[++TC] = w[i];
    }
    Do();
    for(i=1;i<=TC;i++){
        if(!chk[i])E[nd].push_back(TP[i]);
    }
    if(b==e)return;
    int m = (b+e)>>1;
    init(nd*2,b,m);
    init(nd*2+1,m+1,e);
}
void Pro(int nd, int b, int e, int s, int l){
    if(b==s&&e==l){
        int i;
        for(i=0;i<E[nd].size();i++){
            TP[++TC] = E[nd][i];
        }
        return;
    }
    int m = (b+e)>>1;
    if(s<=m)Pro(nd*2,b,m,s,min(m,l));
    if(l>m)Pro(nd*2+1,m+1,e,max(m+1,s),l);
}
int main(){
    int i, Q, b, e;
    scanf("%d%d%d",&n,&m,&Q);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].c);
    }
    for(i=1;i<=n;i++){
        UF[i]=i;
        UD[i]=0;
    }
    init(1,1,m);
    while(Q--){
        scanf("%d%d",&b,&e);
        TC = 0;
        Pro(1,1,m,b,e);
        printf("%d\n",Do());
    }
}