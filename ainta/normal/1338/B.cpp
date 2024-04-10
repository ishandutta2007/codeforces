#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define N_ 101000
using namespace std;
int n, Col[N_];
vector<int>E[N_];
void DFS(int a, int pp, int col){
    Col[a]=col;
    for(auto &x : E[a]){
        if(!Col[x])DFS(x, a, 3-col);
    }
}
int main(){
    int i,a ,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    int Leaf = 0;
    set<int>Set;
    for(i=1;i<=n;i++){
        if(E[i].size()==1){
            Leaf++;
            Set.insert(E[i][0]);
        }
    }
    int R2 = n-1 +Set.size()-Leaf;
    DFS(1,0,1);
    Set.clear();
    for(i=1;i<=n;i++){
        if(E[i].size()==1){
            Set.insert(Col[i]);
        }
    }
    int R1=3;
    if(Set.size()==1)R1=1;
    printf("%d %d\n",R1,R2);
}