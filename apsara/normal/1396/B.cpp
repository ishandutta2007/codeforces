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
        int s = 0, mx = a[0];
        for (int i = 0; i < n; ++i) s += a[i], mx = max(mx, a[i]);
        if (mx > s - mx) puts("T");
        else {
            if (s % 2 == 1) puts("T");
            else puts("HL");
        }
    }
    return 0;
}

/*
2
1
2
2
1 1
*/