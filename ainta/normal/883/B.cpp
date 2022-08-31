#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define N_ 201000
using namespace std;
int n, m, K, w[N_], Q[N_], head, tail, Deg[N_], Mn[N_], Mx[N_], Res[N_];
vector<int>E[N_], F[N_];
set<int>Set;
struct point{
    int b, e, num;
    bool operator<(const point &p)const{
        return e!=p.e?e<p.e:b<p.b;
    }
}P[N_];
int main(){
    int i, a, b, j;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[b].push_back(a);
        F[a].push_back(b);
    }
    for(i=1;i<=n;i++){
        Deg[i] = F[i].size();
        if(!Deg[i])Q[++tail] = i;
    }
    for(i=1;i<=n;i++)Mn[i] = 1, Mx[i] = K;
    while(head < tail){
        int x = Q[++head];
        if(w[x]) Mn[x] = max(Mn[x], w[x]);
        for(i=0;i<E[x].size();i++){
            Deg[E[x][i]]--;
            Mn[E[x][i]] = max(Mn[E[x][i]], Mn[x] + 1);
            if(!Deg[E[x][i]])Q[++tail] = E[x][i];
        }
    }
    if(tail != n){
        printf("-1\n");
        return 0;
    }
    head = tail = 0;
    for(i=1;i<=n;i++){
        Deg[i] = E[i].size();
        if(!Deg[i])Q[++tail] = i;
    }
    while(head < tail){
        int x = Q[++head];
        if(w[x]) Mx[x] = min(Mx[x], w[x]);
        for(i=0;i<F[x].size();i++){
            Deg[F[x][i]]--;
            Mx[F[x][i]] = min(Mx[F[x][i]], Mx[x] - 1);
            if(!Deg[F[x][i]])Q[++tail] = F[x][i];
        }
    }
    for(i=1;i<=n;i++){
        if(Mn[i] > Mx[i]){
            printf("-1\n");
            return 0;
        }
        P[i] = {Mn[i],Mx[i], i};
    }
    sort(P+1,P+n+1);
    for(i=1;i<=K;i++)Set.insert(i);
    for(i=1;i<=n;i++){
        int x = P[i].num;
        auto it = Set.lower_bound(Mn[x]);
        if(it==Set.end() || (*it) > Mx[x]){
            Res[x] = Mn[x];
        }
        else{
            Res[x] = *it;
            Set.erase(it);
        }
        for(j=0;j<E[x].size();j++){
            Mn[E[x][j]] = max(Mn[E[x][j]], Res[x]+1);
        }
    }
    if(Set.empty()){
        for(i=1;i<=n;i++)printf("%d ",Res[i]);
    }
    else printf("-1\n");
}