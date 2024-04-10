#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int n, m, Q, par[201000], Num[201000], cnt, PP[201000], RR[201000], Rt[201000], Rt_C;
int Up[201000], Down[201000];
int DFS(int a, int pp, int rt){
    Num[a]=++cnt;
    par[a] = pp;
    RR[a] = rt;
    int r = cnt, i, t, cc = 0;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]==pp){
            cc++;
            continue;
        }
        if(Num[E[a][i]]){
            r=min(r,Num[E[a][i]]);
            continue;
        }
        t = DFS(E[a][i],a, rt);
        r=min(t,r);
    }
    if(r == Num[a] && cc < 2)PP[a]=a;
    return r;
}
void DFS2(int a){
    int i;
    if(!PP[a])PP[a]=PP[par[a]];
    for(i=0;i<E[a].size();i++){
        DFS2(E[a][i]);
    }
}
int Dep[201000], ppp[201000][18];
void DFS3(int a, int pp, int dep){
    ppp[a][0] = pp;
    Dep[a] = dep;
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)DFS3(E[a][i],a, dep+1);
    }
}
int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b],i=0;
    while(d){
        if(d&1)a=ppp[a][i];
        d>>=1;i++;
    }
    for(i=17;i>=0;i--)if(ppp[a][i]!=ppp[b][i])a=ppp[a][i],b=ppp[b][i];
    if(a!=b)a=ppp[a][0];
    return a;
}
int ck;
void DFS4(int a, int pp){
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)DFS4(E[a][i],a);
    }
    Up[ppp[a][0]]+=Up[a];
    Down[ppp[a][0]]+=Down[a];
    if(Up[a]&&Down[a]){
        ck=1;
    }
}
int main(){
    int i, a, b, t, j;
    scanf("%d%d%d",&n,&m,&Q);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!Num[i]){
            DFS(i,0, i);
            Rt[Rt_C++]=i;
        }
    }
    for(i=1;i<=n;i++)E[i].clear();
    for(i=1;i<=n;i++){
        if(par[i])E[par[i]].push_back(i);
    }
    for(i=0;i<Rt_C;i++){
        DFS2(Rt[i]);
    }
    for(i=1;i<=n;i++){
        E[i].clear();
    }
    for(i=1;i<=n;i++){
        if(par[i] && PP[par[i]]!=PP[i]){
            E[PP[par[i]]].push_back(PP[i]);
        }
    }
    for(i=0;i<Rt_C;i++){
        DFS3(Rt[i],0, 0);
    }
    for(i=0;i<17;i++){
        for(j=1;j<=n;j++){
            ppp[j][i+1]=ppp[ppp[j][i]][i];
        }
    }
    while(Q--){
        scanf("%d%d",&a,&b);
        if(RR[a]!=RR[b]){
            ck=1;
            break;
        }
        a=PP[a],b=PP[b];
        t = LCA(a,b);
        Up[a]++,Up[t]--;
        Down[b]++,Down[t]--;
    }
    for(i=0;i<Rt_C;i++){
        DFS4(Rt[i], 0);
    }
    if(!ck)printf("Yes\n");
    else printf("No\n");
}