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
const int V = 1000100;

int L[V], R[V];
int pl[V], pr[V];
int minl[V], minr[V];
int maxl[V], maxr[V];
int nowl[V], nowr[V];
int ln, rn;

void addL(int p, int v) {
    L[++ln] = v;
    pl[ln] = p;
    nowl[ln] = nowl[ln - 1] + v;
    maxl[ln] = max(maxl[ln - 1], nowl[ln]);
    minl[ln] = min(minl[ln - 1], nowl[ln]);
}
void delL() {
    --ln;
}

void addR(int p, int v) {
    R[++rn] = v;
    pr[rn] = p;
    nowr[rn] = nowr[rn - 1] + v;
    maxr[rn] = max(maxr[rn - 1], nowr[rn]);
    minr[rn] = min(minr[rn - 1], nowr[rn]);
}
void delR() {
    --rn;
}

int n;
char s[V];
int main() {
    while (~scanf("%d", &n)) {
        scanf("%s", s);
        nowl[0] = nowr[0] = 0;
        minl[0] = minr[0] = 0;
        maxl[0] = maxr[0] = 0;
        ln = 0;
        rn = 0;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                if (rn > 0 && pr[rn] == p + 1) {
                    addL(p + 1, -R[rn]);
                    delR();
                }
                ++p;
            } else if (s[i] == 'L') {
                if (p > 0) {
                    if (ln > 0 && pl[ln] == p) {
                        addR(p, -L[ln]);
                        delL();
                    }
                    --p;
                }
            } else if (s[i] == '(') {
                if (ln > 0 && pl[ln] == p) delL();
                addL(p, 1);
            } else if (s[i] == ')') {
                if (ln > 0 && pl[ln] == p) delL();
                addL(p, -1);
            } else {
                if (ln > 0 && pl[ln] == p) delL();
            }
            bool ok = true;
            if (minl[ln] < 0) ok = false;
            if (minr[rn] < 0) ok = false;
            if (nowl[ln] != nowr[rn]) ok = false;
            int ans = -1;
            if (ok) ans = max(maxl[ln], maxr[rn]);
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}

/*
11
(RaRbR)L)L(
11
(R)R(R)Ra)c
19
(R(R(R(R)R)R)R)R(R)
5
))L)(
*/