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

const int V = 510 * 4;
//'U', 'D', 'L' or 'R'.

char DIR[] = {"UDLR"};
char trans(int id) {
    return DIR[id];
}

int f[V], N;
vector<int> c[V];
vector<int> U, D, L, R, MID;

void add(int cnt, vector<int> vv) {
    if (cnt == 0) return;
    f[N] = cnt;
    c[N] = vv;
    ++N;
}
int n, m, K;
int af[V];
vector<int> ans[V];


int main() {
    U.PB(0);
    D.PB(1);
    L.PB(2);
    R.PB(3);
    MID.PB(3);
    MID.PB(0);
    MID.PB(1);
    while (~scanf("%d%d%d", &n, &m, &K)) {
        if (K > 4 * n * m - 2 * n - 2 * m) {
            puts("NO");
            continue;
        }
        N = 0;
        add(m - 1, R);
        add(m - 1, L);
        for (int i = 1; i < n; ++i) {
            add(1, D);
            add(m - 1, MID);
            add(m - 1, L);
        }
        add(n - 1, U);
        puts("YES");
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            int use = min(K / (int) c[i].size(), f[i]);
            if (use != 0) {
                af[cnt] = use;
                ans[cnt++] = c[i];
                K -= use * c[i].size();
            }
            //printf("%d %d %d %d\n", i, f[i], (int)c[i].size(), K);
            if (use != f[i] && K != 0) {
                vector<int> tmp;
                for (int j = 0; j < K; ++j) tmp.PB(c[i][j]);
                af[cnt] = 1;
                ans[cnt++] = tmp;
                K = 0;
            }
            if (K == 0) break;
        }
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; ++i) {
            printf("%d ", af[i]);
            for (int j = 0; j < ans[i].size(); ++j)
                printf("%c", trans(ans[i][j]));
            puts("");
        }
    }
    return 0;
}

/*
3 3 4
3 3 1000000000
3 3 8
4 4 9
3 4 16

*/