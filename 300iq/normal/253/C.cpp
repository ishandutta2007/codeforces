#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXK = (int) 100 + 7;
const int MAXN = (int) 1e5 + 7;
int dp[MAXK][MAXN];
bool used[MAXK][MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (auto &x : a) {
        scanf("%d", &x);
        x++;
    }
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    queue <pair <int, int> > q;
    q.push({r1 - 1, c1});
    dp[r1 - 1][c1] = 0;
    used[r1 - 1][c1] = 1;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.fc, y = p.sc;
        if (x != n - 1) {
            if (y <= a[x + 1]) {
                if (!used[x + 1][y]) {
                    q.push({x + 1, y});
                    used[x + 1][y] = 1;
                    dp[x + 1][y] = dp[x][y] + 1;
                } 
            } else {
                if (!used[x + 1][a[x + 1]]) {
                    q.push({x + 1, a[x + 1]});
                    used[x + 1][a[x + 1]] = 1;
                    dp[x + 1][a[x + 1]] = dp[x][y] + 1;
                }
            }
        } 
        if (x != 0) {
            if (y <= a[x - 1]) {
                if (!used[x - 1][y]) {
                    q.push({x - 1, y});
                    used[x - 1][y] = 1;
                    dp[x - 1][y] = dp[x][y] + 1;
                } 
            } else {
                if (!used[x - 1][a[x - 1]]) {
                    q.push({x - 1, a[x - 1]});
                    used[x - 1][a[x - 1]] = 1;
                    dp[x - 1][a[x - 1]] = dp[x][y] + 1;
                }
            }
        }
        if (y < a[x]) {
            if (!used[x][y + 1]) {
                q.push({x, y + 1});
                used[x][y + 1] = 1;
                dp[x][y + 1] = dp[x][y] + 1;
            }
        }
        if (y != 1) {
            if (!used[x][y - 1]) {
                q.push({x, y - 1});
                used[x][y - 1] = 1;
                dp[x][y - 1] = dp[x][y] + 1;
            }
        }
    }
    printf("%d\n", dp[r2 - 1][c2]);
}