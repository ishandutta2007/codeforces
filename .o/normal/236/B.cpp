#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define INF 1073741823
typedef long long llu;

int A, B, C;
llu res;
llu D[1000005];
int T[105][105];

llu get(int a, int b, int c){
    llu &ret = D[a*b*c]; 
    if(ret >= 0) return ret;
    ret = 1;
    for(int i=2; i<=100; i++){
        ret = (ret * (T[a][i] + T[b][i] + T[c][i] + 1)) & INF;
    }
    return ret;
}

llu real(int v){
    int cnt = 0, i;
    if(v == 1) return 1;
    for(i=1; i*i<v; i++){
        if(v % i == 0) cnt+=2;
    }
    if(i*i==v) cnt++;
    return cnt;
}

int main(){
    int i, j, k;

    scanf("%d%d%d",&A,&B,&C);
    
    for(i=2; i<=100; i++){
        bool ck = 0; int t = i;
        for(j=2; j<=i; ++j){
            while(t % j == 0) T[i][j]++, t/=j, ck = 1;
        }
        if(!ck) T[i][i] = 1;
    }

    memset(D, -1, sizeof(D));
    for(i=1; i<=A; i++) for(j=1; j<=B; j++) for(k=1; k<=C; k++){
        res = (res + get(i, j, k)) & INF;
    }

    printf("%lld\n",res);
    return 0;
}