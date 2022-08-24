#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000], C[20];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        for(j=0;j<20;j++){
            C[j]+= ((w[i]>>j)&1);
        }
    }
    long long res=0;
    for(i=1;i<=n;i++){
        int s=0;
        for(j=0;j<20;j++){
            if(C[j]>=i)s+=(1<<j);
        }
        res+=1ll*s*s;
    }
    printf("%lld\n",res);
}