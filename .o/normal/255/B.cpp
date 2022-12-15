#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<memory.h>
#include<map>
#include<assert.h>
#include<list>
#include<queue>
 
int x, y, N;
char D[1000005];
int C[2];
 
int main(){
    scanf("%s",D+1);
    N = strlen(D+1);
    for(int i = 1; i <= N; i++){
        C[D[i] - 'x'] ++;
    }
    if(C[0] < C[1]){
        for(int i = C[1] - C[0]; i--; ) putchar('y');
    }else{
        for(int i = C[0] - C[1]; i--; ) putchar('x');
    }
    return 0;
}