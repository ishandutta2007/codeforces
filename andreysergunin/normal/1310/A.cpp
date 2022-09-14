// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <random>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

struct Data {
    int a, t;
};

bool operator<(const Data &a, const Data &b) {
    return a.t > b.t;
}

void solve() {  
    int n;
    cin >> n;
    vector<Data> d(n);

    for (int i = 0; i < n; ++i) {
        cin >> d[i].a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i].t;
    }

    sort(all(d));

    set<int> pos;
    set<int> nxt;

    ll res = 0;

    for (auto [a, t] : d) {
        if (!pos.count(a)) {
            pos.insert(a);
            nxt.erase(a);
            if (!pos.count(a + 1)) {
                nxt.insert(a + 1);
            }
        } else {
            auto it = nxt.lower_bound(a);
            int b = *it;
            pos.insert(b);
            nxt.erase(b);
            res += ll(b - a) * t;
            if (!pos.count(b + 1)) {
                nxt.insert(b + 1);
            }
        }
    }

    cout << res << endl;
}