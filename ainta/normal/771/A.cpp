#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, m;
vector<int>E[150010];
map<int,int>Map[150010];
bool v[150010];
vector<int>V;
void DFS(int a){
    v[a]=true;
    V.push_back(a);
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int i, a, b, j, k;
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        Map[a][b]=Map[b][a]=1;
    }
    long long s = 0;
    for(i=1;i<=n;i++){
        if(!v[i]){
            V.clear();
            DFS(i);
            int cnt = V.size();
            s += 1ll*cnt*(cnt-1)/2;
            if(s > m){
                printf("NO\n");
                return 0;
            }
            int ck = 0;
            for(j=0;j<V.size();j++)for(k=j+1;k<V.size();k++)if(!Map[V[j]][V[k]])ck = 1;
            if(ck){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
}