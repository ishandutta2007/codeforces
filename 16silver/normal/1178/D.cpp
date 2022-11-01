#include <cstdio>
int sieve[1111];
int main(){
    sieve[0]=1;
    sieve[1]=1;
    for(int i=2;i<1111;){
        for(int j=i*2;j<1111;j+=i){
            sieve[j]=1;
        }
        for(i++;i<1111 && sieve[i];i++);
    }
    int n;
    scanf("%d",&n);
    int t;
    for(t=n;sieve[t];t++);
    printf("%d\n",t);
    printf("1 %d\n",n);
    for(int i=1;i<n;i++){
        printf("%d %d\n",i,i+1);
    }
    for(int i=1;i<=t-n;i++){
        printf("%d %d\n",i,n-i);
    }
}