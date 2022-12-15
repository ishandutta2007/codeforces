#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <limits.h>
 
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;

const int N_ = 1005;

int N, A[N_];

int gcd (int a, int b) {
    int c;
    while(b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int i, j, k;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", A+i);
    
    int g = A[1], M = A[1];
    for(i = 2; i <= N; i++) g = gcd(g, A[i]), M = max(M, A[i]);
    
    puts((M / g - N) % 2 ? "Alice" : "Bob");
    
    return 0;
}