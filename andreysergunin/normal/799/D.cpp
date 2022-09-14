#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int MAXN = 2000;
const int INF = 1e9;
    
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    
    int a, b;
    cin >> a >> b;
    int w, h;
    cin >> w >> h;

    int qq;
    cin >> qq;

    vector<int> t(qq);
    for (int i = 0; i < qq; ++i)
        cin >> t[i];

    sort(all(t));
    reverse(all(t));
    qq = min(qq, 50);
    t.resize(qq);

    vector<int> v;
    for (int i = a; i >= 1; --i) {
        v.push_back((a - 1) / i + 1);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());

    vector<int> p(a + 1);
    for (int i = 0; i < sz(v); ++i)
        p[v[i]] = i;

    vector<int> u;
    for (int i = b; i >= 1; --i) {
        u.push_back((b - 1) / i + 1);
    }
    sort(all(u));
    u.resize(unique(all(u)) - u.begin());

    vector<int> q(b + 1);
    for (int i = 0; i < sz(u); ++i)
        q[u[i]] = i;


    int n = sz(v);
    int m = sz(u);

    vector<vector<int>> dp(n, vector<int>(m, INF));
    vector<vector<int>> nxt(n, vector<int>(m, INF));
    dp[0][0] = 0;
    nxt[0][0] = 0;

    for (int k = 0; k < qq; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll x = (a - 1) / v[i] + 1;
                ll y = (b - 1) / u[j] + 1;
                // cout << v[i] << " " << u[j] << " " << x << " " << y  << endl;

                ll x1, y1; 
                x1 = (a - 1) / (x * t[k]) + 1;
                y1 = (b - 1) / y + 1;
                // cout << x1 << ' ' << y1 << endl;
                // cout << p[x1] << " " << q[y1] << endl;
                nxt[i][j] = min(nxt[i][j], dp[p[x1]][q[y1]] + 1);

                x1 = (a - 1) / x + 1;
                y1 = (b - 1) / (y * t[k]) + 1;
                // cout << x1 << ' ' << y1 << endl;
                // cout << p[x1] << " " << q[y1] << endl;
                nxt[i][j] = min(nxt[i][j], dp[p[x1]][q[y1]] + 1);
            }
        }
        dp = nxt;
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = dp[p[(a - 1) / w + 1]][q[(b - 1) / h + 1]];
    ans = min(ans, dp[p[(a - 1) / h + 1]][q[(b - 1) / w + 1]]);
    cout << (ans == INF ? -1 : ans) << endl;
}