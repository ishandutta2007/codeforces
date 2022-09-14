#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int MAXN = 100100; 

struct Edge {
    int u, v;
    ll w;
};


int sign(ll x) {
    return x < 0 ? -1 : x > 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> d(n);

    for (int i = 0; i < m; ++i) {
        int a, b, ww;
        cin >> a >> b >> ww;
        --a; --b;
        d[a] += ww;
        d[b] -= ww;
    }

    vector<int> st;
    int k = 0;

    vector<int> x;

    vector<Edge> e;

    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            continue;
        }
        if (k == 0 || sign(d[st[k - 1]]) == sign(d[i])) {
            st.push_back(i);
            ++k;
            continue;
        }

        while (k > 0) {
            ll x = min(abs(d[st[k - 1]]), abs(d[i]));
            if (d[i] > 0) {
                e.push_back({i, st[k - 1], x});
            } else {
                e.push_back({st[k - 1], i, x});
            }
            d[st[k - 1]] = sign(d[st[k - 1]]) * (abs(d[st[k - 1]]) - x);
            d[i] = sign(d[i]) * (abs(d[i]) - x);


            if (d[st[k - 1]] == 0) {
                st.pop_back();
                --k;
            }
            if (d[i] == 0) {
                break;
            } 
        }

        if (d[i] != 0) {
            st.push_back(i);
            ++k;
        }
    }

    cout << sz(e) << endl;
    for (auto ed : e) {
        cout << ed.u + 1 << " " << ed.v + 1 << " " << ed.w << endl;
    }
}