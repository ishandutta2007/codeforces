#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') % 2 == 0) {
            ans += (i + 1);
        }
    }
    cout << ans;
    return 0;
}