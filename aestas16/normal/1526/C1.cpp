/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

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

int n, ans, qwq, a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) {
        fr(a[i]);
        if (a[i] >= 0) ans++, qwq += a[i];
        else {
            while (q.size()) {
                int x = q.top();
                if (x > -a[i] && qwq < -a[i]) {
                    qwq += x, ans--, q.pop();
                } else break;
            }
            if (qwq >= -a[i]) ans++, qwq += a[i], q.push(-a[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}