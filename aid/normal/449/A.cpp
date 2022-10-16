#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    if(k + 2 > n + m) {
        cout << -1 << '\n';
        return 0;
    }
    long long ansn = (long long)(n / min(k + 1, n)) *
        (m / (max(0, k - n + 1) + 1)),
        ansm = (long long)(m / min(k + 1, m)) *
        (n / (max(0, k - m + 1) + 1));
    cout << max(ansn, ansm) << '\n';
    return 0;
}