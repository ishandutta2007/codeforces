#include <cstdio>
int a[1030];
int main(){
    int n,m=1000000007,M=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(m>a[i]) m=a[i];
        if(M<a[i]) M=a[i];
    }
    printf("%d",M-m+1-n);
}