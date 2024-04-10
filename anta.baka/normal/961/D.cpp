#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1 << 20, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    if(n <= 4) return cout << "YES", 0;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int p = 0; p < 2; p++)
        for(int q = p + 1; q < 3; q++) {
            ll A = y[p] - y[q];
            ll B = x[q] - x[p];
            ll C = ll(x[p]) * y[q] - ll(x[q]) * y[p];
            vector<int> xx, yy;
            for(int i = 0; i < n; i++)
                if(A * x[i] + B * y[i] + C != 0) {
                    xx.push_back(x[i]);
                    yy.push_back(y[i]);
                }
            if(sz(xx) <= 2) return cout << "YES", 0;
            ll AA = yy[0] - yy[1];
            ll BB = xx[1] - xx[0];
            ll CC = ll(xx[0]) * yy[1] - ll(xx[1]) * yy[0];
            bool ok = true;
            for(int i = 0; i < sz(xx); i++)
                ok &= (AA * xx[i] + BB * yy[i] + CC == 0);
            if(ok) return cout << "YES", 0;
        }
    cout << "NO";
}