#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k, s;
    cin >> n >> k >> s;
    if ((n - 1) * k < s || k > s) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    int now = 1;
    while (k > 0) {
        long long d = min(n - 1, s - (k - 1));
        if (now - d < 1) {
            cout << now + d << " ";
            now = now + d;
        }
        else {
            cout << now - d << " ";
            now = now - d;
        }
        s -= d;
        k--;
    }
    return 0;
}