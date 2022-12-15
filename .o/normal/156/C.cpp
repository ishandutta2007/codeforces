#include<stdio.h>
#include<string.h>

#define L 100
#define MOD 1000000007
int TC;
int T[L+5][L*30];

int main(){
    int i, j, k;

    T[0][0] = 1;
    for(i=1; i<=L; i++) for(j=0; j<i*26; ++j) for(k=0; k<26; k++) if(j >= k){
        T[i][j] += T[i-1][j-k]; T[i][j] %= MOD;
    }

    scanf("%d",&TC); while(TC--){
        char str[105]; scanf("%s",str);
        int len = strlen(str), sum = 0;
        for(i=0; i<len; i++) sum += str[i] - 'a';
        printf("%d\n",(T[len][sum]+MOD-1)%MOD);
    }
    return 0;
}