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

const int N_ = 100005;
const int SZ = 1000005;
int N, X[N_], A, B;

int Bound[SZ];
int Table[SZ];


int main() {
    int i, j, k;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", X+i);
    scanf("%d%d", &A, &B);
    
    sort(X+1, X+N+1); N = unique(X+1, X+N+1) - (X+1);
    
    for(i = 1; i <= N; i++) {
        for(ll j = (ll)B / X[i] * X[i]; j <= A; j += X[i]) {
            if(j >= B) Bound[j - B] = X[i];
        }
    }
    
    for(i = 0, j = 1; i <= A - B; i++) {
        if(i == j) Table[j++] = Table[i - 1] + 1;
        if(Bound[i] > 0) while(j <= A - B && j < i + Bound[i]) Table[j++] = Table[i] + 1;
    }
    
    printf("%d\n", Table[A - B]);
    return 0;
}