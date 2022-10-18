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

const int N = 1e6;

int n, ans;

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
heap<int> q;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) {
        int x = fr();
        q.push(x -= i);
        if (x < q.top()) ans += q.top() - x, q.pop(), q.push(x);
    }
    return printf("%lld\n", ans), 0;
}