#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

void precalc() {
}

#define int li
const int mod = 1000000007;

int m;

vector<int> mult(vector<int> q, vector<int> w) {
    vector<int> res(m, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            res[(i + j) % m] += q[i] * w[j];
            res[(i + j) % m] %= mod;
        }
    }
    return res;
}

vector<int> get_power(vector<int> q, int w) {
    if (w == 0) {
        vector<int> res(m, 0);
        res[0] = 1;
        return res;
    }
    if (w & 1) {
        return mult(get_power(q, w - 1), q);
    }
    auto res = get_power(q, w / 2);
    return mult(res, res);
}

void solve(bool read) {
    int n, L;
    cin >> n >> L >> m;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> first(m), last(m);
    for (int i = 0; i < n; ++i) {
        ++first[a[i] % m];
        ++last[(b[i] + c[i]) % m];
    }
    L -= 2;
    vector<int> comb = mult(first, last);

    vector<int> me(m);
    for (int i = 0; i < n; ++i) {
        ++me[c[i] % m];
    }

    vector<int> cur_power = get_power(me, L);

    auto ans = mult(cur_power, comb);

    cout << ans[0] << endl;

}