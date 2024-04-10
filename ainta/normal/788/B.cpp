#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010000];
int n, m, T[1010000];
bool v[1010000];
void DFS(int a){
    v[a]=true;
    int i;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
}
long long Res;
int main(){
    int i, a, b, ck = 0, cc = 0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(a==b){
            cc++;
            T[a]++;
        }
        E[a].push_back(b);
        E[b].push_back(a);
    }
    Res = 1ll * cc * (m-cc) + 1ll * cc * (cc-1) / 2;
    for(i=1;i<=n;i++){
        if(!E[i].empty()){
            if(!v[i] && ck){
                printf("0\n");
                return 0;
            }
            ck = 1;
            DFS(i);
        }
    }
    for(i=1;i<=n;i++){
        int t = E[i].size() - T[i]*2;
        Res += 1ll*t*(t-1)/2;
    }
    printf("%lld\n",Res);
}