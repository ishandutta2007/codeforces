#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) iterable.begin(), iterable.end()

template <typename T>
void print_vector(vector<T>& vec, string sep = " ", string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int d = n / m;
    vector<long long> a(n);
    vector<long long> c(m, 0);
    vector<vector<int>> l(m);
    rep(i, n) {
        cin >> a[i];
        int r = a[i] % m;
        ++c[r];
        l[r].push_back(i);
    }
    long long ans = 0;
    vector<int> x(m, 0);
    rep(i, 2 * m) {
        int r = i % m;
        if (c[r] > d) {
            int t = c[r] - d;
            x[r] += t;
            ans += t;
            int nr = r == m - 1 ? 0 : r + 1;
            c[nr] += t;
            c[r]  -= t;
        }
    }
    int base = 0;
    rep(r, m) {
        if (x[r] == 0) base = r;
    }
    vector<int> vs;
    for (int t = base; t < base + m; ++t) {
        int r = t % m;
        for (int i : l[r]) vs.push_back(i);
        while (vs.size() > x[r]) {
            int i = vs.back();
            vs.pop_back();
            int from = a[i] % m;
            int to = r;
            while (to < from) to += m;
            a[i] += to - from;
        }
    }
    int r = (base + m) % m;
    while (vs.size()) {
        int i = vs.back();
        vs.pop_back();
        int from = a[i] % m;
        int to = r;
        while (to < from) to += m;
        a[i] += to - from;
    }
    cout << ans << '\n';
    print_vector(a);
    return 0;
}