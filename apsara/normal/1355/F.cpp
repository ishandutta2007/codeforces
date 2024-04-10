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
const int V = 1000000;

int p[V + 10], pn, vis[V + 10];

void init() {
    memset(vis, 0, sizeof(vis)); pn = 0;
    for (int i = 2; i <= V; ++i) {
        if (vis[i]) continue;
        p[pn++] = i;
        for (int j = i * 2; j <= V; j += i) vis[j] = 1;
    }
    //for (int i = 0; i < 50; ++i) printf("%d\n", p[i]);
}

const int Q = 22;
const LL ooo = 1000000000;
const LL oo = ooo * ooo;

int rp[V], rc[V], rn;
int qp[V], qc[V], qn;

void solve() {
    int gd = 1;
    rn = 0;
    int pos = 0;
    for (int i = 0; i < Q; ++i) {
        qn = rn;
        LL q = 1;
        for (int j = 0; j < rn; ++j) {
            qp[j] = rp[j];
            qc[j] = rc[j] + 1;
            for (int k = 0; k < qc[j]; ++k) q *= qp[j];
        }
        while (oo / q >= p[pos]) {
            q *= p[pos];
            qp[qn] = p[pos];
            qc[qn++] = 1;
            ++pos;
        }
        printf("? %I64d\n", q);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        //for (int i = 0; i < qn; ++i) printf("%d %d\n", qp[i], qc[i]);
        rn = 0;
        for (int i = 0; i < qn; ++i) {
            int cnt = 0;
            while (res % qp[i] == 0) {
                res /= qp[i];
                ++cnt;
            }
            if (cnt == qc[i]) {
                gd /= qc[i];
                gd *= qc[i] + 1;
                rp[rn] = qp[i];
                rc[rn++] = qc[i];
            }
        }
        //for (int i = 0; i < rn; ++i) printf("%d %d\n", rp[i], rc[i]);
    }
    if (gd == 1) puts("! 8");
    else printf("! %d\n", gd * 2);
}

int _;

int main() {
    init();
    scanf("%d", &_);
    while (_--) {
        solve();
    }
    return 0;
}

/*

*/