#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;

int n, S[233], F[233];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        memset(F, 0, sizeof F);
        for(int j = 1; j <= k; j++) {
            int a;
            scanf("%d", &a);
            F[a] = 1;
        }
        for(int j = 1; j <= 100; j++) S[j] += F[j];
    }
    for(int j = 1; j <= 100; j++) if(S[j] == n) printf("%d ", j);
    putchar('\n');
    return 0;
}