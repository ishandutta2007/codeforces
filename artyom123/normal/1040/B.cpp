#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; ; i++) {
        if (n <= i * (2 * k + 1)) {
            int o = (i * (2 * k + 1)) - n;
            cout << i << "\n";
            cout << k + 1 - min(o, k) << " ";
            int f = k + 1 - min(o, k);
            int last = f;
            for (int j = f + (2 * k + 1); j <= n; j += (2 * k + 1)) {
                cout << j << " ";
                last = j;
            }
            return 0;
        }
    }
    return 0;
}