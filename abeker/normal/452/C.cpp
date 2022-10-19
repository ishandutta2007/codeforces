#include <cstdio>
#include <iostream>
using namespace std;

typedef long double ld;

ld calc(int a, int b) {
    ld res = 1;
    for (int i = 0; i < b; i++) {
        res *= (a - i);
        res /= (i + 1);
    }
    return res;
}
  
int N, M;

void load() {
    scanf("%d%d", &N, &M);    
}

ld solve() {
    ld denom = calc(N * M, N), sol = 0;
    for (int j = 1; j <= N && j <= M; j++) {
        ld curr = (ld)j * j / N; 
        curr *= calc(M, j) * calc((N - 1) * M, N - j);
        curr /= denom;
        sol += curr;
    }
    return sol;
}  

int main() {
    load();
    printf("%.16lf\n", (double)solve());
    return 0;
}