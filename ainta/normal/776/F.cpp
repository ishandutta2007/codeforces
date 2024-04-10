#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n, m, cc, cnt, AL;
vector<pii>E[101000];
vector<int>G[201000], F[201000];
int Num[501000], Col[201000];
void Go(int b, int e){
    G[cnt].push_back(e);
    int t = lower_bound(E[e].begin(),E[e].end(), pii(b,0)) - E[e].begin();
    pii tp = E[e][(t+1)%E[e].size()];
    if(Num[tp.second])return;
    Num[tp.second] = cnt;
    Go(e, tp.first);
}
int chk[201000], C[201000];
void DFS(int a, int pp){
    int i, x;
    C[a] = 1;
    for(i=0;i<F[a].size();i++){
        x = F[a][i];
        if(chk[x] || x==pp)continue;
        DFS(x, a);
        C[a] += C[x];
    }
}
int DFS2(int a, int pp, int MM){
    int i, x;
    for(i=0;i<F[a].size();i++){
        x = F[a][i];
        if(chk[x] || x==pp)continue;
        if(C[x] * 2 > MM)return DFS2(x, a, MM);
    }
    return a;
}
int get_mid(int a){
    DFS(a,0);
    if(C[a]==1)return 0;
    return DFS2(a,0,C[a]);
}
void Do(int a, int dep){
    int mid = get_mid(a);
    if(!mid){
        Col[a] = dep;
        return;
    }
    Col[mid] = dep;
    int i;
    chk[mid] = 1;
    for(i=0;i<F[mid].size();i++){
        if(!chk[F[mid][i]]) Do(F[mid][i], dep+1);
    }
    chk[mid] = 0;
}
struct AA{
    long long g;
    int num;
    bool operator<(const AA &p)const{
        return g<p.g;
    }
}ord[201000];
int main(){
    int i, a, b, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(pii(b,cc++));
        E[b].push_back(pii(a,cc++));
    }
    for(i=1;i<=n;i++){
        E[i].push_back(pii(i%n+1,cc++));
        E[i%n+1].push_back(pii(i,cc++));
    }
    for(i=1;i<=n;i++){
        sort(E[i].begin(),E[i].end());
    }
    for(i=1;i<=n;i++){
        for(j=0;j<E[i].size();j++){
            if(!Num[E[i][j].second]){
                cnt++;
                Num[E[i][j].second] = cnt;
                Go(i,E[i][j].first);
            }
        }
    }
    for(i=1;i<=cnt;i++){
        if(G[i].size() == n && !AL)AL = i;
    }
    for(i=0;i<cc;i++){
        if(Num[i]!=AL && Num[i^1]!=AL)F[Num[i]].push_back(Num[i^1]);
    }
    int rt = 1;
    if(AL==1)rt++;
    Do(rt, 1);
    int ccc = 0;
    for(i=1;i<=cnt;i++){
        if(i==AL)continue;
        sort(G[i].begin(),G[i].end());
        long long ss = 0;
        for(j=0;j<2;j++){
            ss *= 1000000;
            ss += G[i][G[i].size()-j-1];
        }
        ord[ccc++]={ss,i};
    }
    sort(ord,ord+ccc);
    for(i=0;i<ccc;i++){
        printf("%d ",Col[ord[i].num]);
    }
}