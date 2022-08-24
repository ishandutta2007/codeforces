#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000], F[201000];
bool v[201000], v2[201000];
int n, Q[201000], head, tail, Deg[201000], w[201000], Num[201000], cnt;
void DFS(int a){
    v[a]=true;
    Num[a] = cnt;
    int i;
    for(i=0;i<F[a].size();i++){
        if(!v[F[a][i]])DFS(F[a][i]);
    }
}
int main(){
    int i, a, b, rt = 0, x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        F[i].push_back(w[i]);
        F[w[i]].push_back(i);
        E[i].push_back(w[i]);
        Deg[w[i]]++;
    }
    for(i=1;i<=n;i++){
        if(!v[i]){
            cnt++;
            DFS(i);
        }
        if(w[i] == i){
            rt = i;
        }
    }
    for(i=1;i<=n;i++)v[i]=false;
    for(i=1;i<=n;i++){
        if(!Deg[i])Q[++tail] = i;
    }
    while(head<tail){
        x = Q[++head];
        v[x] = true;
        for(i=0;i<E[x].size();i++){
            Deg[E[x][i]]--;
            if(!Deg[E[x][i]])Q[++tail] = E[x][i];
        }
    }
    cnt--;
    if(rt == 0){
        for(i=1;i<=n;i++)if(!v[i])break;
        rt = i;
        w[rt] = rt;
        v2[Num[rt]] = true;
        cnt++;
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++){
        if(!v[i]){
            if(!v2[Num[i]]){
                v2[Num[i]]=true;
                w[i] = rt;
            }
        }
    }
    for(i=1;i<=n;i++)printf("%d ",w[i]);
}