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
 
vector<int> solve(vector<int> p, int c = 1) {  
    int n = sz(p);
 
    if (n <= 3) {
        vector<int> cp(n);
        iota(all(cp), c);
        return cp;
    }
 
    if (n == 4) {
        auto it = max_element(all(p));
        int pos = it - p.begin();
        vector<int> cp(n);
        for (int i = 0, j = c; i < n; ++i) {
            if (i != pos) {
                cp[i] = j++;
            }
        }
        if (pos < 2) {
            cp[pos] = cp[3];
        } else {
            cp[pos] = cp[0];
        }
        return cp;
    }
 
    vector<int> q;
    for (int i = 0; i < n; i += 3) {
        int pos = i;
        for (int j = i; j < min(i + 3, n); ++j) {
            if (p[pos] > p[j]) {
                pos = j;
            }
        }
        q.push_back(p[pos]);
    }
 
    vector<int> cq = solve(q, c + 3);
 
    map<int, int> mapa;
    for (int i = 0; i < n; ++i) {
        mapa[p[i]] = i;
    }
 
    vector<int> cr(n);
    for (int i = 0; i < sz(q); ++i) {
        cr[mapa[q[i]]] = cq[i];
    }
 
    vector<pii> order;
    for (int i = 0; i < n; ++i) {
        order.push_back({p[i], i});
    }
    sort(all(order));
     
    set<int> used;
    vector<int> cp(n);

    for (auto [val, pos] : order) {
        if (cr[pos] != 0) {
            cp[pos] = cr[pos];
            used.insert(pos);
            continue;
        }
 
        auto it = used.lower_bound(pos);
        int lf = (it == used.begin() ? -1 : cp[*(--it)]);
        if (lf > c + 2) {
            lf = -1;
        }
 
        it = used.lower_bound(pos);
        int rg = (it == used.end() ? -1 : cp[*it]);
        if (rg > c + 2) {
            rg = -1;
        }

        if (lf == -1 && rg == -1) {
            cp[pos] = c;
        } else if (lf == -1 || lf == rg) {
            cp[pos] = (rg - c + 1) % 3 + c;
        } else if (rg == -1) {
            cp[pos] = (lf - c + 1) % 3 + c;
        } else {
            cp[pos] = (3 * c + 3 - lf - rg);
        }
        used.insert(pos);
    }
    return cp;
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
 
    int tests;
    cin >> tests;
 
    while (tests--) {
        int n;  
        cin >> n;
        vector<int> p(n);
 
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
 
        vector<int> rp(n);
        for (int i = 0; i < n; ++i) {
            rp[p[i] - 1] = i; 
        }
 
        vector<int> res = solve(rp);
  
        for (int c : res) {
            cout << c << " ";
        }
        cout << endl;
    }
    
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}