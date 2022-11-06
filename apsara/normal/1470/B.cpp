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
const int N = 1000000;
int mi_p[N + 10], c[N + 10];

void init() {
    memset(mi_p, 0, sizeof(mi_p));
    for (int i = 2; i <= N; ++i) {
        if (mi_p[i] != 0) continue;
        for (int j = i; j <= N; j += i) mi_p[j] = i;
    }
    for (int i = 1; i <= N; ++i) {
        c[i] = 1;
        int x = i;
        while (x != 1) {
            int cnt = 0;
            int p = mi_p[x];
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            if (cnt % 2 == 1) c[i] *= p;
        }
    }
}

int _, n, Q, cnt[N + 10], a[V];
LL x;
int main() {
    init();
    scanf("%d", &_);
    memset(cnt, 0, sizeof(cnt));
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) a[i] = c[a[i]];
        sort(a, a + n);
        for (int i = 0; i < n; ++i) cnt[a[i]]++;
        int mx_0 = 0;
        for (int i = 0; i < n; ++i) mx_0 = max(mx_0, cnt[a[i]]);
        int odd = 0;
        for (int i = 0; i < n; ++i) if ((i == 0 || a[i] != a[i - 1]) && a[i] != 1 && cnt[a[i]] % 2 == 1) odd += cnt[a[i]];
        scanf("%d", &Q);
        while (Q--) {
            scanf("%lld", &x);
            if (x == 0) printf("%d\n", mx_0);
            else printf("%d\n", max(mx_0, n - odd));
        }
        for (int i = 0; i < n; ++i) cnt[a[i]]--;
    }
    return 0;
}

/*
2
4
6 8 4 2
1
0
6
12 3 20 5 80 1
1
1
*/