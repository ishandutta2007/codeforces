#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define pii pair<int,int>
priority_queue<pii>PQ;
int n, K, w[301000], res[301000];
long long S;
int main(){
    int i, pv = 1;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=K+1;i<=K+n;i++){
        while(pv <= n && pv <= i){
            PQ.push(pii(w[pv],pv));
            pv++;
        }
        pii tp = PQ.top();
        PQ.pop();
        S += 1ll * tp.first * (i-tp.second);
        res[tp.second] = i;
    }
    printf("%lld\n",S);
    for(i=1;i<=n;i++)printf("%d ",res[i]);
}