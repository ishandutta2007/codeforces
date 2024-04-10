#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define N_ 301000
#define pii pair<int,int>
using namespace std;
int n, m, EC, st;
vector<int>E[N_], L[N_];
priority_queue<pii>PQ;
int D[N_];
struct Edge{
    int a, b;
}Ed[N_];
void Ins(int a, int d){
    if(D[a]<=d)return;
    D[a]=d;
    PQ.push(pii(-d,a));
}
int main(){
    int i, a, b, ck;
    scanf("%d%d%d",&n,&m,&st);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&ck,&a,&b);
        if(ck==1){
            E[a].push_back(b);
            L[a].push_back(0);
        }
        else{
            Ed[EC++]={a,b};
            E[a].push_back(b);
            E[b].push_back(a);
            L[a].push_back(1);
            L[b].push_back(1);
        }
    }
    for(i=1;i<=n;i++)D[i]=1e9;
    Ins(st,0);
    while(!PQ.empty()){
        pii tp = PQ.top();
        PQ.pop();
        if(-tp.first != D[tp.second])continue;
        int x = tp.second;
        for(i=0;i<E[x].size();i++)Ins(E[x][i],D[x]+L[x][i]);
    }
    int r1 = 0, r2 = 0;
    for(i=1;i<=n;i++){
        if(D[i]==0)r2++;
        if(D[i] < 1e8)r1++;
    }
    printf("%d\n",r1);
    for(i=0;i<EC;i++){
        if(D[Ed[i].a]<D[Ed[i].b])printf("+");
        else printf("-");
    }
    printf("\n%d\n",r2);
    for(i=0;i<EC;i++){
        if(D[Ed[i].a]<D[Ed[i].b])printf("-");
        else printf("+");
    }
}