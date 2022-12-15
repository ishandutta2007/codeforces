#include <stdio.h>
#include <queue>
#include <vector>

const int M_ = 1005;
using namespace std;

int N, M;
int A[M_];

priority_queue < int > H;
long long res1, res2;

int main(){
    int i, j;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= M; i++) scanf("%d", &A[i]);
    
    // res1
    for(i = 1; i <= M; i++) H.push ( A[i] );
    for(i = 1; i <= N; i++){
        int p = H.top(); H.pop(); res1 += p;
        if(p > 1) H.push (p - 1);
    }
    
    // res2
    while( ! H.empty() ) H.pop();
    for(i = 1; i <= M; i++) H.push ( -A[i] );
    for(i = 1; i <= N; i++){
        int p = -H.top(); H.pop(); res2 += p;
        if(p > 1) H.push ( -(p - 1) );
    }
    
    printf("%lld %lld\n", res1, res2);
    return 0;
}