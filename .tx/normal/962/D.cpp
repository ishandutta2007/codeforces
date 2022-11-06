#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    map<lint, set<lint>> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x].insert(i);
    }

    lint cur = 0;
    while (true) {
        auto it = m.upper_bound(cur);
        if (it == m.end()) {
            break;
        }
        lint c = it->first;
        if (it->second.size() < 2) {
            cur = c;
            continue;
        }
        auto ii = it->second.begin();
        lint p1 = *ii;
        ++ii;
        lint p2 = *ii;
        it->second.erase(p1);
        it->second.erase(p2);
        m[2 * c].insert(p2);
    }
    vector<pair<lint, lint>> a;
    for (auto& i : m) {
        for (auto& j : i.second) {
            a.push_back({j, i.first});
        }
    }
    sort(a.begin(), a.end());
    cout << a.size() << "\n";
    for (auto& i : a) {
        cout << i.second << " ";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//kvgidh