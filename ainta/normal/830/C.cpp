#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define pii pair<int,int>
int n, w[110], N[110];
long long C, K, V[110], R, res;
priority_queue<pii>PQ;
int main(){
    int i;
    scanf("%d%lld",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        PQ.push(pii(-1,i));
    }
    int xx = -1;
    while(!PQ.empty()){
        pii tp = PQ.top();
        PQ.pop();
        int x = -tp.first, y = tp.second;
        //        printf("%d %d\n",x,y);
        if(xx != x && xx != -1){
            if(xx == 1)R = 0;
            if(R <= K){
                res = xx + (K-R)/C;
            }
            R += (x-xx) * C;
            xx = x;
        }
        if(xx == -1)xx = x;
        int num = (x-1+w[y])/x;
        R -= 1ll*x * (N[y] - num);
        C += num - N[y];
        N[y] = num;
        if(num!=1){
            int nx = (w[y]-1) / (num-1) + 1;
            PQ.push(pii(-nx, y));
        }
    }
    if(xx==1)R = 0;
    if(R <= K && xx!=-1){
        res = xx + (K-R)/C;
    }
    printf("%lld\n",res);
}