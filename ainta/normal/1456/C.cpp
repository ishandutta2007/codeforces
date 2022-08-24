#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, K;
int w[501000];
priority_queue<long long>PQ;
long long res;
int main(){
    int i;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1);
    for(i=0;i<=K;i++)PQ.push(0ll);
    for(i=n;i>=1;i--){
        long long t = PQ.top();
        PQ.pop();
        res += t;
        PQ.push(t + w[i]);
    }
    printf("%lld\n",res);
}