#include <iostream>

using namespace std;

long double pow(long double a, int k) {
    long double res = 1;
    while(k) {
        if(k & 1)
            res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    int m, n;
    cin >> m >> n;
    long double ans = m;
    for(int i = 1; i < m; i++)
        ans -= pow((long double)i / m, n);
    cout << ans << '\n';
    return 0;
}