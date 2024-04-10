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
const int V = 300100;
char s[V];
int a[V], _, n, K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 0; i < K; ++i) a[i] = -1;
        scanf("%s", s);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int j = i % K;
            if (s[i] == '?') continue;
            if (a[j] != -1 && a[j] != s[i] - '0') ok = false;
            a[j] = s[i] - '0';
        }
        int c0 = 0, c1 = 0;
        for (int i = 0; i < K; ++i) {
            if (a[i] == 0) ++c0;
            if (a[i] == 1) ++c1;
        }
        if (c0 > K / 2 || c1 > K / 2) ok = false;
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
9
6 4
100110
3 2
1?1
3 2
1?0
4 4
????
7 4
1?0??1?
10 10
11??11??11
4 2
1??1
4 4
?0?0
6 2
????00
*/