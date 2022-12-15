#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>

const int N_ = 1000005;
using namespace std;

int N;
char D[N_];
bool Chk[N_];
int sum;

int main(){
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        int x; scanf("%d", &x);
        D[i] = x; sum = (sum + x) % 3;
    }
    
    sort( D + 1, D + N + 1, greater<int>() );
    if(D[N] != 0) return 0 & puts("-1");
    
    int chk;
    if(sum > 0){
        chk = 0;
        for(i = N; i > 0; i--) if(D[i] % 3 == sum) {
            Chk[i] = true; chk = 1; break;
        }
        if(chk == 0){
            for(i = N; i > 0 && chk < 2; i--) if(D[i] % 3 == 3 - sum) {
                Chk[i] = true; ++chk;
            }
            if(chk < 2) return 0 & puts("-1");
        }
    }
    
    for(i = 1; i <= N; i++) {
        if(!Chk[i] && D[i] != 0) break;
    }
    if(i > N) puts("0");
    for( ; i <= N; i++) {
        if(!Chk[i]) putchar( D[i] + '0' );
    }
    return 0;
}