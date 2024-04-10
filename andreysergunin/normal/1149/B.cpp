#include <iostream>
#include <stdio.h>
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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 255;
const int MAXM = 100100;
const int ALPH = 26;

int dp[MAXN][MAXN][MAXN];
vector<int> rg;

int to[MAXM][ALPH];
string t[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // sieve(MAXN);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    rg.resize(3);

    vector<int> prv(ALPH, n);
    for (int i = n; i >= 0; --i) {
        if (i < n) {
            prv[s[i] - 'a'] = i;
        }
        for (int j = 0; j < 26; ++j) {
            to[i][j] = prv[j];
        }
    }

    for (int qw = 0; qw < q; ++qw) {
        char c;
        int pos;
        cin >> c >> pos;
        --pos;
        if (c == '-') {
            --rg[pos];
            t[pos].pop_back();
        } else {
            char ch;
            cin >> ch;

            t[pos] += ch;

            vector<int> lf(3);
            ++rg[pos];
            lf[pos] = rg[pos];

            for (int i = lf[0]; i <= rg[0]; ++i) {
                for (int j = lf[1]; j <= rg[1]; ++j) {
                    for (int k = lf[2]; k <= rg[2]; ++k) {
                        // cout << i << " " << j << " " << k << endl;
                        dp[i][j][k] = n + 1;
                        if (i > 0) {
                            // cout << "here" << endl;
                            int p = dp[i - 1][j][k];
                            // cout << p << endl;
                            if (p < n) {
                                int c = t[0][i - 1] - 'a';
                                // cout << c << endl;
                                dp[i][j][k] = min(to[p][c] + 1, dp[i][j][k]);
                            }
                        }

                        if (j > 0) {
                            int p = dp[i][j - 1][k];
                            if (p < n) {
                                int c = t[1][j - 1] - 'a';
                                dp[i][j][k] = min(to[p][c] + 1, dp[i][j][k]);
                            }
                        }

                        if (k > 0) {
                            int p = dp[i][j][k - 1];
                            if (p < n) {
                                int c = t[2][k - 1] - 'a';
                                dp[i][j][k] = min(to[p][c] + 1, dp[i][j][k]);
                            }
                        }
                    }
                }
            }
        }

        // cout << dp[rg[0]][rg[1]][rg[2]] << endl;
        // cout << rg[0] << " " << rg[1] << " " << rg[2] << endl;

        if (dp[rg[0]][rg[1]][rg[2]] <= n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}