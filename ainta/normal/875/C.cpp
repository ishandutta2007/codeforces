#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, chk[101000], v[101000];
vector<int>E[101000], F[101000];
vector<int>G[101000];
int Prefix(vector<int> &T1, vector<int> &T2){
    if(T1.size() > T2.size())return 0;
    int i;
    for(i=0;i<T1.size();i++)if(T1[i]!=T2[i])return 0;
    return 1;
}
void DFS(int a){
    v[a] = 1;
    int i;
    for(i=0;i<F[a].size();i++){
        if(!v[F[a][i]])DFS(F[a][i]);
    }
}
int main(){
    int i, a, j, c;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        G[i].resize(c);
        for(j=0;j<c;j++)scanf("%d",&G[i][j]);
    }
    for(i=1;i<n;i++){
        int t1 = Prefix(G[i],G[i+1]), t2 = Prefix(G[i+1],G[i]);
        if(t1)continue;
        if(t2){
            printf("No\n");
            return 0;
        }
        for(j=0;;j++){
            if(G[i][j]!=G[i+1][j]){
                E[G[i][j]].push_back(G[i+1][j]);
                F[G[i+1][j]].push_back(G[i][j]);
                break;
            }
        }
    }
    for(i=1;i<n;i++){
        int t1 = Prefix(G[i],G[i+1]), t2 = Prefix(G[i+1],G[i]);
        if(t1)continue;
        if(t2){
            printf("No\n");
            return 0;
        }
        for(j=0;;j++){
            if(G[i][j]!=G[i+1][j]){
                if(G[i][j] > G[i+1][j])DFS(G[i][j]);
                break;
            }
        }
    }
    int cnt = 0;
    for(i=1;i<=K;i++){
        for(j=0;j<E[i].size();j++){
            int t1 = i, t2 = E[i][j];
            if(v[t1])t1 -= K;
            if(v[t2])t2 -= K;
            if(t1 > t2){
                printf("No\n");
                return 0;
            }
        }
        if(v[i])cnt++;
    }
    printf("Yes\n");
    printf("%d\n",cnt);
    for(i=1;i<=K;i++)if(v[i])printf("%d ",i);
}