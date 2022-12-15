#include<stdio.h>
#include<algorithm>

#define N_ 1005
int N, K;
int D[N_], A[N_];
int res;

bool cmp(const int&a, const int&b){
    return D[a] > D[b];
}

int main(){
    freopen("INPUT.TXT","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);
    
    int i;

    scanf("%d%d",&N,&K);
    for(i=1; i<=N; i++) scanf("%d",&D[i]), A[i] = i;
    std::sort(A+1, A+N+1, cmp);
    printf("%d\n",D[A[K]]);
    for(i=1; i<=K; i++) printf("%d ",A[i]);
    return 0;
}