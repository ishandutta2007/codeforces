#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100 + 5;

int x[NMAX];

int main() {
    int N, d;
    cin >> N >> d;
    for (int i = 1; i <= N; ++ i)
        cin >> x[i];
    sort(x + 1, x + N + 1);

    int ans = 2;
    for (int i = 1; i < N; ++ i) {
        const int l = x[i + 1] - x[i];
        if (l == 2 * d)
            ++ ans;
        else if (l > 2 * d)
            ans += 2;
    }

    cout << ans << endl;
    return 0;
}