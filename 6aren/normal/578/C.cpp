#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const double EPS = 1e-20;

int n;
int a[200005];
double sum[200005];

double check(double x) {
    double mx = 0;
    double mn = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (a[i] - x);
        mx = max(mx, sum[i]);
        mn = min(mn, sum[i]);
    }
    return (mx - mn);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = -1e12, r = 1e12;
    for (int rep = 1; rep <= 150; rep++) {
        double u = (2 * l + r) / 3;
        double v = (l + 2 * r) / 3;
        double checkU = check(u);
        double checkV = check(v);
        if (checkU - checkV > EPS) {
            l = u;
        } else {
            r = v;
        }
    }
    cout << setprecision(10) << fixed << check(l);
    return 0;
}