#include <stdio.h>
#include <string.h>

const int N_ = 1005;

int A[N_][N_], B[N_][N_];
int TableA[N_][N_], TableB[N_][N_];
bool DirA[N_][N_], DirB[N_][N_];
int N;

int min (int a, int b){
    return a < b ? a : b;
}

void solve( int (*D)[N_], int (*T)[N_], bool (*P)[N_] ){
    int i, j;
    
    T[1][1] = D[1][1];
    for(i = 2; i <= N; i++) {
        T[1][i] = T[1][i - 1] + D[1][i]; P[1][i] = true;
        T[i][1] = T[i - 1][1] + D[i][1]; P[i][1] = false;
    }
    
    for(i = 2; i <= N; i++) for(j = 2; j <= N; j++){
        int r = T[i][j - 1], d = T[i - 1][j];
        T[i][j] = D[i][j];
        if(r < d) P[i][j] = true, T[i][j] += r;
        else P[i][j] = false, T[i][j] += d;
    }
}

char Res[N_ * 5];
void result ( int val, bool (*P)[N_] ){
    int i, j, rn = 0;
    for(i = j = N; i > 0 && j > 0 && rn <= 2 * N; ){
        if(P[i][j]) --j, Res[++rn] = 'R'; 
        else --i, Res[++rn] = 'D';
    }
    
    if(val < 0) val = 1;
    printf("%d\n", val);
    for(i = rn - 1; i > 0; i--) putchar( Res[i] );
}

int main(){
    int i, j, x = -1, y = -1;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) for(j = 1; j <= N; j++){
        int v; scanf("%d", &v);
        if(v == 0) A[i][j] = B[i][j] = 1, x = i, y = j;
        else{
            for(; (v % 2) == 0; v /= 2) ++A[i][j];
            for(; (v % 5) == 0; v /= 5) ++B[i][j];
        }
    }
    
    solve( A, TableA, DirA );
    solve( B, TableB, DirB );
    
    if( min(TableA[N][N], TableB[N][N]) > 1 && x > 0){
        puts("1");
        for(i = 2; i <= x; i++) putchar('D');
        for(i = 2; i <= y; i++) putchar('R');
        for(i = x + 1; i <= N; i++) putchar('D');
        for(i = y + 1; i <= N; i++) putchar('R');
    }else if(TableA[N][N] < TableB[N][N]) result ( TableA[N][N], DirA );
    else result ( TableB[N][N], DirB );
    
    return 0;
}