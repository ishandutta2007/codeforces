#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000], T[201000];
int n, M, D[201000], Dep[201000], TC;
void DFS1(int a, int pp){
    for(auto &x : E[a]){
        if(x==pp)continue;
        T[a].push_back(x);
        Dep[x]=Dep[a]+1;
        DFS1(x,a);
    }
}
bool DFS2(int a){
    if(T[a].empty()){
        D[a]=Dep[a];
        return true;
    }
    vector<int>Z;
    int Mn = 1e9, c = 0;
    for(auto &x: T[a]){
        if(!DFS2(x))return false;
        int d = D[x]-Dep[a];
        if(d>M)return false;
        if(d==M)c++;
        Mn = min(Mn,D[x]);
    }
    if(c>1 || (c>0&&a!=1))return false;
    D[a]=Mn;
    return true;
}
bool Pos(int MM){
    M=MM;
    return DFS2(1);
}
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        E[i].clear();
        T[i].clear();
    }
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS1(1,0);
    int b = 1, e = n, r = 0;
    while(b<=e){
        int mid = (b+e)>>1;
        if(Pos(mid)){
            r=mid;
            e=mid-1;
        }
        else b=mid+1;
    }
    printf("%d\n",r);
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}