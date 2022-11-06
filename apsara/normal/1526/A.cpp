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
int _, n, a[120];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);
        sort(a, a + n * 2);
        for (int i = 0; i < n; ++i) printf("%d %d ", a[i], a[n + i]);
        puts("");
    }
    return 0;
}

/*
3
3
1 2 3 4 5 6
2
123 456 789 10
1
6 9
*/