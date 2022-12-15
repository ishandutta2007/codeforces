#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

#define N_ 70
struct S{
    int rat;
    char name[25];
    bool operator< (const S&t) const{ return rat > t.rat; }
} D[N_];
int N, M, X, A, B, C;
bool Chk[4][N_];
int Cnt[4];

int main(){
    freopen("INPUT.TXT","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);

    int i, j, k;

    scanf("%d%d%d%d%d",&N,&X,&A,&B,&C);
    for(i=1; i<=N; i++) scanf("%s%d",&D[i].name,&D[i].rat);
    std::sort(D+1, D+N+1);
    
    M = N>>2;
    for(i=1; i<=M; i++){
        printf("Group %c:\n",i+64);
        for(j=0; j<=3; j++){
            int Y = (X * A + B) % C; X = Y;
            for(Cnt[j] = 0, k=1; k<=M; k++) if(!Chk[j][k]){
                if(Cnt[j] == Y % (M - i + 1)) break; ++Cnt[j];
            }
            Chk[j][k] = true; printf("%s\n",D[k+j*M].name);
        } 
    }
    return 0;
}