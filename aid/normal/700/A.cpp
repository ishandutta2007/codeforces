#include <iostream>

using namespace std;

const double EPS = 1e-9;

bool check(int n, int l, int v0, int v1, int k, double s) {
    double pos = 0;
    while(n) {
        if(l - pos < s - EPS)
            return false;
        n -= min(n, k);
        double p = pos + s;
        pos += (s / v1) * v0;
        double t = (p - pos) / (v0 + v1);
        pos += t * v0;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, l, v0, v1, k;
    cin >> n >> l >> v0 >> v1 >> k;
    double ls = 0, rs = l;
    for(int i = 0; i < 100; i++) {
        double ms = (ls + rs) / 2;
        if(check(n, l, v0, v1, k, ms))
            ls = ms;
        else
            rs = ms;
    }
    cout << ls / v1 + (l - ls) / v0 << '\n';
    return 0;
}