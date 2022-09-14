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

void solve(vector<int> cnt, vector<int> to_del) {
    if (cnt[1] - cnt[0] != cnt[2] - cnt[3] || cnt[1] - cnt[0] < 0) {
        return;
    }
    if (cnt[1] - cnt[0] == 0 && cnt[0] != 0 && cnt[3] != 0) {
        return;
    }

    cout << "YES\n";

    vector<int> res;

    for (int i = 0; i < 3; ++i) {
        if (cnt[i] == 0) {
            continue;
        }
        int j = i;

        while (j < 4 && cnt[j] != 0) {
            while (cnt[j] > 0) {
                res.push_back(j + 1);
                res.push_back(j);
                --cnt[j];
                --cnt[j + 1];
            }
            res.pop_back();
            ++j;
        }
        --j;
        while (j >= i) {
            res.push_back(j);
            --j;
        }
    }   


    int n = sz(res);

    if (sz(to_del) == 1) {
        for (int i = 0; i < n; ++i) {
            if (res[i] == to_del[0]) {
                reverse(res.begin(), res.begin() + i);
                reverse(res.begin() + i, res.end());
                res.pop_back();
                break;
            }
        }   
    }

    if (sz(to_del) == 2) {
        if ((res[0] == to_del[0] && res.back() == to_del[1]) || 
            (res[0] == to_del[1] && res.back() == to_del[0])) {
            res.pop_back();
            reverse(all(res));
            res.pop_back();
        } else {
            for (int i = 0; i < n - 1; ++i) {
                if ((res[i] == to_del[0] && res[i + 1] == to_del[1]) ||
                    (res[i] == to_del[1] && res[i + 1] == to_del[0])) {
                    reverse(res.begin(), res.begin() + i);
                    reverse(res.begin() + i, res.end());
                    res.pop_back();
                    res.pop_back();
                    break;
                }
            }   
        }
    }

    for (int i = 0; i < sz(res); ++i) {
        cout << res[i] << " ";
    } 
    cout << "\n";

    exit(0);
}

void solve() {
    vector<int> cnt(4);

    for (int i = 0; i < 4; ++i) {
        cin >> cnt[i];
    }


    solve(cnt, {});

    for (int i = 0; i < 4; ++i) {
        ++cnt[i];
        solve(cnt, {i});
        --cnt[i];
    }

    ++cnt[1];
    ++cnt[2];
    solve(cnt, {1, 2});

    cout << "NO\n";

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

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}