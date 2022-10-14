#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0' && b[i] == '1') {
            if (i < n - 1 && a[i + 1] == '1' && b[i + 1] == '0') {
                ans++;
                i++;
                continue;
            }
            else {
                ans++;
            }
        }
        if (a[i] == '1' && b[i] == '0') {
            if (i < n - 1 && a[i + 1] == '0' && b[i + 1] == '1') {
                ans++;
                i++;
                continue;
            }
            else {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}