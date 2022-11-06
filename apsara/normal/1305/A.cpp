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

int a[120], b[120], _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; ++i) printf("%d ", a[i]);puts("");
        for (int i = 0; i < n; ++i) printf("%d ", b[i]);puts("");
    }
    return 0;
}

/*
2
3
1 8 5
8 4 5
3
1 7 5
6 1 2
*/