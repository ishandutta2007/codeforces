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
vector<int> g[V], Q[V];
int cnt[V];

bool cmp(int x, int y) {
    return cnt[x] > cnt[y];
}
int _, n, A, B;
int a[V], b[V], c[V], d[V], ans[V];

bool check() {
    for (int i = 1; i <= n + 1; ++i) c[i] = d[i] = 1;
    for (int i = 1; i <= n; ++i) c[a[i]++], d[ans[i]++];
    int C = 0, D = 0;
    for (int i = 1; i <= n; ++i) if (a[i] == ans[i]) ++C;
    for (int i = 1; i <= n; ++i) D += max(c[i], d[i]);
    if (C != A && D != B) {
        puts("Wrong");
        while (1);
        return false;
    }
    return true;
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &A, &B);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        /*
        n = 7;
        A = rand() % n;
        B = rand() % (n - A + 1) + A;
        for (int i = 1; i <= n; ++i) a[i] = rand() % (n + 1) + 1;
        */
        if (A == n) {
            puts("YES");
            for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
            continue;
        }
        for (int i = 1; i <= n + 1; ++i) g[i].clear();
        for (int i = 1; i <= n; ++i) g[a[i]].PB(i);
        int miss = -1;
        for (int i = 0; i <= n; ++i) Q[i].clear();
        for (int i = 1; i <= n + 1; ++i) {
            cnt[i] = g[i].size();
            if (cnt[i] == 0) miss = i;
            else Q[cnt[i]].PB(i);
        }
        for (int i = 1; i <= n; ++i) ans[i] = -1;
        int cur = 0;
        for (int i = n; i > 0 && cur != A; --i) {
            for (int j = 0; j < Q[i].size() && cur != A; ++j) {
                int id = Q[i][j];
                int pos = g[id][cnt[id] - 1];
                ans[pos] = a[pos];
                --cnt[id];
                Q[cnt[id]].PB(id);
                ++cur;
            }
        }
        for (int i = 1; i <= n + 1; ++i) b[i] = i;
        sort(b + 1, b + n + 2, cmp);
        int mx = cnt[b[1]];
        int R = n - A;
        cur = 0;
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j < cnt[b[i]]; ++j) {
                c[cur++] = b[i];
            }
        }
        cur = mx % R;
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j < cnt[b[i]]; ++j) {
                d[cur] = b[i];
                cur = (cur + 1) % R;
            }
        }
        int diff = 0;
        for (int i = 0; i < R; ++i) {
            if (c[i] != d[i]) {
                ++diff;
            }
        }
        if (diff < B - A) {
            puts("NO");
        } else {
            puts("YES");
            //for (int i = 1; i <= R; ++i) printf("%d ", c[i - 1]); puts("");
            //for (int i = 1; i <= R; ++i) printf("%d ", d[i - 1]); puts("");
            diff = 0;
            for (int i = 0; i < R && diff < B - A; ++i) {
                if (c[i] != d[i]) {
                    ++diff;
                    int id = c[i];
                    //printf("%d %d\n", id, cnt[id]);
                    //continue;
                    int pos = g[id][cnt[id] - 1];
                    ans[pos] = d[i];
                    --cnt[id];
                }
            }
            for (int i = 1; i <= n; ++i) if(ans[i] == -1) ans[i] = miss;
            for (int i = 1; i <= n; ++i) printf("%d ", ans[i]); puts("");
            if(!check()) break;
        }
    }
    return 0;
}

/*
7
5 2 4
3 1 1 2 5
5 3 4
1 1 2 1 2
4 0 4
5 5 3 3
4 1 4
2 3 2 3
6 1 2
3 2 1 1 1 1
6 2 4
3 3 2 1 1 1
6 2 6
1 1 3 2 1 1
*/