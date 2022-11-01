#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    long long n, a, b, c, d, e, p[60], sum = 0;
    long long A, B, C, D, E; A = B = C = D = E = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> a >> b >> c >> d >> e;

    for (int i = 1; i <= n; i++) {
        sum += p[i];
        E += sum/e; sum %= e;
        D += sum/d; sum %= d;
        C += sum/c; sum %= c;
        B += sum/b; sum %= b;
        A += sum/a; sum %= a;
    }

    cout << A << " " << B << " " << C << " " << D << " " << E << endl << sum << endl;
    return 0;
}