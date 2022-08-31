#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010];
int n, i, m;
bool v[10100];
void DFS(int a){
    int i;
    v[a]=true;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
}
int main(){
    int a,b;
    scanf("%d%d",&n,&m);
    if(m!=n-1){
        printf("no\n");
        return 0;
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1);
    for(i=1;i<=n;i++)if(!v[i])break;
    if(i==n+1)printf("yes\n");
    else printf("no\n");
}