#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>
#define N_ 201000
#define SZ 262144
#define INF 1999999999
using namespace std;
vector<int>E[N_], F[N_];
multiset<int>Set[N_];
int n, m, P[N_], Num[N_], reNum[N_], cnt, par[N_], Ck[N_];
int DFS(int a, int pp){
    Num[a] = ++cnt;
    par[a] = pp;
    int r = cnt, i, t;
    for(i=0;i<E[a].size();i++){
        if(Num[E[a][i]]){
            r=min(r,Num[E[a][i]]);
            continue;
        }
        t = DFS(E[a][i],a);
        r=min(r,t);
        if(t >= Num[a]){
            Ck[E[a][i]]=1;
        }
    }
    return r;
}
void Make(int a, int b){
    F[a].push_back(b);F[b].push_back(a);
}
void Do2(int a){
    Make(a,cnt);
    for(int i=0;i<E[a].size();i++){
        if(!Ck[E[a][i]])Do2(E[a][i]);
    }
}
void Do(int a){
    int i;
    for(i=0;i<E[a].size();i++)Do(E[a][i]);
    for(i=0;i<E[a].size();i++){
        if(Ck[E[a][i]]){
            cnt++;
            Make(a,cnt);
            Do2(E[a][i]);
        }
    }
}
int C[N_];
void DFS2(int a, int pp){
    int i;
    C[a]=1;
    for(i=0;i<F[a].size();i++){
        if(F[a][i]!=pp){
            DFS2(F[a][i],a);
            C[a] += C[F[a][i]];
        }
    }
}
int head[N_], IT[SZ+SZ];
void HLD(int a, int pp, int h){
    Num[a] = ++cnt;
    par[cnt] = Num[pp];
    head[cnt] = Num[h];
    int i, Mx = 0, t = -1;
    if(a>n)Set[Num[a]].insert(INF);
    for(i=0;i<F[a].size();i++){
        if(F[a][i] == pp)continue;
        if(a>n)Set[Num[a]].insert(P[F[a][i]]);
        if(Mx < C[F[a][i]])Mx=C[F[a][i]], t = i;
    }
    if(t==-1)return;
    HLD(F[a][t], a,h);
    for(i=0;i<F[a].size();i++){
        if(F[a][i]==pp || i==t)continue;
        HLD(F[a][i], a ,F[a][i]);
    }
}
int LCA(int a, int b){
    if(head[a]==head[b])return min(a,b);
    if(a<b)return LCA(a,par[head[b]]);
    return LCA(par[head[a]],b);
}
int Min(int b, int e){
    b+=SZ,e+=SZ;
    int r = INF;
    while(b<=e){
        r=min(r,IT[b]);
        r=min(r,IT[e]);
        b=(b+1)>>1;
        e=(e-1)>>1;
    }
    return r;
}
int Gap(int a, int b){
    if(head[a] <= b) return Min(b,a);
    return min(Min(head[a],a), Gap(par[head[a]], b));
}
int Calc(int a, int b){
    int l = LCA(a,b);
    if(reNum[l] > n)l=par[l];
    return min(Gap(a,l), Gap(b,l));
}
void Ins(int a, int b){
    a+=SZ;
    IT[a]=b;
    while(a!=1){
        a>>=1;
        IT[a]=min(IT[a+a],IT[a+a+1]);
    }
}
int main(){
    int i, Q, a, b, t;
    scanf("%d%d%d",&n,&m,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&P[i]);
    }
    while(m--){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1, 0);
    for(i=1;i<=n;i++){
        E[i].clear();
        Num[i]=0;
    }
    cnt = n;
    for(i=2;i<=n;i++)E[par[i]].push_back(i);
    Do(1);
    for(i=1;i<=n;i++){
        Num[i]=0;
    }
    DFS2(1, 0);
    m=cnt;cnt=0;
    HLD(1, 0, 1);
    for(i=1;i<=m;i++)reNum[Num[i]]=i;
    for(i=1;i<=n;i++) Ins(Num[i], P[i]);
    for(i=n+1;i<=m;i++) Ins(Num[i], *Set[Num[i]].begin());
    char pp[3];
    while(Q--){
        scanf("%s",pp);
        scanf("%d%d",&a,&b);
        if(pp[0]=='C'){
            Ins(Num[a],b);
            t = par[Num[a]];
            if(t){
                Set[t].erase(Set[t].find(P[a]));
                Set[t].insert(b);
                Ins(t, *Set[t].begin());
            }
            P[a]=b;
            continue;
        }
        printf("%d\n",Calc(Num[a],Num[b]));
    }
    return 0;
}