#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int a[111111];
int b[111111];
int cnt[111111];

struct query {
    int l, r, id;

    bool operator<(const query& q) const {
        return r < q.r;
    }
};

const int N = 100000;
const int BLEN = 310;
const int BCNT = N / BLEN + 1;

vector<query> qs[BCNT];

void add(int i, int& cans) {
    int x = a[i];
    if (cnt[x] == b[x]) {
        cans--;
    }
    cnt[x]++;
    if (cnt[x] == b[x]) {
        cans++;
    }
}

void rem(int i, int& cans) {
    int x = a[i];
    if (cnt[x] == b[x]) {
        cans--;
    }
    cnt[x]--;
    if (cnt[x] == b[x]) {
        cans++;
    }
}

int ans[111111];

int main() {
    sciid(n, m);
    unordered_map<int, int> um;
    um.reserve(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        if (um.find(x) == um.end()) {
            int t = um.size();
            um[x] = t;
            b[t] = x;
        }
        a[i] = um[x];
    }

    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        query q{x, y, i};
        qs[x / BLEN].push_back(q);
    }

    for (int i = 0; i < BCNT; i++) {
        sort(qs[i].begin(), qs[i].end());
        memset(cnt, 0, sizeof(cnt));
        int l = 0, r = 0;
        int cans = 0;
        for (auto& q : qs[i]) {
            for (; r <= q.r; r++) {
                add(r, cans);
            }
            for (; l < q.l; l++) {
                rem(l, cans);
            }
            for (; l > q.l; l--) {
                add(l - 1, cans);
            }
            ans[q.id] = cans;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}