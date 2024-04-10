#include <bits/stdc++.h>

using namespace std;

int N, R;
const int NMAX = 2000 + 5;

int x[NMAX];
long double y[NMAX];

int main()
{
    cin >> N >> R;
    R *= 2;

    for (int i = 1; i <= N; ++ i) {
        cin >> x[i];
        y[i] = R / 2;
        for (int j = 1; j < i; ++ j) {
            int d = abs(x[i] - x[j]);
            if (d == R)
                y[i] = max(y[i], y[j]);
            else {
                long double dy = sqrtl(R * R - d * d);
                y[i] = max(y[i], y[j] + dy);
            }
        }
    }

    cout << fixed << setprecision(12);
    for (int i = 1; i <= N; ++ i)
        cout << y[i] << " \n"[i == N];
    return 0;
}