#include<cstdio>
using namespace std;
int main(){
    int t,n;
    long long ans=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=1LL*n*(n+1)/2;
        for(int i=1;i<=n;i<<=1){
            ans-=(i+i);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}