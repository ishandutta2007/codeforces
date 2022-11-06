#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct FenwTree {
    int* a;
    int n;

    FenwTree(int n) : n(n) {
        a = new int[n];
        memset(a, 0, sizeof(int) * n);
    }

    int get(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res ^= a[r];
        }
        return res;
    }

    int get(int l, int r) {
        int res = get(r);
        if (l > 0) {
            res ^= get(l - 1);
        }
        return res;
    }

    void set(int i, int x) {
        int tx = x ^ get(i, i);
        for (; i < n; i |= (i + 1)) {
            a[i] ^= tx;
        }
    }
};

int a[1111111];
int px[1111111];
int ans[1111111];

struct query {
    int l, id;
};

vector<query> qs[1111111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        px[i] = a[i];
        if (i) {
            px[i] ^= px[i - 1];
        }
    }

    scid(m);
    for (int i = 0; i < m; i++) {
        sciid(l, r);
        --l;
        qs[r - 1].push_back({l, i});
    }

    FenwTree st(n);
    unordered_map<int, int> last(2 * n);

    for (int i = 0; i < n; i++) {
        auto it = last.find(a[i]);
        if (it != last.end()) {
            st.set(it->second, 0);
            it->second = i;
        } else {
            last[a[i]] = i;
        }
        st.set(i, a[i]);

        for (auto& q : qs[i]) {
            int x1 = px[i];
            if (q.l > 0) {
                x1 ^= px[q.l - 1];
            }
            int x2 = st.get(q.l, i);
            ans[q.id] = x1 ^ x2;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}