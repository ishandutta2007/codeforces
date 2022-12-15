#include <stdio.h>
#include <string.h>

const int N_ = 1000005;

int N;
int D[N_];

int gcd (int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int div[N_], div_n;
int res = 1;
int T[N_];

int main(){
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &D[i]);
    
    for(i = 1; i <= N; i++){
        int &n = D[i]; div_n = 0;
        if(n == 1) continue;
        for(j = 2; j * j <= n; j++) if(n % j == 0){
            div[ ++div_n ] = j;
            while(n % j == 0) n /= j;
        }
        if(n > 1){ // prime
            div[ ++div_n ] = n;
        }
        
        int tmp = 0;
        for(j = 1; j <= div_n; j++){
            if(T[ div[j] ] > tmp) tmp = T[ div[j] ];
        }
        
        ++tmp;
        if(tmp > res) res = tmp;
        for(j = 1; j <= div_n; j++){
            if(T[ div[j] ] < tmp) T[ div[j] ] = tmp;
        }
    }
    
    printf("%d\n", res);
    return 0;
}