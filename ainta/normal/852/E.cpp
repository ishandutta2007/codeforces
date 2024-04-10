#include<cstdio>
#include<algorithm>
using namespace std;
int n, Deg[101000], Mod = 1000000007, po[101000], CL;
int main(){
    int i, a, b;
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    po[0]=1;
    for(i=1;i<=n;i++)po[i]=po[i-1]*2%Mod;
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        Deg[a]++,Deg[b]++;
    }
    for(i=1;i<=n;i++){
        if(Deg[i]==1)CL++;
    }
    printf("%lld\n", (1ll * po[n-CL] * (n-CL) + 1ll * po[n-CL+1] * CL)%Mod);
}