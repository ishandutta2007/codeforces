#include<stdio.h>

#define INF 1000000007
int N, M;
int cnt[105]; bool Chk[105][100];
char S[105];
long long res;

int main(){
    int i, j;

    scanf("%d%d",&N,&M);
    for(i=1; i<=N; i++){
        scanf("%s",S+1);
        for(j=1; j<=M; j++){
            if(!Chk[j][S[j]-'A']) cnt[j]++;
            Chk[j][S[j]-'A'] = true;
        }
    }

    res = 1;
    for(i=1; i<=M; i++) res = (res * cnt[i]) % INF;
    printf("%I64d\n",res%INF);
    return 0;
}