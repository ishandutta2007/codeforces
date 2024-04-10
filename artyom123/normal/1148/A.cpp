#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans1 = 2 * c + 2 * min(a, b) + max(0ll, min(a - b, 1ll));
    long long ans2 = 1 + 2 * c + 2 * min(a, b - 1);
    cout << max(ans1, ans2);
    return 0;
}