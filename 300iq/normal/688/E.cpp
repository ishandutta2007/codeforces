#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int u, v;
const int MAXN = (int) 500 + 7;

bool dp[MAXN][MAXN][MAXN];
int n;
int a[MAXN];
int x, k;

void calc(int i, int sum, int psum) {
    if (i == n) {
        dp[i][sum][psum] = 1;
        return;
    } else {
        if (dp[i][sum][psum]) {
            return;
        }
        dp[i][sum][psum] = 1;
        calc(i + 1, sum, psum);
        if (sum + a[i] < MAXN) {
            calc(i + 1, sum + a[i], psum);
            if (psum + a[i] < MAXN) {
                calc(i + 1, sum + a[i], psum + a[i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> can;
    calc(0, 0, 0);
    for (x = 0; x <= k; x++) {
        if (dp[n][k][x]) {
            can.pb(x);
        }
    }
    cout << can.size() << endl;
    for (auto v : can) {
        cout << v << " ";
    }
    cout << endl;
}