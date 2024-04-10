#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int nn = n, mm = m, kk = k;
    int a = gcd(n, k);
    n /= a;
    k /= a;
    a = gcd(m, k);
    m /= a;
    k /= a;
    if (k > 2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (k == 2) {
        cout << "0 0" << endl;
        cout << n << " 0" << endl;
        cout << "0 " << m << endl;
    } else {
        if (n * 2 <= nn) {
            cout << "0 0" << endl;
            cout << 2 * n << " 0" << endl;
            cout << "0 " << m << endl;
        } else {
            cout << "0 0" << endl;
            cout << n << " 0" << endl;
            cout << "0 " << 2 * m << endl;
        }
    }
}