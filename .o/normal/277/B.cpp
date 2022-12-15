#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;
const int N_ = 305, M_ = 305;
const int INF = 987654321;
#define sq(x) x*x

int N, M;

int main(){
    int i, j, k;
    
    scanf("%d%d", &N, &M);
    
    if(M == 3){
        if(N == 3){
            puts("0 0");
            puts("0 10");
            puts("10 0");
        }else if(N == 4){
            puts("0 0");
            puts("0 3");
            puts("3 0");
            puts("1 1");
        }else if(N == 5){
            puts("-1");
        }else if(N == 6){
            puts("-1");
        }
        return 0;
    }
    
    for(i = 1; i <= M; i++){
        printf("%d %d\n", i, sq(i));
    }
    
    i = 100000; j = 0; k = M * 2 - N;
    while(j < N - M){
        ++j; ++k;
        printf("%d %d\n", i--, k*k);
    }
    return 0;
}