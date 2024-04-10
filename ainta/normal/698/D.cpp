#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010][8];
bool chk[1010];
struct point{
    long long x, y;
}w[1010], P[8];
long long Dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
long long ccw(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int n, K;
bool DFS(vector<int>V, int *R, int ed){
    if(V.empty()){
        return true;
    }
    int i, a = R[0], x, j;
    for(i=0;i<V.size();i++){
        x = V[i];
        vector<int>L;
        for(j=0;j<V.size();j++){
            if(j!=i)L.push_back(V[j]);
        }
        for(j=0;j<E[x][a].size();j++){
            L.push_back(E[x][a][j]);
        }
        sort(L.begin(),L.end());
        L.resize(unique(L.begin(),L.end())-L.begin());
        if(L.size() >= ed)continue;
        if(DFS(L, R+1, ed-1)) return true;
    }
    return false;
}
int main(){
    int i, j, k, R[10];
    scanf("%d%d",&K,&n);
    for(i=1;i<=K;i++){
        scanf("%lld%lld",&P[i].x,&P[i].y);
    }
    for(i=1;i<=n;i++){
        scanf("%lld%lld",&w[i].x,&w[i].y);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=K;j++){
            long long d = Dist(w[i],P[j]);
            for(k=1;k<=n;k++){
                if(ccw(w[i], P[j], w[k]) == 0 && d > Dist(w[i], w[k]) && d > Dist(P[j],w[k])){
                    E[i][j].push_back(k);
                    if(E[i][j].size() > 6)break;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=K;j++)R[j] = j;
        do{
            vector<int>Vec;
            Vec.push_back(i);
            if(DFS(Vec, R+1, K)){
                chk[i] = true;
                break;
            }
        }while(next_permutation(R+1,R+K+1));
    }
    int res = 0;
    for(i=1;i<=n;i++)if(chk[i])res++;
    printf("%d\n",res);
}