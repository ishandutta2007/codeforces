/**
 *  created: 12/04/2021, 10:31:44
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;
const int max_d = 10;

int n, d, a[max_n], p[max_n][max_d];
bool f[max_n][max_d];
long double dp[max_n][max_d];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
        for (int x = 0; x < max_d; ++x) {
            dp[i][x] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        long double val = logl(a[i]);
        //cout << "#" << i << " " << val << endl;
        if (dp[i + 1][a[i] % 10] < val) {
            dp[i + 1][a[i] % 10] = val;
            f[i + 1][a[i] % 10] = 1;
            p[i + 1][a[i] % 10] = -1;
        }
        for (int x = 0; x < max_d; ++x) {
            if (dp[i][x] >= 0) {
                //cout << i << ": " << x << ": " << dp[i][x] << endl;
                if (dp[i + 1][x] < dp[i][x]) {
                    dp[i + 1][x] = dp[i][x];
                    f[i + 1][x] = 0;
                    p[i + 1][x] = -2;
                }
                int nxt = (x * a[i]) % 10;
                if (dp[i + 1][nxt] < dp[i][x] + val) {
                    dp[i + 1][nxt] = dp[i][x] + val;
                    f[i + 1][nxt] = 1;
                    p[i + 1][nxt] = x;
                }
            }
        }
    }
    if (dp[n][d] < 0) {
        puts("-1");
        return 0;
    }
    int pos = n;
    vector<int> ans;
    while (true) {
        if (f[pos][d]) {
            ans.push_back(a[pos - 1]);
            if (p[pos][d] == -1) {
                break;
            }
            d = p[pos][d];
            --pos;
        } else {
            --pos;
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
    return 0;
}