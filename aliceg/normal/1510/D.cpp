#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <bitset>

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
//#define int ll
#define mp(a) make_pair(a)

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const int INF = 1e9 + 7;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 1e3 + 5;

void solution() {
    int n, d;
    cin >> n >> d;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<ld>> dp(n + 1, vector<ld>(10, -INF));
    vvi p(n + 1, vi(10, -1));
    dp[0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (dp[i][j] == -INF)
                continue;
            if (dp[i + 1][j] < dp[i][j]) {
                dp[i + 1][j] = dp[i][j];
                p[i + 1][j] = -1;
            }
            int k = (a[i] % 10 * j) % 10;
            if (dp[i + 1][k] < dp[i][j] + log(a[i])) {
                dp[i + 1][k] = dp[i][j] + log(a[i]);
                p[i + 1][k] = j;
            }
        }
    }
    if (dp[n][d] == -INF) {
        cout << -1;
        return;
    }
    int cur = d;
    vi ans;
    for (int i = n - 1; i >= 0; --i) {
        if (p[i + 1][cur] != -1) {
            ans.push_back(a[i]);
            cur = p[i + 1][cur];
        }
    }
    if (ans.empty()) {
        cout << -1;
        return;
    }
    cout << ans.size() << '\n';
    for (int x : ans)
        cout << x << ' ';
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}