
#include<cstdio>
#include<algorithm>
    int K, a, b;
    int main(){
        scanf("%d%d%d",&K,&a,&b);
        if(K>a && K>b){
            printf("-1\n");
            return 0;
        }
        if(K>a && b%K){
            printf("-1\n");
            return 0;
        }
        if(K>b && a%K){
            printf("-1\n");
            return 0;
        }
        printf("%d\n",a/K+b/K);
    }