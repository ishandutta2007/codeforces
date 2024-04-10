#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

const int maxn = 5005;
int c[5005][5005];

void calcc() {
    for (int n = 1; n <= maxn - 1; ++n) {
        c[n][0] = c[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
            if (c[n][k] >= MOD) c[n][k] -= MOD;
        }
    }
}

void add(int& to, int x) {
    to += x;
    if (to >= MOD) to -= MOD;
}

struct polynomial {
    vector<int> c;
    
    polynomial diff() {
        polynomial res;
        if (c.empty()) return res;
        res.c.resize(c.size() - 1);
        for (int i = 1; i < c.size(); ++i)
            res.c[i - 1] = c[i] * (li)i % MOD;
        return res;
    }
    
    polynomial operator+(const polynomial& p) const {
        polynomial res;
        res.c.resize(max(c.size(), p.c.size()));
        for (int i = 0; i < res.c.size(); ++i) {
            if (i < c.size()) add(res.c[i], c[i]);
            if (i < p.c.size()) add(res.c[i], p.c[i]);
        }
        return res;
    }
};

int smart(int n, int d) {
    if (n == 1) return 1;
    
    polynomial cur;
    cur.c.push_back(1);
    
    for (int t = 0; t < d; ++t) {
        auto p = cur.diff();
        p.c.resize(p.c.size() + 1);
        for (int i = p.c.size() - 1; i >= 1; --i)
            add(p.c[i], p.c[i - 1]);
        for (int& x: cur.c) x = x * (li)(n - t) % MOD;
        cur = cur + p;
        cur.c.insert(cur.c.begin(), 0);
    }
    
    int answer = 0;
    for (int x: cur.c)
        add(answer, x);
    
    answer = answer * (li)modpow(2, max(n - d, 0)) % MOD;
    //cout << n - d << "\n";
    return answer;
}

int dumb(int n, int d) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        add(sum, c[n][i] * (li)modpow(i, d) % MOD);
    }
    return sum;
}

int combined(int n, int d) {
    if (n <= d) {
        return dumb(n, d);
    }
    else {
        return smart(n, d);
    }
}

void solve(bool __attribute__((unused)) read) {
    calcc();
    
#if 0
    for (int n = 1; n <= 100; ++n)
        for (int d = 1; d <= 100; ++d) {
            cout << n << " " << d << " " << combined(n, d) << " " << dumb(n, d) << endl;
            assert(combined(n, d) == dumb(n, d));
        }
#endif
    
    int n, d;
    cin >> n >> d;
    cout << combined(n, d) << "\n";
    
    //for (int n = 1; n <= 20; ++n) {
        
    //cout << sum << " " << smart(n, d) << "\n";
    //}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}