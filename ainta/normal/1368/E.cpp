#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, chk[501000], Mid[501000];
vector<int>E[501000];
void Solve(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)E[i].clear(), chk[i]=0, Mid[i]=0;
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
    }
    vector<int>Res;
    for(i=1;i<=n;i++){
        if(chk[i]){
            Res.push_back(i);
            continue;
        }
        if(Mid[i]){
            for(auto &x : E[i]){
                chk[x]=1;
            }
        }
        else{
            for(auto &x : E[i]){
                Mid[x]=1;
            }
        }
    }
    printf("%d\n",Res.size());
    for(auto &t : Res)printf("%d ",t);
    puts("");
}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}