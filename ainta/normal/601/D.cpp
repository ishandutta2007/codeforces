#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 301000
char p[N_];
int n, G[N_], Num[N_], Col[N_], cnt, col_c, Prev[N_], PP[N_], ed[N_], Dep[N_], par[N_][20];
int cc[N_][26], S[N_], RR[N_];
vector<int>E[N_];
void DFS(int a, int pp, int col){
    Num[a] = ++cnt;
    par[a][0] = pp;
    Col[a] = col;
    Prev[a] = Num[PP[col]];
    PP[col] = a;
    int i, x;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        if(!cc[col][p[x]-'a']){
            col_c++;
            cc[col][p[x]-'a'] = col_c;
        }
        Dep[x] = Dep[a]+1;
        DFS(x, a, cc[col][p[x]-'a']);
    }
    ed[a] = cnt;
}
void Make_List(){
    int i, j;
    for(i=0;i<18;i++){
        for(j=1;j<=n;j++){
            par[j][i+1] = par[par[j][i]][i];
        }
    }
}
void Do(int a){
    int i, x = a, t;
    for(i=18;i>=0;i--){
        t = par[x][i];
        if(t && Num[t] > Prev[a]) x = t;
    }
    S[par[x][0]]--;
    S[a]++;
}
void DFS2(int a, int pp){
    RR[a] = S[a];
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]==pp)continue;
        DFS2(E[a][i],a);
        RR[a] += RR[E[a][i]];
    }
    G[a] += RR[a];
}
int main(){
    int i, a, b, Mx = -1, Mx_C = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&G[i]);
    scanf("%s",p+1);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    col_c = 1;
    DFS(1, 0, 1);
    Make_List();
    for(i=1;i<=n;i++){
        Do(i);
    }
    DFS2(1, 0);
    for(i=1;i<=n;i++){
        Mx = max(Mx, G[i]);
    }
    for(i=1;i<=n;i++){
        if(Mx == G[i])Mx_C++;
    }
    printf("%d\n%d\n",Mx,Mx_C);
}