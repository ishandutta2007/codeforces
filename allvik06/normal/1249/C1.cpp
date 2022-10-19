#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

int res, b = 10, minres;
void ans(int n, vector <int> &p, int last) {
    if (res >= n && res < minres) {
        minres = res;
        return;
    }
    for (int i = last; i < b; ++i) {
        res += p[i];
        ans(n, p, i + 1);
        res -= p[i];
    }
}
signed main() {
    int q;
    cin >> q;
    vector <int> p(b);
    p[0] = 1;
    for (int i = 1; i < b; ++i) {
        p[i] = p[i - 1] * 3;
    }
    for (int w = 0; w < q; ++w) {
        int n;
        cin >> n;
        res = 0, minres = INF;
        ans(n, p, 0);
        if (minres >= n) {
            cout << minres << "\n";
        }
        else {
            for (int i = 0; i < b; ++i) {
                if (p[i] >= n) {
                    cout << p[i] << "\n";
                    break;
                }
            }
        }
    }
}