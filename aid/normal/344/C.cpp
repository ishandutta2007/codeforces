#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    while(b > 0) {
        ans += a / b;
        a = a % b;
        swap(a, b);
    }
    cout << ans << '\n';
}