#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    f ? a = - a : 0;
}
template <class T, class ...Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e6;

int n, ans, top;
char str[N + 10];

namespace Heap {
    template <class T> struct heap {
        T h[N + 10]; int sz;
        void push(T x) { h[++sz] = x, push_heap(h + 1, h + 1 + sz); }
        void pop() { pop_heap(h + 1, h + 1 + sz), sz--; }
        T top() { return h[1]; }
        int size() { return sz; }
    };
} // namespace Heap
using namespace Heap;
heap<pair<int, int>> q;

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    scanf("%s", str + 1), n = strlen(str + 1);
    if (n & 1) puts("-1"), exit(0);
    for (int i = 1; i <= n; i++) {
        if (str[i] == '(') top++;
        else if (str[i] == ')') top--;
        else {
            int a = fr(), b = fr();
            ans += b, top--, q.push({b - a, i}), str[i] = ')';
        }
        if (top < 0) {
            if (q.size() == 0) puts("-1"), exit(0);
            auto u = q.top();
            ans -= u.first, str[u.second] = '(', top += 2, q.pop();
        }
    }
    if (top) puts("-1"), exit(0);
    printf("%lld\n", ans), puts(str + 1);
    return 0;
}