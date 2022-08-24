#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, w[201000], be = 1, ed = 1000000, mid, res, D[201000], D2[201000], C[201000], G;
vector<int>E[201000];
void DFS(int a, int pp){
    int i, x, r = 1, MM = 0;
    C[a] = 1;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        DFS(x, a);
        C[a] += C[x];
        if(D[x] == C[x]){
            r += D[x];
        }
        else if(MM <D[x])MM=D[x];
    }
    if(w[a] < mid)D[a]=0;
    else D[a] = r+MM;
    G = max(G,D[a]);
}
void DFS2(int a, int pp){
    int MM = 0, x, ss = 0, Mnum = -1, MM2 = 0, tt;
    int i;
    if(w[a]>=mid){
        if(D2[a] == n - C[a] + 1) ss += D2[a] - 1;
        else MM = max(MM, D2[a] - 1);
        for(i=0;i<E[a].size();i++){
            x = E[a][i];
            if(x == pp)continue;
            if(D[x] == C[x]) ss += D[x];
            else{
                if(MM < D[x]){
                    MM2 = MM;
                    MM = D[x], Mnum = x;
                }
                else if(MM2 < D[x])MM2 = D[x];
            }
        }
        for(i=0;i<E[a].size();i++){
            x = E[a][i];
            if(x == pp || w[x] < mid)continue;
            tt = ss;
            if(D[x] == C[x])tt -= C[x];
            if(x == Mnum) D2[x] = 2+tt+MM2;
            else D2[x] = 2+tt+MM;
        }
    }
    else{
        for(i=0;i<E[a].size();i++){
            x = E[a][i];
            if(x == pp || w[x] < mid)continue;
            D2[x] = 1;
        }
    }
    MM = 0, ss = 0;
    if(D2[a]==n-C[a]+1)ss = D2[a]-1;
    else MM = D2[a]-1;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        if(D[x] == C[x])ss += D[x];
        else if(MM<D[x])MM=D[x];
    }
    if(w[a]>=mid)G=max(G,ss+MM+1);
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        DFS2(x,a);
    }
}
bool Pos(){
    G = 0;
    int i;
    for(i=1;i<=n;i++)D[i]=D2[i]=0;
    DFS(1,0);
    DFS2(1,0);
    if(G>=K)return true;
    return false;
}
int main(){
    int i, j, a, b;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    while(be<=ed){
        mid = (be+ed)>>1;
        if(Pos()){
            res = mid;
            be = mid+1;
        }
        else ed = mid-1;
    }
    printf("%d\n",res);
}