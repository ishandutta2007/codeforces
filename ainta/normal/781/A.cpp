#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int n, M, w[201000];
void DFS(int a, int col, int pp){
    int i, x, cc = 1;
    w[a] = col;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x == pp)continue;
        while(w[a] == cc || w[pp] == cc)cc++;
        DFS(x, cc, a);
        cc++;
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
    for(i=1;i<=n;i++){
        M = max(M, (int)E[i].size() + 1);
    }
    printf("%d\n",M);
    DFS(1,1,0);
    for(i=1;i<=n;i++)printf("%d ",w[i]);
}