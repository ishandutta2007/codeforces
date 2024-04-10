#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define pii pair<int,int>
struct Range{
    int b, e;
    bool operator <(const Range &p)const{
        return b<p.b;
    }
}RR[2010000];
vector<Range>P[501000][2];
int n, m, cnt, Dest[2010000];
int D[2010000];
struct Edge{
    int a, b, s, l;
}w[501000];
struct Node{
    int b, e, num;
    bool operator <(const Node &p)const{
        return b<p.b;
    }
};
vector<Edge>E[2010000];
vector<Node>G[501000][2];
void Make(int nd, int b, int e){
    P[nd][0].push_back({(b+1)/2*2, e/2*2});
    P[nd][1].push_back({b/2*2+1,(e+1)/2*2-1});
}
void Put(int x, int y, vector<Range> &T){
    int i, b = 0, e = -2;
    for(i=0;i<T.size();i++){
        if(e < T[i].b){
            if(e>=0){
                cnt++;
                RR[cnt] = {b,e};
                if(x==n)Dest[cnt] = 1;
                G[x][y].push_back({b,e,cnt});
            }
            b = T[i].b;
        }
        e = max(e, T[i].e);
    }
    cnt++;
    RR[cnt] = {b,e};
    if(x==n)Dest[cnt] = 1;
    G[x][y].push_back({b,e,cnt});
}
void FF(int &a, int ck, int c){
    if(a%2!=ck)a+=c;
}
void ME2(int b, int e, int ck, int s1, int l1, int s2, int l2){
    FF(s1,ck,1);FF(l1,ck,-1); FF(s2,!ck,1);FF(l2,!ck,-1);
    if(s1>l1||s2>l2)return;
    Node t1 = {s1,l1,0}, t2 = {s2,l2,0};
    int p1 = lower_bound(G[b][ck].begin(), G[b][ck].end(),t1) - G[b][ck].begin();
    int p2 = lower_bound(G[e][!ck].begin(), G[e][!ck].end(),t2) - G[e][!ck].begin();
    if(p1 == G[b][ck].size() || G[b][ck][p1].b > s1) p1--;
    if(p2 == G[e][!ck].size() || G[e][!ck][p2].b > s2) p2--;
    int x = G[b][ck][p1].num, y = G[e][!ck][p2].num;
    E[x].push_back({x, y, s1, l1});
}
void Make_Edge(int b, int e, int s, int l){
    ME2(b, e, 0, s, l-1, s+1, l);
    ME2(b, e, 1, s, l-1, s+1, l);
}
priority_queue<pii>PQ;
void Ins(int a, int d){
    if(D[a]<=d)return;
    D[a] = d;
    PQ.push(pii(-d,a));
}
void Dijk(){
    int i;
    for(i=1;i<=cnt;i++)D[i] = 2e9;
    Ins(G[1][0][0].num,  0);
    while(!PQ.empty()){
        pii tp = PQ.top();
        PQ.pop();
        if(D[tp.second] != -tp.first)continue;
        int x = tp.second;
        for(i=0;i<E[x].size();i++){
            if(max(D[x],E[x][i].s) <= min(E[x][i].l, RR[x].e)){
                Ins(E[x][i].b, max(D[x],E[x][i].s) + 1);
            }
        }
    }
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    if(n==1){
        printf("0\n");
        return 0;
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d%d",&w[i].a,&w[i].b,&w[i].s,&w[i].l);
        Make(w[i].a, w[i].s, w[i].l);
        Make(w[i].b, w[i].s, w[i].l);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<2;j++){
            if(P[i][j].empty())continue;
            sort(P[i][j].begin(),P[i][j].end());
            Put(i,j,P[i][j]);
        }
    }
    for(i=0;i<m;i++){
        Make_Edge(w[i].a,w[i].b,w[i].s,w[i].l);
        Make_Edge(w[i].b,w[i].a,w[i].s,w[i].l);
    }
    if(G[1][0].empty() || G[1][0][0].b){
        printf("-1\n");
        return 0;
    }
    Dijk();
    int Res = 2e9;
    for(i=1;i<=cnt;i++)if(Dest[i])Res = min(Res, D[i]);
    printf("%d\n",Res==2e9?-1:Res);
}