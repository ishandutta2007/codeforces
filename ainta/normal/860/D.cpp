#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000], L[201000];
int v[201000], n, m, Used[201000], RC;
struct AA{
    int a, b, c;
}Res[201000];
void DFS(int a, int pp){
    int i;
    v[a] = 1;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]]){
            DFS(E[a][i], a);
        }
    }
    int tt = -1, b = 0, nn = 0;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]==pp){
            nn = L[a][i];
            continue;
        }
        if(Used[L[a][i]])continue;
        if(tt == -1){
            tt = L[a][i];
            b = E[a][i];
        }
        else{
            Res[++RC] = {b,a,E[a][i]};
            Used[L[a][i]] = Used[tt] = 1;
            tt = -1;
        }
    }
    if(tt != -1 && pp){
        Res[++RC] = {b, a, pp};
        Used[nn] = Used[tt] = 1;
    }
}
int main(){
    int i, a, b;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        L[a].push_back(i);
        L[b].push_back(i);
    }
    for(i=1;i<=n;i++){
        if(!v[i]){
            DFS(i,0);
        }
    }
    printf("%d\n",RC);
    for(i=1;i<=RC;i++)printf("%d %d %d\n",Res[i].a,Res[i].b,Res[i].c);
}