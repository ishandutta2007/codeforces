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
const int V = 1000100;
int n, K;
int main() {
    while (~scanf("%d%d", &n, &K)) {
        if (K < 2 * n) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 1; i < n; ++i) printf("%d ", 2);
            printf("%d\n", K - 2 * n + 2);
            puts("1");
        }
    }
    return 0;
}

/*
1 4
3 4
3 8
*/