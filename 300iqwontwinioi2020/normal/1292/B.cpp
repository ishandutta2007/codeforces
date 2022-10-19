#include <bits/stdc++.h>
using namespace std;
#define int long long

int x[10000], y[10000];
int X, Y, T;

main() {
    ios_base::sync_with_stdio(0);
    int a1, a2, b1, b2;
    cin >> x[0] >> y[0];
    cin >> a1 >> a2 >> b1 >> b2;
    cin >> X >> Y >> T;
    int n = 1;
    while (1){
        x[n] = x[n - 1] * a1 + b1;
        y[n] = y[n - 1] * a2 + b2;
        if (x[n] > X + T || y[n] > Y + T)
            break;
        n++;
    }
    n--;
    int ans = 0;
    for (int l = 0; l <= n; l++)
        for (int r = l; r <= n; r++)
            for (int k = l; k <= r; k++){
                int pas = abs (X - x[k]) + abs (Y - y[k]);
                pas += x[r] + y[r] - x[l] - y[l];
                pas += min (x[r] + y[r] - x[k] - y[k], x[k] + y[k] - x[l] - y[l]);
                if (pas <= T)
                    ans = max (ans, r - l + 1);
            }
    cout << ans << endl;
}