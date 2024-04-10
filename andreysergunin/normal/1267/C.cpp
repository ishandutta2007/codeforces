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

void update(set<pii> &setik, set<pii> &odd, pii p, int val) {
    setik.erase(p);
    odd.erase(p);
    p.first -= val;
    if (p.first > 0) {
        setik.insert(p);
        if (p.first & 1) {
            odd.insert(p);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    set<pii> setik;
    set<pii> odd;

    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        setik.insert({d, i + 1});
        if (d & 1) {
            odd.insert({d, i + 1});
        }
    }

    vector<pii> edges;

    while (!setik.empty()) {
        auto it = setik.begin();

        if (it->first > 2 || sz(setik) == 1) {
            cout << -1 << endl;
            return;
        }

        if (it->first == 1) {
            auto it_odd = (--odd.end());

            if (it_odd->first > 1) {
                edges.push_back({it->second, it_odd->second});

                update(setik, odd, *it, 1);
                update(setik, odd, *it_odd, 1);
                continue;
            }

            auto it1 = (--setik.end());
            if (it1->first == 1 && sz(setik) > 2) {
                cout << -1 << endl;
                return;
            }
            edges.push_back({it->second, it1->second});

            update(setik, odd, *it, 1);
            update(setik, odd, *it1, 1);
            continue;
        }

        if (sz(setik) == 2) {
            cout << -1 << endl;
            return;
        }

        auto it1 = it;
        ++it1;
        auto it2 = (--setik.end());

        if (it1->first != 2) {
            cout << -1 << endl;
            return;
        }
        
        if (it2->first == 2) {
            break;
        }

        edges.push_back({it->second, it1->second});
        edges.push_back({it1->second, it2->second});
        edges.push_back({it2->second, it->second});

        update(setik, odd, *it, 2);
        update(setik, odd, *it1, 2);
        update(setik, odd, *it2, 2);
    }

    vector<int> rem;

    for (auto [x, v] : setik) {
        rem.push_back(v);
    }

    for (int i = 0; i < sz(rem); ++i) {
        edges.push_back({rem[i], rem[i + 1 == sz(rem) ? 0 : i + 1]});
    }

    cout << sz(edges) << endl;

    for (auto [u, v] : edges) {
        cout << 2 << " " << u << " " << v << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    solve();

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}