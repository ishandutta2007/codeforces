// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5;

int n, m, k, p, a[N + 10], h[N + 10], f[N + 10];

struct Element {
    int val, id;
    bool operator < (const Element &rhs) const { return val > rhs.val; }
};

namespace Heap {
    template <class T> struct heap {
        T h[N + 10];
        int sz;
        void push(T x) { h[++sz] = x, std::push_heap(h + 1, h + 1 + sz); }
        void pop() { std::pop_heap(h + 1, h + 1 + sz), sz--; }
        T top() { return h[1]; }
        int size() { return sz; }
        bool empty() { return sz == 0; }
    };
} // namespace Heap
using namespace Heap;
heap<Element> q;

bool chk(int x) {
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) {
        if (x - a[i] * m < h[i]) q.push({x / a[i], i});
        f[i] = x;
    }
    for (int i = 1; i <= m; i++) {
        if (q.size() == 0) break;
        for (int j = 1; j <= k; j++) {
            if (q.size() == 0) break;
            Element tmp = q.top();
            q.pop();
            if (f[tmp.id] - a[tmp.id] * i < 0) return 0;
            f[tmp.id] += p;
            if (f[tmp.id] - a[tmp.id] * m < h[tmp.id]) q.push({f[tmp.id] / a[tmp.id], tmp.id});
        }
    }
    for (int i = 1; i <= n; i++)
        if (f[i] - a[i] * m < h[i]) return 0;
    return 1;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n, m, k, p);
    int l = 0, r = 0, ans = -1;
    for (int i = 1; i <= n; i++) fr(h[i], a[i]), r = max(r, a[i] * m + h[i]);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return printf("%lld\n", ans), 0;
}