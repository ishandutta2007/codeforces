#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const ll INF = 1e18;
ll cnt[3][100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    int n;
    ll x, y, ans = INF, sum = 0;
    cin >> s >> x >> y;
    if (x > y) {
        swap(x, y);
        reverse(ALL(s));
    }
    n = SZ(s);
    s.insert(s.begin(), '#');
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') {
            sum += y * (cnt[1][i - 1] + cnt[2][i - 1]);
            ++cnt[0][i];
        }
        else if (s[i] == '1') {
            sum += x * cnt[0][i - 1];
            ++cnt[1][i];
        }
        else {
            sum += x * cnt[0][i - 1];
            ++cnt[2][i];
        }
        for (int j = 0; j < 3; ++j)
            cnt[j][i] += cnt[j][i - 1];
    }
    ans = sum;
    for (int i = 1; i <= n; ++i)
        if (s[i] == '?') {
            sum -= (cnt[0][i - 1] + cnt[2][i - 1]) * x + (cnt[0][n] - cnt[0][i]) * y;
            sum += cnt[1][i - 1] * y + (cnt[1][n] - cnt[1][i] + cnt[2][n] - cnt[2][i]) * x;
            ans = min(ans, sum);
        }
    cout << ans << "\n";
}