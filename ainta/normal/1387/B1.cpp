#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, par[N_], chk[N_], w[N_];
vector<int>E[N_], T;
void DFS(int a, int pp){
    T.push_back(a);
    par[a]=pp;
    for(auto &x:E[a]){
        if(x==pp)continue;
        DFS(x,a);
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++)w[i]=i;
    DFS(1,0);
    reverse(T.begin(),T.end());
    int res=0;
    for(auto &t : T){
        if(!chk[t]){
            int x = par[t];
            if(!x)x=E[t][0];
            chk[t]=chk[x]=1;
            swap(w[t],w[x]);
            res+=2;
        }
    }
    printf("%d\n",res);
    for(i=1;i<=n;i++){
        printf("%d ",w[i]);
    }
}