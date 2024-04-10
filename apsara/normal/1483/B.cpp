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
int a[V], l[V], r[V], ans[V], m;
void del(int i) {
    r[l[i]] = r[i];
    l[r[i]] = l[i];
    l[i] = r[i] = -1;
    ans[++m] = i;
}
PII Q[V * 10];
int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) r[i] = i % n + 1;
        for (int i = 1; i <= n; ++i) l[r[i]] = i;
        int top = 0, tail = 0;
        m = 0;
        for (int i = 1; i <= n; ++i) if (__gcd(a[i], a[r[i]]) == 1) Q[++tail] = MP(i, r[i]);
        while (top != tail) {
            PII cur = Q[++top];
            if (r[cur.fi] != cur.se || l[cur.se] != cur.fi) continue;
            //printf("Cur %d %d\n", cur.fi, cur.se);
            del(cur.se);
            if (__gcd(a[cur.fi], a[r[cur.fi]]) == 1 && m != n) {
                Q[++tail] = MP(cur.fi, r[cur.fi]);
            }
        }
        printf("%d", m);
        for (int i = 1; i <= m; ++i) printf(" %d", ans[i]); puts("");
    }
    return 0;
}

/*
5
5
5 9 2 10 15
6
1 2 4 2 4 2
2
1 2
1
1
1
2
*/