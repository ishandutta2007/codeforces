#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

string s1, s2, t;

int go[200][30];

int getgo(int v, int c) {
    if (go[v][c] != -1)
        return go[v][c];
    if (v + 1 <= t.size() && t[v] == c)
        return go[v][c] = v + 1;

    vector <char> a;
    for (int i = 0; i < v; ++i)
        a.pb(t[i]);
    a.pb(c);
    for (int i = v; i > 0; --i) {
        bool f = true;
        for (int j = 0; j < i; ++j)
            if (t[j] != a[a.size() - i + j]) {
                f = false;
                break;
            }
        if (f)
            return go[v][c] = i;
    }

    return go[v][c] = 0;
}

int dp[101][101][101];
pair <pair <int, int>, char> par[101][101][101];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> s1 >> s2 >> t;
    for (int i = 0; i < s1.size(); ++i)
        s1[i] -= 'A';
    for (int i = 0; i < s2.size(); ++i)
        s2[i] -= 'A';

    for (int i = 0; i < t.size(); ++i)
        t[i] -= 'A';

    memset(go, 255, sizeof(go));
    memset(dp, 255, sizeof(dp));
    int best = 0;
    dp[0][0][0] = 0;

    for (int l = 0; l <= min(s1.size(), s2.size()); ++l) {
        for (int x = 0; x < t.size(); ++x)
            for (int j = 0; j <= s1.size(); ++j) {
                if (dp[l][x][j] == -1)
                    continue;
                if (best < l)
                    best = l;
                if (j == s1.size())
                    continue;

                if (dp[l][x][j + 1] == -1 || dp[l][x][j + 1] > dp[l][x][j]) {
                    dp[l][x][j + 1] = dp[l][x][j];
                    par[l][x][j + 1] = par[l][x][j];
                }
                for (int z = dp[l][x][j]; z < s2.size(); ++z)
                    if (s2[z] == s1[j]) {
                        int tmp = dp[l + 1][getgo(x, s2[z])][j + 1];
                        if (tmp == -1 || tmp > z + 1) {
                            dp[l + 1][getgo(x, s2[z])][j + 1] = z + 1;
                            par[l + 1][getgo(x, s2[z])][j + 1] = mp(mp(x, j), s2[z]);
                        }
                        break;
                    }
            }
    }
    if (best == 0)
        cout << 0 << endl;
    else {
        for (int x = 0; x < t.size(); ++x)
            for (int j = 0; j <= s1.size(); ++j) 
                if (dp[best][x][j] != -1) {
                    string res;
                    pair <int, int> cur = mp(x, j);
                    for (int i = best; i > 0; --i) {
                        res.pb(par[i][cur.first][cur.second].second);
                        cur = par[i][cur.first][cur.second].first;
                    }
                    reverse(res.begin(), res.end());
                    for (int i = 0; i < res.size(); ++i)
                        res[i] += 'A';
                    cout << res << endl;
                    return 0;
                }
    }
    return 0;
}