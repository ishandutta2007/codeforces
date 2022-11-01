#include <cstdio>
int a[16];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int p=n;p>0;p/=2){
        for(int i=0;i<n;i+=p){
            int j;
            for(j=1;j<p;j++){
                if(a[i+j-1]>a[i+j]) break;
            }
            if(j==p){
                printf("%d",p);
                return 0;
            }
        }
    }
    printf("1");
    return 0;
}