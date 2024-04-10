#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> pii;
int n;
long long w[101000];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    if(n==1){
        printf("1 1\n");
        printf("%lld\n",-w[1]);
        printf("1 1\n");
        printf("%lld\n",0ll);
        printf("1 1\n");
        printf("%lld\n",0ll);
    }
    else{
        printf("%d %d\n",1,n-1);
        for(i=1;i<=n-1;i++){
            printf("%lld ",w[i]*(n-1));
        }
        puts("");
        printf("%d %d\n",1,n);
        for(i=1;i<=n;i++){
            printf("%lld ",-w[i]*n);
        }
        puts("");
        printf("%d %d\n",n,n);
        printf("%lld\n",w[n]*(n-1));
    }
}