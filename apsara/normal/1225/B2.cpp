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
const int P = 1000000007;

const int V = 1000100;
int tr[V], N;

void update(int k, int v) {
    while (k <= N) {
        tr[k] += v;
        k += k & -k;
    }
}

int read(int k) {
    int res = 0;
    while (k) {
        res += tr[k];
        k -= k & -k;
    }
    return res;
}

int last[V];

set<int> s;

int _, n, K, D, x;
int main() {
    scanf("%d", &_);
    for (int i = 1; i < V; ++i) last[i] = -1;
    while (_--) {
        s.clear();
        scanf("%d%d%d", &n, &K, &D);
        N = n;
        for (int i = 1; i <= N; ++i) tr[i] = 0;
        int ans = K;
        for (int i = n; i > 0; --i) {
            scanf("%d", &x);
            s.insert(x);
            if (last[x] != -1) update(last[x], -1);
            last[x] = i;
            update(i, 1);
            if (i + D - 1 <= n) {
                int tmp = read(i + D - 1);
                ans = min(ans, tmp);
            }
        }
        printf("%d\n", ans);
        for (auto x : s) last[x] = -1;
    }
    return 0;
}

/*
4
5 2 2
1 2 1 2 1
9 3 3
3 3 3 2 2 2 1 1 1
4 10 4
10 8 6 4
16 9 8
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3
*/