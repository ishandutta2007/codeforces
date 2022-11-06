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

double fact(int n) {
    double res = 1;
    rep(i, 2, n + 1) {
        res *= i;
    }
    return res;
}

double c(int n, int k) {
    return fact(n) / fact(k) / fact(n - k);
}

double f(int n, int k) {
    double res = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        res += i * c(n - i, k - 1);
    }
    res /= c(n, k);
    return res;
}

int a[222222];
pair<int, int> b[222222];
int ans[222222];

void solve(istream& cin, ostream& cout) {
//    cout << setprecision(3) << fixed;
//    for (int n = 1; n <= 10; n++) {
//        for (int k = 1; k <= 10; k++) {
//            cout << f(n, k) << " ";
//        }
//        cout << endl;
//    }
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    sort(b, b + n);
    rep(i, 0, n) {
        ans[b[i].second] = a[i];
    }
    rep(i, 0, n) {
        cout << ans[i] << " ";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
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
}//vulcqo