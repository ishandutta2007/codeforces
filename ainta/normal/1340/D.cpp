#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
#define pii pair<int,int>
using namespace std;
int n, K;
vector<int>E[N_], Ch[N_];
vector<pii>Res;
void DFS(int a){
    int z = Res.back().second;
    int sz = Ch[a].size();
    for(int i=0;i<sz;i++){
        int x = Ch[a][i];
        pii t = Res.back();
        if(t.second==K){
            Res.push_back({a, (K-1)-sz});
            t = Res.back();
        }
        
        int col = t.second;
        Res.push_back({x,col+1});
        DFS(x);
        Res.push_back({a,col+1});
    }
    if(a==1)return;
    if(Res.back().second!=z-1)Res.push_back({a,z-1});
    
}
void Pre(int a, int pp){
    for(auto &x : E[a]){
        if(x==pp)continue;
        Pre(x,a);
        Ch[a].push_back(x);
    }
}
void Print(){
    printf("%d\n",Res.size());
    for(auto &x : Res)printf("%d %d\n",x.first,x.second);
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
    
    for(i=1;i<=n;i++){
        int t = E[i].size();
        K=max(K,t);
    }
    Res.push_back({1,0});
    if(n==1){
        Print();
        return 0;
    }
    Pre(1,0);
    DFS(1);
    Print();
}