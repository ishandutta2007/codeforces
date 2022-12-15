#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

const int N_ = 1000005;
int N, K;
int A[N_];
int B[N_];
int cnt;
int C[N_];
set<int> D[N_];

int main(){
    int i, j;
    
    scanf("%d%d", &N, &K);
    for(i = 1; i <= K; i++){
        cnt=0;
        for(j = i; j <= N; j += K) A[j] = i, ++cnt;
        B[i] = j - K;
        if(cnt <= 2) return 0 & puts("-1");
    }
    
    for(i = 1; i < K; i++){
        std::swap(A[B[i]], A[B[i+1]]);
    }
    
    for(i = 1; i <= N; i++){
        if(C[A[i]] == 0) C[A[i]] = i;
        else {
            D[A[i]].insert(i - C[A[i]]);
            C[A[i]] = i;
        }
    }
    
    for(i = 1; i <= K; i++){
        if(D[i].size() == 1) return 0 & puts("-1");
    }
    
    for(i = 1; i <= N; i++){
        printf("%d ",A[i]);
    }
    return 0;
}