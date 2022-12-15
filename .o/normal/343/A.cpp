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

ll A, B;
ll res;

int main() {
    int i, j, k;
    
    scanf("%I64d%I64d", &A, &B);

    while(1) {
        res += A / B;
        A = A % B;
        if(A == 0) break;
        swap(A, B);
    }    
    
    printf("%I64d\n", res);
    return 0;
}