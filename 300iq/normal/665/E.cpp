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
const int MAXN = (int) 3e7 + 7;
int to[MAXN][2];
int n, k;
int dp[MAXN];
int lim = 30;
int sz = 1;

int calc(int s) {
    int cur = 0;
    int v = 0;
    int ans = 0;
    for (int i = lim; i >= 0; i--) {
        int b = ((s & (1 << i)) == 0 ? 0 : 1);
        if ((cur | (1 << i)) >= k) {
            if (to[v][b ^ 1] != 0) {
                ans += dp[to[v][b ^ 1]];
            }
            if (to[v][b] != 0) {
                v = to[v][b];
            } else {
                break;
            }
        } else {
            cur |= (1 << i);
            b ^= 1;
            if (to[v][b] != 0) {
                v = to[v][b];
            } else {
                break;
            }
        }
    }
    return ans;
}

void add(int s) {
    int v = 0;
    for (int i = lim; i >= 0; i--) {
        int b = ((s & (1 << i)) == 0 ? 0 : 1);
        dp[v]++;
        if (to[v][b] == 0) {
            to[v][b] = sz++;
        }
        v = to[v][b];
    }
    dp[v]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    int x;
    int s = 0;
    ll ans = 0;
    add(0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        s ^= x;
        ans += calc(s);
        add(s);
    }
    cout << ans << endl;
}