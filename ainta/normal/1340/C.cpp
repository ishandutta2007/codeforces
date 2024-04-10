#include<cstdio>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
int n, m, w[10100], G, R, D[1010][10100];
queue<int>Q[1010];
void Put(int t, int a, int d){
    if(t>G)return;
    if(t==G){
        if(D[0][a]>d+1){
            D[0][a]=d+1;
            Q[0].push(a);
        }
        return;
    }
    if(D[t][a]>d){
        D[t][a]=d;
        Q[t].push(a);
    }
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+m+1);
    scanf("%d%d",&G,&R);
    for(i=0;i<=G;i++){
        for(j=1;j<=m;j++)D[i][j]=1e9;
    }
    D[0][1]=0;
    Q[0].push(1);
    while(1){
        int ck=0;
        for(i=0;i<G;i++){
            while(!Q[i].empty()){
                ck=1;
                int t = Q[i].front();
                Q[i].pop();
                if(t>1){
                    int d = w[t]-w[t-1];
                    Put(i+d, t-1, D[i][t]);
                }
                if(t<m){
                    int d = w[t+1]-w[t];
                    Put(i+d, t+1, D[i][t]);
                }
            }
        }
        if(!ck)break;
    }
    long long res=8e18;
    for(i=0;i<G;i++){
        if(D[i][m]<8e8){
            long long t = 1ll*(R+G)*D[i][m]+i;
            if(i==0)t-=R;
            res=min(res,t);
        }
    }
    if(res>7e18)res=-1;
    printf("%lld\n",res);
}