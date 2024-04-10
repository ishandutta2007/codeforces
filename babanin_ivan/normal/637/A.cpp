#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp std::make_pair
#define x first
#define y second

typedef std::pair<int, int> PII;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;
typedef long double ld;
typedef std::pair<ld, ld> PLD;
typedef std::pair<double, double> PDD;

using namespace std;

const int N = 1000 * 1000 + 10;
int cnt[N];

void solve() {
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
        if (ans == -1 || cnt[ans] < cnt[x]) {
            ans = x;
        }
    }
    cout << ans << "\n";
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    return 0;
}