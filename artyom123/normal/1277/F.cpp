#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    map<int, int> cnt;
    for (auto &c : a) cnt[c]++;
    vector<int> kek;
    for (auto &c : cnt) {
        kek.pb(c.se);
    }
    int x = 1, p = 1, q = 1;
    sort(all(kek));
    int sum = 0, j = 0, y = kek.size();
    for (int p1 = 1; p1 <= n; p1++) {
        while (j < (int)kek.size() && kek[j] < p1) {
            sum += kek[j];
            y--;
            j++;
        }
        int now = sum + y * p1;
        int q1 = now / p1;
        if (q1 >= p1 && p1 * q1 > x) {
            x = p1 * q1;
            p = p1;
            q = q1;
        }
    }
    cout << x << "\n" << q << " " << p << "\n";
    vector<pii> lol;
    for (auto &c : cnt) {
        lol.pb(c.se, c.fi);
        lol.back().fi = min(lol.back().fi, p);
    }
    sort(all(lol));
    vector<vector<int>> ans(q, vector<int>(p));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < p; j++) {
            if (lol.back().fi == 0) lol.pop_back();
            lol.back().fi--;
            ans[(i + j) % q][j] = lol.back().se;
        }
    }
    for (auto &c : ans) {
        for (auto &l : c) {
            cout << l << " ";
        }
        cout << "\n";
    }
    return 0;
}