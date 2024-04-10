#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int a[100500], b[100500];
pii edges[100500];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pii> tree, not_tree;
    REP (i, m) {
        cin >> a[i] >> b[i];
        if (b[i]) {
            tree.emplace_back(a[i], i);
        } else {
            not_tree.emplace_back(a[i], i);
        }
    }
    sort(all(tree));
    sort(all(not_tree));
    vector<pair<int, pii>> f;
    REP (i, sz(tree)) {
        int j = tree[i].Y;
        edges[j].X = 1;
        edges[j].Y = i + 2;
        for (j = 0; j < i && sz(f) < sz(not_tree); ++j) {
            f.emplace_back(tree[i].X, pii(i + 2, j + 2));
        }
    }
    if (sz(f) != sz(not_tree)) {
        puts("-1");
    }
    REP (i, sz(f)) {
        if (not_tree[i].X < f[i].X) {
            puts("-1");
            return 0;
        }
        int j = not_tree[i].Y;
        edges[j] = f[i].Y;
    }
    REP (i, m) {
        cout << edges[i].X << ' ' << edges[i].Y << endl;
    }
    return 0;
}