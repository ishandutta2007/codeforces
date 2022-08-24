#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int D[201000][2], n, deg[201000];
long long x, y;
void DFS(int a, int pp){
    int i, x, t1 = 0, t2 = 0, t3 = 0, t;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        DFS(x,a);
        t1 += D[x][0];
        t = D[x][1]-D[x][0]+1;
        if(t2<t){
            t3=t2;
            t2=t;
        }
        else if(t3<t)t3=t;
    }
    D[a][1] = t1+t2;
    D[a][0] = t1+t2+t3;
}
int main(){
    int i, a, b;
    long long res, t;
    scanf("%d%lld%lld",&n,&x,&y);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    t = max(D[1][0],D[1][1]);
    if(x<=y){
        printf("%lld\n",t*x + (n-t-1)*y);
    }
    else{
        for(i=1;i<=n;i++)deg[i] = n-1-E[i].size();
        t = 0;
        a=0,b=0;
        for(i=1;i<=n;i++){
            if(deg[i]==0)a=1;
            if(deg[i]==1)b++;
        }
        if(b>2 || a==1)t=1;
        printf("%lld\n",t*x + (n-t-1)*y);
    }
}