#include <algorithm>
#include <cstdio>
#include <vector>

#define int long long

using std::vector;

const int N = 3e5;

namespace Heap {
    bool cmp(int a, int b) { return a > b; }
    struct heap {
        int h[N + 10], sz;
        heap() { sz = 0; }
        void push(int x) { h[++sz] = x, std::push_heap(h + 1, h + 1 + sz, cmp); }
        void pop() { std::pop_heap(h + 1, h + 1 + sz, cmp), sz--; }
        int top() { return h[1]; }
        int size() { return sz; }
    } q;
} // namespace Heap
using namespace Heap;

int n, pre, cnt, ans;

vector<int> a[N + 10];

void clr() {
    for (int i = 0; i <= n; i++) a[i].clear();
    while (q.size()) q.pop();
}

signed main() {
    int T;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n), clr(), pre = n, cnt = ans = 0;
        for (int i = 1, c, t; i <= n; i++) scanf("%lld%lld", &c, &t), a[c].push_back(t);
        for (int i = n; ~i; i--) {
            pre -= a[i].size();
            for (int j = 0; j < a[i].size(); j++) q.push(a[i][j]);
            while (pre + cnt < i) ans += q.top(), q.pop(), cnt++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}