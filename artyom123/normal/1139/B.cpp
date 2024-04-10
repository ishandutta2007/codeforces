#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    int prev = INF;
    long long ans = 0;
    for (auto &c : a) {
        cin >> c;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (prev <= 1) {
            break;
        }
        ans += min(a[i], prev - 1);
        prev = min(a[i], prev - 1);
    }
    cout << ans;
    return 0;
}