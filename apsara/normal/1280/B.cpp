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

const int V = 70;
char s[V][V];

int solve(int n, int m) {
    bool hasA = false;
    bool hasP = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'A') hasA = true;
            if (s[i][j] == 'P') hasP = true;
        }
    }
    //printf("%d %d\n", hasA, hasP);
    if (!hasA) return -1;
    if (!hasP) return 0;
    int ans = 100;
    for (int i = 0; i < n; ++i) {
        bool allA = true;
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'P') allA = false;
        if (allA) ans = min(ans, 1 + (i > 0 && i + 1 < n));
    }
    for (int i = 0; i < m; ++i) {
        bool allA = true;
        for (int j = 0; j < n; ++j)
            if (s[j][i] == 'P') allA = false;
        if (allA) ans = min(ans, 1 + (i > 0 && i + 1 < m));
    }
    if (ans != 100) return ans;
    if (s[0][0] == 'A') return 2;
    if (s[0][m - 1] == 'A') return 2;
    if (s[n - 1][0] == 'A') return 2;
    if (s[n - 1][m - 1] == 'A') return 2;
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'A') return 3;
        if (s[i][m - 1] == 'A') return 3;
    }
    for (int i = 0; i < m; ++i) {
        if (s[0][i] == 'A') return 3;
        if (s[n - 1][i] == 'A') return 3;
    }
    return 4;
}

int n, m, _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int res = solve(n, m);
        if (res == -1) puts("MORTAL");
        else printf("%d\n", res);
    }
    return 0;
}

/*
5
3 3
AAA
PPP
PPP
7 8
AAPAAAAA
PPPPAAAA
PPPPAAAA
APAAPPPP
APAPPAPP
AAAAPPAP
AAAAPPAA
6 5
AAAAA
AAAAA
AAPAA
AAPAP
AAAPP
AAAPP
4 4
PPPP
PPPP
PPPP
PPPP
3 4
PPPP
PAAP
PPPP

*/