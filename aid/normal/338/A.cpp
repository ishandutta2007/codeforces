#include <iostream>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 9;

int power(int a, int p) {
    if(p == 0)
        return 1;
    if(p % 2)
        return ((long long)a * power(a, p - 1)) % MOD;
    int x = power(a, p / 2);
    return ((long long)x * x) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int p = n - n / k;
    if(p >= m)
        cout << m << '\n';
    else {
        int a = ((long long)(power(2, m - p) - 1) * 2 * k) % MOD;
        cout << ((long long)a + m - (m - p) * k) % MOD  << '\n';
    }
}