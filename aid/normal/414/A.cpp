#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int p = n / 2;
    if(n == 1) {
        cout << (k > 0? -1 : 1) << '\n';
        return 0;
    }
    if(k < p) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < p - 1; i++) {
        cout << 2 * i + 1 << ' ' << 2 * i + 2 << ' ';
        k--;
    }
    int q = (2 * p - 1 + k - 1) / k;
    cout << q * k << ' ' << (q + 1) * k;
    if(n & 1)
        cout << ' ' << (q + 1) * k + 1;
    cout << '\n';
    return 0;
}