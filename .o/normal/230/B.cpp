#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

typedef long long lld;
int TC; lld N;
#define M 1000000
lld SQ[M+5]; int C;
bool P[M+5];

int main(){
    lld i, j;

    for(i=2; i<=M; i++){
        if(P[i]) continue; SQ[++C] = i*i;
        for(j=i*i; j<=M; j+=i) P[j] = true;
    }

    scanf("%d",&TC); while(TC--){
        scanf("%I64d",&N);
        lld *rtf = std::lower_bound(SQ+1, SQ+C+1, N);
        if(*rtf != N) puts("NO");
        else puts("YES");
    }
    return 0;
}