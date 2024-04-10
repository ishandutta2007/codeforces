#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    while(n > 1 && k) {
        ans += 2 * n - 3;
        n -= 2;
        k--;
    }
    cout << ans << '\n';
    return 0;
}