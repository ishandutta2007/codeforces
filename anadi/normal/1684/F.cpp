#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

int n, m;
int in[N];
vector <int> Q[N];
vector <PII> edges;

int k;
map <int, int> M;
set <int> vals[N];

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        vals[i].clear();
        vals[i].insert(0);

        Q[i].clear();
    }

    k = 0;
    M.clear();

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        if (!M.count(in[i])) {
            M[in[i]] = ++k;
        }

        in[i] = M[in[i]];
        vals[in[i]].insert(i);
    }

    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);

        Q[l].push_back(l);
        Q[r + 1].push_back(-l);
    }

    multiset <int> idxs;
    edges.clear();

    for (int i = 1; i <= n; ++i) {
        for (auto v: Q[i]) {
            if (v > 0) {
                idxs.insert(v);
            } else {
                idxs.erase(idxs.find(-v));
            }
        }

        auto it = vals[in[i]].lower_bound(i);
        --it;

        if (!idxs.empty() && *it >= *idxs.begin()) {
            edges.push_back({*it, i});
        }

        if (!idxs.empty()) {
            auto it = vals[in[i]].lower_bound(*idxs.begin());
            if (*it < i) {
                edges.push_back({*it, i});
            }
        }
    }

    if (edges.empty()) {
        puts("0");
        return;
    }

    set <pair <int, int> > active;
    for (int i = 0; i < (int)edges.size(); ++i) {
        active.insert({edges[i].first, i});
    }

    int ans = n;
    for (int i = 1; i <= n; ++i) {
        while (true) {
            auto [v, idx] = *active.begin();
            if (v >= i) {
                break;
            }

            if (edges[idx].second < i) {
                printf("%d\n", ans);
                return;
            }

            active.erase(active.begin());
            active.insert({edges[idx].second, idx});
        }

        ans = min(ans, (*active.rbegin()).first - i + 1);
    }

    printf("%d\n", ans);
}

int main()
{
    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}