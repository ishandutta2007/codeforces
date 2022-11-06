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

int _, a[120], c[120];
int main() {
    scanf("%d", &_);
    while (_--) {
        for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < 5; ++i) scanf("%d", &c[i]);
        for (int i = 0; i < 3; ++i) a[i] -= c[i];
        c[3] -= min(c[3], a[0]);
        c[4] -= min(c[4], a[1]);
        a[2] -= c[3];
        a[2] -= c[4];
        bool ok = true;
        for (int i = 0; i < 3; ++i) if (a[i] < 0) ok = false;
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
7
1 2 3
1 2 3 0 0
2 2 3
1 2 3 1 0
2 2 3
1 2 3 0 1
1 2 5
1 2 3 1 1
0 0 0
0 0 0 0 0
0 0 4
1 0 0 0 0
13 37 42
0 0 0 40 47
*/