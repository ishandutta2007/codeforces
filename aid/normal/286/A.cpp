#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n % 4 != 0 && n % 4 != 1) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < n / 2; i += 2)
        cout << i + 2 << ' ' << n - i << ' ';
    if(n & 1)
        cout << n / 2 + 1 << ' ';
    for(int i = (n + 1) / 2; i < n; i += 2)
        cout << n - i - 1 << ' ' << i + 1 << ' ';
    cout << '\n';
    return 0;
}