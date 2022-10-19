#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int l[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < n) return cout << -1, 0;
    ans[m] = n - l[m] + 1;
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        if (i + l[i] - 1 > n) ok = 0;
    }
    for (int i = m - 1; i >= 1; i--) {
        ans[i] = max(i, ans[i + 1] - l[i]);
    }
    if (!ok) return cout << -1, 0;
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}