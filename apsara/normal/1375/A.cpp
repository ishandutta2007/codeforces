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
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (a[i] < 0) a[i] = -a[i];
            } else {
                if (a[i] > 0) a[i] = -a[i];
            }
        }
        for (int i = 0; i < n; ++i) printf("%d ", a[i]);puts("");
    }
    return 0;
}

/*
5
3
-2 4 3
5
1 1 1 1 1
5
-2 4 7 -6 4
9
9 7 -4 -2 1 -3 9 -4 -5
9
-4 1 9 4 8 9 5 1 -9
*/