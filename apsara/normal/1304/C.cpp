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

const int V = 110;
struct Node {
    int t, l, r;
}e[V];
bool cmp(Node x, Node y) {
    return x.t < y.t;
}
int _, n, L, R;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &L);
        R = L;
        bool ok = true;
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &e[i].t, &e[i].l, &e[i].r);
        sort(e, e + n, cmp);
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            int dt = e[i].t - pre;
            L -= dt, R += dt;
            if (R < e[i].l || L > e[i].r) {ok = false; break;}
            L = max(L, e[i].l), R = min(R, e[i].r);
            pre += dt;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
4
3 0
5 1 2
7 3 5
10 -1 0
2 12
5 7 10
10 16 20
3 -100
100 0 0
100 -50 50
200 100 100
1 100
99 -100 0
*/