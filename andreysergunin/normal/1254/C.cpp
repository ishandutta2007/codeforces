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

using pli = pair<ll, int>;

ll ask1(int x, int y, int z) {
    cout << "1 " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
    ll res;
    cin >> res;
    return res;
}

int ask2(int x, int y, int z) {
    cout << "2 " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
    int res;
    cin >> res;
    return res;
}

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

    int n;
    cin >> n;

    vector<pli> upper, lower;

    for (int i = 2; i < n; ++i) {
        ll s = ask1(0, 1, i);
        int sgn = ask2(0, 1, i);
        if (sgn < 0) {
            lower.push_back({s, i});
        } else {
            upper.push_back({s, i});
        }
    }

    sort(all(lower));
    sort(all(upper));

    vector<int> res;
    int t = 0;
    for (auto vct : {lower, upper}) {
        res.push_back(t);

        if (sz(vct) == 0) {
            ++t;
            continue;
        }

        int mid = vct.back().second;

        vector<int> left, right;

        for (auto [s, i] : vct) {
            if (i == mid) {
                continue;
            }
            if (ask2(mid, t, i) > 0) {
                right.push_back(i);
            } else {
                left.push_back(i);
            }
        }
        reverse(all(left));

        for (int i : right) {
            res.push_back(i);
        }
        res.push_back(mid);
        for (int i : left) {
            res.push_back(i);
        }
        ++t;
    }

    cout << "0 ";
    for (int i : res) {
        cout << i + 1 << " ";
    }
    cout << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}