#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define pli pair<long long, int>
vector<int>E[1010];
struct Edge{
    int b, e, d, ck;
}Ed[20100];
int n, m, L, Path[1010];
void Make(int d){
    int i;
    for(i=0;i<2*m;i++){
        if(Ed[i].ck==1)Ed[i].d = d;
    }
}
long long D[1010];
priority_queue<pli>PQ;
void Ins(int a, long long d, int pp){
    if(D[a]<=d)return;
    Path[a] = pp;
    D[a] = d;
    PQ.push(pli(-d,a));
}
void Dijk(int st){
    int i, x;
    for(i=1;i<=n;i++)D[i]=L+1;
    Ins(st,0,-1);
    pli tp;
    while(!PQ.empty()){
        tp = PQ.top();
        PQ.pop();
        if(D[tp.second]!=-tp.first)continue;
        x = tp.second;
        for(i=0;i<E[x].size();i++){
            Ins(Ed[E[x][i]].e, D[x] + Ed[E[x][i]].d, E[x][i]);
        }
    }
}
int main(){
    int i, a;
    int st, ed;
    scanf("%d%d%d%d%d",&n,&m,&L,&st,&ed);
    st++,ed++;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&Ed[i*2].b,&Ed[i*2].e,&Ed[i*2].d);
        Ed[i*2].b++,Ed[i*2].e++;
        Ed[i*2+1] = Ed[i*2];
        swap(Ed[i*2+1].b,Ed[i*2+1].e);
    }
    for(i=0;i<2*m;i++){
        E[Ed[i].b].push_back(i);
        if(Ed[i].d == 0)Ed[i].ck = 1;
    }
    Make(L+1);
    Dijk(st);
    if(D[ed] < L){
        printf("NO\n");
        return 0;
    }
    Make(1);
    Dijk(st);
    if(D[ed] > L){
        printf("NO\n");
        return 0;
    }
    while(D[ed]!=L){
        a = ed;
        int t, ck=0;
        while(a!=st){
            t=Path[a];
            if(Ed[t].ck){
                Ed[t].ck = 2;
                Ed[t^1].ck = 2;
                if(!ck){
                    Ed[t].d += L-D[ed];
                    Ed[t^1].d += L-D[ed];
                    ck=1;
                }
            }
            a=Ed[t].b;
        }
        for(i=0;i<m*2;i++){
            if(Ed[i].ck){
                if(Ed[i].ck==1)Ed[i].d = L+1;
                Ed[i].ck=1;
            }
        }
        Dijk(st);
    }
    printf("YES\n");
    for(i=0;i<m;i++)printf("%d %d %d\n",Ed[i*2].b-1,Ed[i*2].e-1,Ed[i*2].d);
}