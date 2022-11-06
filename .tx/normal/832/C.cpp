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

double get_d(double xg, double v, double s, double t) {
    return floor((t - (xg / (s + v))) * (s - v) / ((1 - v / (s + v))));
}

vector<double> x[2];
vector<double> v[2];
const int A = int(1e6);
int n;
double s;
const double eps = 1e-9;

bool check(double t) {
    vector<pair<double, int>> ps;
    for (int i = 0; i < x[0].size(); i++) {
        double xg = x[0][i];
        double v = ::v[0][i];
        if (xg / v < t + eps) {
            ps.push_back({0, -1});
            ps.push_back({A, 1});
        } else if (xg / (v + s) < t + eps) {
            ps.push_back({xg, -1});
            double d = get_d(xg, v, s, t);
            ps.push_back({xg + d, 1});
        }
    }
    for (int i = 0; i < x[1].size(); i++) {
        double xg = A - x[1][i];
        double v = ::v[1][i];
        if (xg / v < t + eps) {
            ps.push_back({0, -2});
            ps.push_back({A, 2});
        } else if (xg / (v + s) < t + eps) {
            double d = get_d(xg, v, s, t);
            ps.push_back({x[1][i] - d, -2});
            ps.push_back({x[1][i], 2});
        }
    }

    sort(ps.begin(), ps.end());
    int cnt[2] = {0, 0};
    for (auto& p : ps) {
        if (p.second == -1) {
            cnt[0]++;
        } else if (p.second == -2) {
            cnt[1]++;
        } else if (p.second == 1) {
            cnt[0]--;
        } else if (p.second == 2) {
            cnt[1]--;
        }
        if (cnt[0] > 0 && cnt[1] > 0) {
            return true;
        }
    }
    return false;
}

void solve(istream& cin, ostream& cout) {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        double xg, vg;
        int t;
        cin >> xg >> vg >> t;
        if (t == 1) {
            x[0].push_back(xg);
            v[0].push_back(vg);
        } else {
            x[1].push_back(xg);
            v[1].push_back(vg);
        }
    }
//
    double l = 0, r = 1e7;
    for (int it = 0; it < 70; it++) {
        double m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << setprecision(11) << fixed << r;
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
}//bqlmxm