#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, D[201000];
int main(){
    int i, res = 0;
    scanf("%d%d",&n,&K);
    printf("%d\n", (n-1)/K*2 + min((n-1)%K,2));
    for(i=2;i<=n;i++)printf("%d %d\n",i,max(i-K,1));
}