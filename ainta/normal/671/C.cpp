#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
vector<int>D[201000], E[201000];
int n, w[201000], BE[201000], ED[201000];
struct SegTree{
    long long S;
    int M, K;
}IT[SZ+SZ+2];
int Change(int nd, int b, int e, int x){
    IT[nd].M = IT[nd].K = x;
    IT[nd].S = (long long)(e-b+1)*x;
}
void UDT(int nd){
    IT[nd].S = IT[nd*2].S+IT[nd*2+1].S;
    IT[nd].M = max(IT[nd*2].M,IT[nd*2+1].M);
}
void spread(int nd, int b, int e, int m){
    if(!IT[nd].K)return;
    Change(nd*2, b, m, IT[nd].K);
    Change(nd*2+1, m+1, e, IT[nd].K);
    IT[nd].K = 0;
}
int Get(int nd, int b, int e, int s, int l, int x){
    if(b == e){
        if(IT[nd].M <= x)return b+1;
        return b;
    }
    int m = (b+e)>>1;
    spread(nd, b, e, m);
    if(IT[nd*2].M > x){
        if(s <= m) return Get(nd*2, b, m, s, min(m,l), x);
        return s;
    }
    if(l > m) return Get(nd*2 + 1, m + 1, e, max(s, m+1), l, x);
    return l+1;
}
void Ins(int nd, int b, int e, int s, int l, int x){
    if(b == s && e == l){
        Change(nd, b, e, x);
        return;
    }
    int m = (b+e)>>1;
    spread(nd, b, e, m);
    if(s <= m)Ins(nd*2, b, m, s,min(m,l),x);
    if(l > m)Ins(nd*2+1,m+1,e, max(s,m+1),l,x);
    UDT(nd);
}
void Do2(int b, int e){
    if(b > e)return;
    int pv = Get(1, 1, n, b, e, e) - 1;
    if(pv < b)return;
    Ins(1, 1, n, b, pv, e);
}
void Do(int a){
    int sz = E[a].size();
    Do2(1, E[a][sz - 2]-1);
    Do2(E[a][0]+1, E[a][sz - 1]-1);
    Do2(E[a][1]+1, n);
}
void init(int nd, int b, int e){
    if(b==e){
        Change(nd, b, e, b-1);
        return;
    }
    int m = (b+e)>>1;
    init(nd*2,b,m);
    init(nd*2+1,m+1,e);
    UDT(nd);
}
int main(){
    int i, j, a;
    for(i=1;i<=200000;i++){
        for(j=i;j<=200000;j+=i){
            D[j].push_back(i);
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        for(j=0;j<D[a].size();j++){
            E[D[a][j]].push_back(i);
        }
    }
    init(1, 1, n);
    long long Res = 0;
    for(i=200000;i>=1;i--){
        if(E[i].size() >= 2){
            long long TS = IT[1].S;
            Do(i);
            Res += (IT[1].S - TS) * i;
        }
    }
    printf("%lld\n",Res);
}