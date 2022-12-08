#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> ar(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ar[i] = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
    }
    sort(ar.begin(), ar.end());
    int ans = ar[0] + 24 * 60 - 1 - ar[n - 1];
    for (int i = 1; i < n; ++i) {
        ans = max(ans, ar[i] - ar[i - 1] - 1);
    }
    int h = ans / 60;
    int m = ans % 60;
    if (h < 10) cout << 0;
    cout << h << ":";
    if (m < 10) cout << 0;
    cout << m << endl;
}