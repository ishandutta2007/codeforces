#include <stdio.h>
#include <string.h>
#include <algorithm>
 
const int N_ = 35;
typedef long long lld;
 
int N;
int res;
 
int main(){
    int i, j;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        for(j = 1; j < N - i; j++) res += i + 1;
        ++res;
    }
    printf("%d\n", res);
    return 0;
}