#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

//#define int li
//const int mod = 1000000007;

vector<vector<int>> e;

vector<char> used;
vector<int> comp;

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (int u : e[v]) {
        if (used[u]) continue;
        dfs(u);
    }
}

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;

    vector<pair<int, int>> l(n), r(n);
    vector<int> lOrig(n), rOrig(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i].first >> r[i].first;
        lOrig[i] = l[i].first;
        rOrig[i] = r[i].first;
        l[i].second = i;
        r[i].second = i;
    }
    sort(l.rbegin(), l.rend());
    sort(r.rbegin(), r.rend());

    e.resize(n);
    for (int i = 0; i < n; ++i) {
        e[l[i].second].push_back(r[i].second);
    }

    used.assign(n, false);
    li ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            comp.clear();
            dfs(i);

            int s = comp.size();
            li ans1 = 0;
            li ans2 = 0;
            for (int j = 0; j < s; ++j) {
                int a = comp[j];
                int b = comp[(j + 1) % s];

                ans1 += 1 + max(rOrig[a], lOrig[b]);
                ans2 += 1 + max(lOrig[a], rOrig[b]);
            }
            ans += min(ans1, ans2);
        }
    }

    cout << ans << endl;
}