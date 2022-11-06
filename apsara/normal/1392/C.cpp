#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 200100;
int _, n, a[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        LL ans = 0;
        for (int i = 1; i < n; ++i) if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
4
5 3 2 5
5
1 2 3 5 3
3
1 1 1
*/