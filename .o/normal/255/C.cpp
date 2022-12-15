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

#define SZ 4005
int N;
int D[SZ];
int G[SZ][SZ];
int T[SZ][SZ];
int res;

int main(){
    int i, j;
    
    scanf("%d",&N);
    for(i=1; i<=N; i++){
        scanf("%d",D+i);
        for(j = 1; j <= i; j++) if(D[i] == D[j]){
            G[i][j] = j; G[j][i] = i;
        }
    }
    
    if(N == 1){
        puts("1");
        return 0;
    }
    
    for(i = 1; i <= N; i++) for(j = 1; j <= N; j++){
        if(G[i][j] < G[i][j-1]) G[i][j] = G[i][j-1];
    }
    
    for(i = 1; i <= N; i++) for(j = i+1; j <= N; j++){
        int val = T[G[j][i-1]][i] + 1;
        if(val > 2) T[i][j] = val; else T[i][j] = 2;
        if(res < T[i][j]) res = T[i][j];
    }
    
    printf("%d\n",res);
    return 0;
}