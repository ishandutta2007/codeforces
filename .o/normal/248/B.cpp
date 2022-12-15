/* 
 * File:   main.cpp
 * Author: tncks0121
 *
 * Created on 2012 12 28 (),  10:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uc;
typedef unsigned int ui;
const ui N_ = 100005;
const ui MOD = 210;

struct P{ 
    int n; uc m; 
    P() { }
    P(int n, uc m): n(n), m(m) { }
};

ui N;
uc Parent[N_][MOD];
uc Number[N_][MOD];
P Que[N_ * MOD];
ui Qf, Qr;

uc Res[N_];
ui res_n;

int main() {
    ui i, j;
    
    scanf("%d", &N);
    if(N < 3) {
        puts("-1");
        return 0;
    }
    
    memset(Number, 11, sizeof(Parent));
    
    Que[++Qr] = P( 0, 0 );
    while(Qf < Qr){
        P f = Que[++Qf];
        for(i = 0; i < 10; i++) if(f.n > 0 || i > 0){
            P g = P( f.n + 1, ((ui)f.m * 10 + i) % MOD );
            if(Number[g.n][g.m] > 9){
                Parent[g.n][g.m] = f.m;
                Number[g.n][g.m] = i;
                Que[++Qr] = g;
            }
            
            if(g.n == N && g.m == 0) goto print_result;
        }
    }
    
print_result:
    for(i = N, j = 0; i > 0; j = Parent[i--][j]){
        Res[++res_n] = Number[i][j];
    }
    
    while(res_n > 0) putchar(Res[res_n --] + '0');
    return 0;
}