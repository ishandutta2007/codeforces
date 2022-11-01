#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1000003;

int M[N], A[N], n, k, i, j, taken, lo = 1, hi = 1, siz, ret;

int main () {
    memset(M, 0, sizeof M);
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", A + i);
    ret = 1;
    siz = 1, i = 1, j = 1; taken = 1; M[A[1]]++;
    while (i <= n && j <= n) {
        while (taken <= k && j <= n) {
            j++; siz++;
            if (M[A[j]] == 0) taken++;
            M[A[j]]++;
        }
        if (siz - 1 > ret) {
        	ret = siz - 1;
            lo = i, hi = j - 1;
        }
        while (taken > k) {
        	M[A[i]]--;
        	if (M[A[i]] == 0) taken--;
        	i++; siz--;
        }
    }
    printf("%d %d\n", lo, hi);
    return 0;
}