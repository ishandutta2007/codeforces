#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;

typedef long long int lint;

lint sum;
int sz;
int nr[NMAX];
lint add[NMAX];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    sz = 1;
    for (int i = 1; i <= N; ++ i) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, x;
            cin >> a >> x;
            if (a > sz)
                a = sz;
            add[a] += x;
            sum += 1LL * a * x;
        }
        else if (t == 2) {
            int a;
            cin >> a;
            nr[++ sz] = a;
            sum += a;
        }
        else {
            sum -= (nr[sz] + add[sz]);
            add[sz - 1] += add[sz];
            add[sz] = 0;
            -- sz;
        }

        cout << fixed << setprecision(12) << 1.0 * sum / sz << '\n';
    }
    return 0;
}