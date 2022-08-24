#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, B[201000], Deg[201000], Dep[201000], vis[201000];
vector<int>E[201000], T, Ans;
long long A[201000];
long long res;
void DFS(int a, int d){
    T.push_back(a);
    for(auto &x : E[a]){
        DFS(x,d+1);
    }
    if(A[a]>= 0){
        vis[a]=1;
        res += A[a];
        if(B[a]!=-1)A[B[a]]+=A[a];
        Ans.push_back(a);
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&B[i]);
        if(B[i]!=-1)E[B[i]].push_back(i), Deg[i]++;
    }
    for(i=1;i<=n;i++){
        if(!Deg[i])DFS(i,1);
    }
    for(auto &t : T){
        if(!vis[t]){
            res += A[t];
            if(B[t]!=-1)A[B[t]]+=A[t];
            Ans.push_back(t);
        }
    }
    printf("%lld\n",res);
    for(auto &t : Ans)printf("%d ",t);
}