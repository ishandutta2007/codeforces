#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) return cout << "NO", 0;
    cout << "YES\n";
    vector<int> ans(2 * n + 1);
    vector<bool> sign(2 * n + 1);
    for (int i = 1; i <= 2 * n; i += 2) sign[i] = 1;
    for (int i = 1; i <= n; i++) {
        if (sign[i]) ans[i] = 2 * i, ans[i + n] = 2 * i - 1;
        else ans[i] = 2 * i - 1, ans[i + n] = 2 * i;
    }
    for (int i = 1; i <= 2 * n; i++) cout << ans[i] << ' ';
    return 0;
}