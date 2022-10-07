#include <bits/stdc++.h>

class fenwick_tree {
public:
    static const int N = 1000001;

protected:
    int c[N + 1];
    long long s[N + 1];

public:
    fenwick_tree() : c(), s() {}

    void add(int x, int v) {
        long long vx = 1ll * v * x;
        for (++x; x <= N; x += x & -x) {
            c[x] += v;
            s[x] += vx;
        }
    }

    long long query(int x) const {
        x = std::min(x, N);
        x = std::max(x, 0);
        int t = x;
        long long res = 0;
        for (; x; x ^= x & -x) {
            res += 1ll * c[x] * t;
            res -= s[x];
        }
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    long long sum = 0;
    std::multiset<int> Sa;
    fenwick_tree Ta;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        Sa.insert(a[i]);
        Ta.add(a[i], 1);
        sum += a[i];
    }
    std::multiset<int> Sb;
    fenwick_tree Tb;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
        Sb.insert(b[i]);
        Tb.add(b[i], 1);
        sum -= b[i];
    }

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p, v;
            std::cin >> p >> v;
            --p;
            Sa.erase(Sa.find(a[p]));
            Ta.add(a[p], -1);
            sum -= a[p];
            a[p] = v;
            Sa.insert(a[p]);
            Ta.add(a[p], 1);
            sum += a[p];
        } else if (op == 2) {
            int p, v;
            std::cin >> p >> v;
            --p;
            Sb.erase(Sb.find(b[p]));
            Tb.add(b[p], -1);
            sum += b[p];
            b[p] = v;
            Sb.insert(b[p]);
            Tb.add(b[p], 1);
            sum -= b[p];
        } else {
            int k;
            std::cin >> k;
            int min = std::min(*Sa.begin(), *Sb.begin());
            auto it = Sa.lower_bound(Sb.size() <= 1 ? 0 : k + *(--(--Sb.end())));

            auto calc = [&](int t, bool inA) {
                return 1ll * (n - inA) * std::max(0, t - k - min)
                       - Tb.query(t - k) + 1ll * (m - n) * t;
            };

            long long ans = std::max({
                calc(*Sa.begin(), true), 
                calc(*(--Sa.end()), true),
                calc(*Sb.begin(), false),
                calc(*(--Sb.end()), false)
            });
            if (it != Sa.end()) {
                ans = std::max(ans, calc(*it, true));
            }
            if (it != Sa.begin()) {
                ans = std::max(ans, calc(*std::prev(it), true));
            }
            std::cout << ans + 1ll * (n - m) * k + sum << "\n";
        }
    }
}