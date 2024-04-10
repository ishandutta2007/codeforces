#include<stdio.h>

#define N_ 100005
int N, D[N_];
int res;

int main(){
    freopen("INPUT.TXT","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);

    int i, k;

    scanf("%d",&N);
    for(i=1; i<=N; i++) scanf("%d",&D[i]);
    res = N;

    int sum = 0;
    for(i=1; i<=N; i++){
        if(D[i] <= 0) sum++;
    }

    for(i=1; i<N; i++){
        // 1..i < 0, i+1..N > 0
        if(D[i] > 0) ++sum; else if(D[i] < 0) --sum;
        if(sum < res) res = sum;
    }

    printf("%d\n",res);
    return 0;
}