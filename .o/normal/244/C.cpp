#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define SZ 100005
int N;
int A[SZ], C[SZ][20];
int X[20];

struct S{
    int x, d;
    bool operator< (const S&t) const{
        return d<t.d;
    }
} W[25];

int Cnt[1<<20];
long long res;

int main(){
    int i, j;

    scanf("%d",&N);
    for(i=1; i<=N; i++){
        scanf("%d",A+i);
        for(j=0; j<20; j++){
            C[i][j] += C[i-1][j];
            if(A[i] & (1<<j)) C[i][j] ++;
        }
    }

    for(i=0; i<20; i++){
        for(j=1; j<=N; j++) if(A[j] & (1<<i)){
            X[i] = j;
            break;
        }
    }

    for(i=1; i<=N; i++){
        for(j=0; j<20; j++){ 
            W[j].x = j; 
            W[j].d = X[j];
        }

        std::sort(W, W+20);

        int v = 0;
        if(!Cnt[A[i]]++) res++;
        for(j=0; j<20; j++){
            if(W[j].d == 0 || W[j].d > N) continue;
            int x = W[j].x; v |= 1<<x;
            if(j < 19 && W[j].d == W[j+1].d) continue;
            if(!Cnt[v]++) res++;
        }

        for(j=0; j<20; j++){
            if(X[j] == i) while(++X[j] <= N){
                if(A[X[j]] & (1<<j)) break;
            }
        }
    }

    printf("%I64d\n",res);

    return 0;
}