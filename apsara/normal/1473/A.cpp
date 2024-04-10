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
int _, a[1200], n, K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        if (a[n - 1] <= K || a[0] + a[1] <= K) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
3
5 3
2 3 2 5 4
3 4
2 4 4
5 4
2 1 5 3 6
*/