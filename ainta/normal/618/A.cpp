#include<stdio.h>
int n, w[100], c;
int main(){
    int i;
    scanf("%d",&n);
    while(n){
        w[++c] = n%2;
        n/=2;
    }
    for(i=c;i>=1;i--)if(w[i])printf("%d ",i);
}