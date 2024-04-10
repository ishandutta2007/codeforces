#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct UF {
    int rep[200010];
    void init(int n) {
        iota(rep, rep+n+1, 0);
    }
    int findrep(int a) {
        if (rep[a] == a) return a;
        return rep[a] = findrep(rep[a]);
    }
    void merge(int a, int b) {
        rep[findrep(a)] = findrep(b);
    }
};
UF uf;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        ll k;
        scanf("%d%d%lld", &n, &m, &k);
        vector<pair<ll, pair<int, int> > > edges;
        ll mn = 1e9;
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({max(0ll, c-k), {a, b}});
            mn = min(mn, abs(c-k));
        }

        uf.init(n);
        sort(edges.begin(), edges.end());
        int components = n;
        for (auto a : edges) {
            if (uf.findrep(a.second.first) != uf.findrep(a.second.second) && components > 1) {
                uf.merge(a.second.first, a.second.second);
                components--;
                ans += a.first;
            }
        }

        ans = max(ans, mn);
        printf("%lld\n", ans);
    }
}