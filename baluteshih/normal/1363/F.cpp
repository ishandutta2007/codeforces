#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

string a, b;
const int INF = 1e9;
int dp[2005][2005], chk[2005][2005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, cnt[26] = {};
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> a >> b;
        for (int i = 0; i <= SZ(b); ++i)
            for (int j = 0; j <= SZ(a); ++j)
                dp[i][j] = INF, chk[i][j] = 0;
        fill(dp[SZ(b)], dp[SZ(b)] + SZ(a) + 1, 0);
        fill(chk[SZ(b)], chk[SZ(b)] + SZ(a) + 1, 1);
        fill(cnt, cnt + 26, 0);
        for (int i = SZ(b) - 1; i >= 0; --i) {
            ++cnt[b[i] - 'a'];
            int fin = 0, cnt2[26] = {};
            for (int j = 0; j < 26; ++j)
                if (cnt[j] == 0)
                    ++fin;
            for (int j = SZ(a) - 1; j >= 0; --j) {
                ++cnt2[a[j] - 'a'];
                if (cnt2[a[j] - 'a'] == cnt[a[j] - 'a'])
                    ++fin;
                if (fin == 26)
                    chk[i][j] = 1;
            }
        }
        if (chk[0][0] != 1) {
            cout << "-1\n";
            continue;
        }
        for (int i = SZ(b) - 1; i >= 0; --i)
            for (int j = SZ(a) - 1; j >= 0; --j) {
                dp[i][j] = dp[i][j + 1];
                if (b[i] == a[j])
                    dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                if (chk[i][j])
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            }
        cout << dp[0][0] << "\n";
    }
}