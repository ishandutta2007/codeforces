#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 3001;
const ll INF = 1e17 + 1;

int a[N];
ll med[N][N];
ll dist[N][N];
ll dp[N + 1];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    for (int l = 0; l < n; l++) {
        multiset<int, greater<int>> small;
        multiset<int> big;
        ll sumSmall = 0, sumBig = 0;
        for (int r = l; r < n; r++) {
            if (!small.size() || *small.begin() >= a[r]) {
                small.insert(a[r]);
                sumSmall += a[r];
            } else {
                big.insert(a[r]);
                sumBig += a[r];
            }
            while (small.size() > (r - l + 2) / 2) {
                ll top = *small.begin();
                small.erase(small.begin());
                sumSmall -= top;
                big.insert(top);
                sumBig += top;
            }
            while (small.size() < (r - l + 2) / 2) {
                ll top = *big.begin();
                big.erase(big.begin());
                sumBig -= top;
                small.insert(top);
                sumSmall += top;
            }
            med[l][r] = *small.begin();
            dist[l][r] = (med[l][r] * (int)small.size() - sumSmall) +
                (sumBig - med[l][r] * (int)big.size());
        }
    }

    dp[0] = 0;
    fill(dp + 1, dp + n + 1, INF);
    vector<ll> last(n + 1);
    last[0] = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (last[j - 1] <= med[j - 1][i - 1] && dp[i] > dp[j - 1] + dist[j - 1][i - 1]) {
                dp[i] = dp[j - 1] + dist[j - 1][i - 1];
                last[i] = med[j - 1][i - 1];
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int tst = 1;
    while (tst--)
        solve();
}