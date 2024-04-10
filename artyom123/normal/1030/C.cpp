#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        sum += a[i];
    }
    for (int i = 2; i <= sum; i++) {
        if (sum % i == 0) {
            int now = 0;
            int ans = 0;
            for (int j = 0; j < n; j++) {
                now += a[j];
                if (now == sum / i) {
                    ans++;
                    now = 0;
                }
            }
            if ((ans == i && now == 0) || (sum / i == 0)) {
                cout << "YES";
                return 0;
            }
        }
    }
    if (sum == 0) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}