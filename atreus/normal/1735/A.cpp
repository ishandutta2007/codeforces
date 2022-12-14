#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int t = n - 3;
        int opt = 0;
        for (int i = t/3 - 10; i <= t/3 + 10; i++) {
            if (i < 1 or t - 1 - i < i)
                continue;
            opt = max(opt, min(i - 1, t - 1 - i - i));
        }
        cout << opt << '\n';
    }
}