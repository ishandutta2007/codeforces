#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int X[100010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        X[a]++, X[b]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(X[i] == 1) ans++;
    printf("%d\n", ans);
    return 0;
}