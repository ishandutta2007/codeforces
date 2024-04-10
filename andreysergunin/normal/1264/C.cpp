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

const int P = 998244353;


void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

int binPow(int a, int b) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, a);
        }
        mul(a, a);
    }
    return res;
}

int rev(int a) {
    return binPow(a, P - 2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    int r = rev(100);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        mul(p[i], r);
    }

    vector<int> suff(n + 1);
    vector<int> sum(n + 1);
    suff[n] = 1;
    sum[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1];
        mul(suff[i], rev(p[i]));
        sum[i] = sum[i + 1];
        add(sum[i], suff[i]);
    }

    // for (int i = 0; i < n; ++i) {
    //     pref[i + 1] = pref[i];
    //     mul(pref[i + 1], rev(p[i]));
    //     sum[i + 1] = sum[i];
    //     add(sum[i + 1], pref[i + 1]);
    // }

    auto f = [&](int lf, int rg) {
        int res = sum[lf];
        sub(res, sum[rg]);
        mul(res, rev(suff[rg]));
        return res;
    };

    int res = f(0, n);

    set<int> setik;
    setik.insert(0);
    setik.insert(n);


    for (int i = 0; i < q; ++i) {
        int pos;
        cin >> pos;
        --pos;

        if (setik.count(pos)) {
            auto it = setik.find(pos);
            auto lf = it;
            --lf;
            auto rg = it;
            ++rg;

            sub(res, f(*lf, *it));
            sub(res, f(*it, *rg));
            add(res, f(*lf, *rg));
            setik.erase(it);
        } else {
            setik.insert(pos);

            auto it = setik.find(pos);
            auto lf = it;
            --lf;
            auto rg = it;
            ++rg;

            add(res, f(*lf, *it));
            add(res, f(*it, *rg));
            sub(res, f(*lf, *rg));
        }

        cout << res << "\n";
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

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}