#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

int n;

int main() {
    int tot = 0, mx = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        tot += x;
    }
    tot *= 2;
    int o = tot / n;
    while(o * n <= tot) o++;
    printf("%d\n", max(mx, o));
    return 0;
}