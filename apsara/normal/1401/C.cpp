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
const int V = 100100;

int gcd(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    return gcd(y, x % y);
}

int _, n, a[V], b[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int mi = a[0];
        for (int i = 1; i < n; ++i) mi = min(mi, a[i]);
        for (int i = 0; i < n; ++i) b[i] = a[i];
        sort(b, b + n);
        bool ok = true;
        for (int i = 0; i < n; ++i) if (a[i] != b[i] && (a[i] % mi != 0 || b[i] % mi != 0)) ok = false;
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
4
1
8
6
4 3 6 6 2 9
4
4 5 6 7
5
7 5 2 2 4
*/