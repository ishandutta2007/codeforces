#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

//#define int li

struct fenwick {
    int n;
    vector<int> a;

    fenwick(int n): n(n), a(n) {}

    void add(int i, int x) {
        for (; i < n; i = (i | (i + 1)))
            a[i] += x;
    }

    int get(int i) {
        int ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            ans += a[i];
        return ans;
    }
};

li countInversions(vector<int> p) {
    int n = p.size();
    fenwick f(n);
    li answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += i - f.get(p[i]);
        f.add(p[i], 1);
    }
    return answer;
}

vector<int> gen(int n, int ns) {
    vector<int> p(n);
    iota(all(p), 0);
    for (int t = 0; t < ns; ++t) {
        int i = rand() % n;
        int j = rand() % n;

        swap(p[i], p[j]);
    }
    return p;
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    //cout << countInversions(p) << endl;

    cout << ((countInversions(p) % 2 == n % 2) ? "Petr" : "Um_nik") << endl;
}