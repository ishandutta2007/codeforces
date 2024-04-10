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
int _, n, a[V], K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        bool ok = false;
        bool has = false;
        for (int i = 1; i <= n; ++i) if (a[i] == K) has = true;
        int pre = -2;
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= K) {
                if (i - pre <= 2) ok = true;
                pre = i;
            }
        }
        if (n == 1) ok = true;
        if (ok && has) puts("yes");
        else puts("no");
        /*
        int pre = 0;
        if (n == 1 && a[1] == K) ok = true;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == K && i > 1 && pre >= 0) ok = true;
            int t = a[i] >= K ? 1 : -1;
            if (pre > 0) pre += t;
            else pre = t;
        }
        pre = 0;
        for (int i = n; i >= 1; --i) {
            if (a[i] == K && i < n && pre >= 0) ok = true;
            int t = a[i] >= K ? 1 : -1;
            if (pre > 0) pre += t;
            else pre = t;
        }
        if (ok) puts("yes");
        else puts("no");
        */
    }
    return 0;
}

/*
5
5 3
1 5 2 6 1
1 6
6
3 2
1 2 3
4 3
3 1 2 3
10 3
1 2 3 4 5 6 7 8 9 10
*/