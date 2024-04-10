#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b, a--, b--;
    if (a > b) swap(a, b);
    for (int i = 0; ; ++i) {
        if (a < n / 2 && n / 2 <= b) {
            if (i == 0) cout << "Final!\n";
            else cout << __lg(n) << endl;
            return 0;
        }
        if (a >= n / 2) a -= n / 2, b -= n / 2;
        n /= 2;
    }
}