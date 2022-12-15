#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N_ = 35;
typedef long long lld;

int N;
int H[N_], A[N_];
int res;

int main(){
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d%d", &H[i], &A[i]);
    
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++) if(i != j){
            // i , j 
            if(H[i] == A[j]) ++res;
        }
    }
    
    printf("%d\n", res);
    return 0;
}