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

int _, a[12], b[12];

int main() {
    scanf("%d", &_);
    while (_--) {
        for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < 3; ++i) scanf("%d", &b[i]);
        int cnt1 = min(a[2], b[1]);
        a[2] -= cnt1, b[1] -= cnt1;
        int cnt2 = a[0] + b[0] + min(a[1], b[1]) + min(a[2], b[2]);
        cnt2 = max(0, a[0] + a[1] + a[2] - cnt2);
        int ans = 2 * (cnt1 - cnt2);
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
2 3 2
3 3 1
4 0 1
2 3 0
0 0 1
0 0 1
*/