#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
    ios_base :: sync_with_stdio(false);
    int T = 0;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int xr = 0;
        lint sum = 0;
        for (int i = 0; i < N; ++i) {
            int nr;
            cin >> nr;
            xr ^= nr;
            sum += nr;
        }
        cout << "2\n";
        cout << xr << ' ' << (sum + xr) << '\n';
    }
    return 0;
}