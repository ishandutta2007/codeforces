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

using namespace std;
typedef long long LL;

const int M = 10000;
int _, n, d;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &d);
        int x = (int) pow(1.0 * d, 0.5);
        bool ok = false;
        for (int i = max(0, x - M); i <= x + M; ++i) {
            int y = i + (d + i) / (i + 1);
            if (y <= n) ok = true;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
3
1 1
4 5
5 11
*/