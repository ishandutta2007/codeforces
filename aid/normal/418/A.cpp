#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if(n * k > n * (n - 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    cout << n * k << '\n';
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
            cout << j + 1 << ' ' << (j + i) % n + 1 << '\n';
    return 0;
}