#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

map<int, int> cnt;
int a[111111];
set<tuple<int, int, int>> ch;

lint get(int i, int j, int k) {
    if (a[i] > a[j]) {
        return get(j, i, k);
    }
    if (a[i] > a[k]) {
        return get(k, j, i);
    }
    if (a[j] > a[k]) {
        return get(i, k, j);
    }
    if (ch.count(make_tuple(a[i], a[j], a[k]))) {
        return 0;
    }
    ch.insert(make_tuple(a[i], a[j], a[k]));
    if (a[i] == a[j] && a[j] == a[k]) {
        int x = cnt[a[i]];
        return 1LL * x * (x - 1) * (x - 2) / 6;
    }
    if (a[i] == a[j]) {
        int x = cnt[a[i]];
        return 1LL * x * (x - 1) / 2 * cnt[a[k]];
    }
    if (a[k] == a[j]) {
        int x = cnt[a[j]];
        return 1LL * cnt[a[i]] * x * (x - 1) / 2;
    }
    return 1LL * cnt[a[i]] * cnt[a[j]] * cnt[a[k]];
}

vector<pair<long double, lint>> b;

void add(int i, int j, int k) {
    long double mul = (long double) 1LL * a[i] * a[j] * a[k];
    lint q = get(i, j, k);
    b.push_back({mul, q});
}

void solve(istream& cin, ostream& cout) {
    cnt.clear();
    b.clear();
    ch.clear();
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a, a + n);
    add(0, 1, 2);
    add(0, 1, n - 1);
    add(0, n - 1, n - 2);
    add(n - 1, n - 2, n - 3);
    sort(b.begin(), b.end());
    lint ans = 0;
    rep(i, 0, b.size()) {
        if (abs(b[i].first - b[0].first) < 1e-9) {
            ans += b[i].second;
        }
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand(3203223);
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
}//oav