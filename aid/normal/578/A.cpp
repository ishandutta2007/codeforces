#include <iostream>

using namespace std;

const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
const long double EPS = 1e-9;

long double solve(long double a, long double b) {
    if(a < EPS)
        return b;
    a /= 2;
    long long k = (long long)(a / b + EPS);
    if(!k)
        return INF;
    return a / k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    long long a, b;
    cin >> a >> b;
    if(a < b) {
        cout << -1 << '\n';
        return 0;
    }
    long double ans = min(solve(a - b, b), solve(a + b, b));
    if(ans >= INF - 1)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}