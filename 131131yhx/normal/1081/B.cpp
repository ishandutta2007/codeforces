#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#define M 200010

using namespace std;

int n, A[M], S[M], C[M], D[M];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]), S[A[i]]++;
    for(int i = 0; i < n; i++)
        if(S[i] % (n - i) != 0) {
            puts("Impossible");
            return 0;
        }
    puts("Possible");
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(C[A[i]]++ % (n - A[i]) == 0) D[A[i]] = ++cnt;
        printf("%d ", D[A[i]]);
    }
    putchar('\n');
    return 0;
}