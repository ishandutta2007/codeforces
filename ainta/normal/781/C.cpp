#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, K;
bool v[201000];
vector<int>E[201000];
int L[401000], cnt, C[201000];
void DFS(int a){
    v[a]=true;
    int i;
    L[cnt++] = a;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]]){
            DFS(E[a][i]);
            L[cnt++] = a;
        }
    }
}
int main(){
    int i, j;
    scanf("%d%d%d",&n,&m,&K);
    for(i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1);
    if(cnt==1)L[cnt++] = 1;
    for(i=0;i<cnt-1;i++)C[i%K]++;
    int pv = 0;
    for(i=0;i<K;i++){
        printf("%d ",C[i]);
        for(j=0;j<C[i];j++){
            printf("%d ",L[pv++]);
        }
        printf("\n");
    }
}