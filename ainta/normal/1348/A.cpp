#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int i;
        scanf("%d",&n);
        long long s=0;
        for(i=1;i<=n;i++){
            if(i<n/2 || i==n)s+=1ll<<i;
            else s-=1ll<<i;
        }
        printf("%lld\n",s);
    }
}