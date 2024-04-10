#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, st, ed, Num[1010], Up[1010], cnt, pE[1010], EC, res = -1, SC;
int n1, n2, rn1, rn2, rC, Q[30100], head, tail;
bool v[30100];
vector<int>G[1010];
struct Edge{
    int b, e, d, chk, rev, num;
}E[60100];
void DFS(int a, int pnum){
    Num[a] = ++cnt;
    int i, x, r = Num[a];
    for(i=0;i<G[a].size();i++){
        if(E[G[a][i]].chk)continue;
        if(E[G[a][i]].num == pnum)continue;
        x = E[G[a][i]].e;
        if(Num[x]){
            if(Num[x] < Num[a]){
                r = min(r,Num[x]);
            }
            else{
                r = min(r,Up[x]);
            }
        }
        else{
            pE[x] = G[a][i];
            DFS(x, E[G[a][i]].num);
            r = min(r, Up[x]);
        }
    }
    Up[a] = r;
}
void init(){
    int i;
    for(i=1;i<=n;i++){
        Up[i] = 0;
        Num[i] = 0;
        pE[i] = 0;
    }
    cnt = 0;
}
void Make_Edge(int a, int b, int d, int num){
    G[a].push_back(EC);
    G[b].push_back(EC+1);
    E[EC].b = a, E[EC].e = b, E[EC].d = d, E[EC].chk = 0, E[EC].rev = EC+1, E[EC].num = num; EC++;
    E[EC].b = b, E[EC].e = a, E[EC].d = d, E[EC].chk = 0, E[EC].rev = EC-1, E[EC].num = num; EC++;
}
void Get1(){
    int a = ed, pp, t, r = -1, nn = -1;
    while(a!=st){
        if(Up[a] == Num[a]){
            t = E[pE[a]].d;
            if(r == -1 || r>t){
                r = t, nn = E[pE[a]].num;
            }
        }
        a = E[pE[a]].b;
    }
    if(r == -1)return;
    if(res == -1 || res > r){
        res = r;
        rC = 1;
        rn1 = nn;
    }
}
void Get2(int dd, int num){
    if(!Num[ed])return;
    int a = ed, pp, t, r = -1, nn = -1, i;
    while(a!=st){
        if(Up[a] == Num[a]){
            t = E[pE[a]].d;
            if(r == -1 || r>t){
                r = t, nn = E[pE[a]].num;
            }
        }
        a = E[pE[a]].b;
    }
    for(i=1;i<=n;i++){
        if(Num[i] && i!=st && Up[i] == Num[i]){
            if(!v[E[pE[i]].num]){
                v[E[pE[i]].num] = true;
                Q[++tail] = pE[i];
            }
        }
    }
    if(r == -1)return;
    if(res == -1 || res > dd + r){
        rC = 2;
        res = dd+r;
        rn1 = num;
        rn2 = nn;
    }
}
int main(){
    int i, a, b, d, pp, t;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&d);
        if(a == b)continue;
        Make_Edge(a,b,d,i);
    }
    init();
    DFS(st, -1);
    if(!Num[ed]){
        printf("0\n");
        printf("0\n");
        return 0;
    }
    a = ed;
    Get1();
    SC = 0;
    for(i=1;i<=n;i++){
        if(Num[i] && i != st){
            Q[++tail] = pE[i];
            v[E[pE[i]].num] = true;
        }
    }
    while(head<tail){
        int tt = Q[++head];
        E[tt].chk = 1;
        E[E[tt].rev].chk = 1;
        init();
        DFS(st, -1);
        Get2(E[tt].d, E[tt].num);
        E[tt].chk = 0;
        E[E[tt].rev].chk = 0;
    }
    if(res == -1){
        printf("-1\n");
        return 0;
    }
    printf("%d\n%d\n",res,rC);
    if(rC == 1)printf("%d\n",rn1);
    else printf("%d %d\n",rn1,rn2);
}