#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << 1 << " " << 1 << " " << n - 2;
        return 0;
    }
    cout << 1 << " " << 2 << " " << n - 3;
    return 0;
}