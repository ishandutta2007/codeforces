#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 1000200;

int main() {
    int n;
    scanf("%d", &n);
    int k[MAXN];
    for (int i = 0; i < MAXN; i++)
        k[i] = 0;
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        k[w]++;
    }
    int ans;
    for (int i = 0; i < MAXN - 1; i++) {
        k[i + 1] += k[i] / 2;
        k[i] = k[i] % 2;
        ans += k[i];
    }
    printf("%d\n", ans);
    return 0;
}