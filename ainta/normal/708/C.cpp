#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int D[401000], n, res[401000];
vector<int>E[401000];
void DFS(int a, int pp){
    int i;
    D[a]=1;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            DFS(E[a][i],a);
            D[a]+=D[E[a][i]];
        }
    }
}
int get_C(int a, int pp){
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp && D[E[a][i]]*2 > n){
            return get_C(E[a][i], a);
        }
    }
    return a;
}
void Do(int a, int pp, int c1, int c2){
    if(c1*2 == n)res[a] = 1;
    if((D[a]+c2)*2>=n)res[a] = 1;
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)Do(E[a][i],a,c1,c2);
    }
}
int main(){
    int i, a, b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    a = get_C(1,0);
    DFS(a,0);
    res[a] = 1;
    int Mx = -1, Mx2 = -1, pv;
    for(i=0;i<E[a].size();i++){
        if(D[E[a][i]] > Mx){
            Mx2 = Mx;
            Mx = D[E[a][i]];
            pv = E[a][i];
        }
        else if(D[E[a][i]] > Mx2)Mx2 = D[E[a][i]];
    }
    for(i=0;i<E[a].size();i++){
        if(E[a][i] == pv){
            Do(E[a][i], a, D[E[a][i]], Mx2);
        }
        else{
            Do(E[a][i], a, D[E[a][i]], Mx);
        }
    }
    for(i=1;i<=n;i++)printf("%d ",res[i]);
}