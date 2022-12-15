#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N_ 100
int N;

int main(){
    int i, j;
    scanf("%d",&N);
    if(N % 2) puts("-1");
    else for(i=0; i<N; i++) printf("%d ",(i>>1)*2+2-i%2);
    return 0;
}