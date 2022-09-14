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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int MAXN = 2010;
const int MAXF = 9;

int dp[MAXN][1000][9];
int pos[MAXN], to[MAXN];

vector<vector<int>> t;
vector<int> cnt;
vector<int> msk;
int mapa[1953125];

void write(int type) {
    cout << "! " << type << endl;
    for (int j = 0; j < 9; ++j) {
        cout << t[type][j] << " ";
    }
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;     
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        pos[i] = a;
        to[i] = b;
    }

    vector<int> st(10);
    st[0] = 1;
    for (int i = 1; i < 10; ++i) {
        st[i] = st[i - 1] * 5;
    }

    for (int mask = 0; mask < st[9]; ++mask) {
        int sum = 0;
        vector<int> d(9);
        for (int tmp = mask, i = 0; i < 9; tmp /= 5, ++i) {
            d[i] = tmp % 5;
            sum += tmp % 5;
        }
        if (sum > 4) {
            continue;
        }
        mapa[mask] = sz(msk);
        msk.push_back(mask);
        t.push_back(d);
        cnt.push_back(sum);
    }

    

    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int type = sz(t) - 1; type >= 0; --type) {
            vector<int> bits;
            for (int b = 0; b < 9; ++b) {
                if (t[type][b] > 0) {
                    bits.push_back(b);
                }
            }

            for (int floor = 0; floor < 9; ++floor) {
                if (dp[i][type][floor] == -1) {
                    continue;
                }
                if (i < n && cnt[type] < 4) {
                    int b = pos[i];
                    int nxt = mapa[msk[type] + st[to[i]]];
                    if (dp[i + 1][nxt][b] == -1) {
                        dp[i + 1][nxt][b] = dp[i][type][floor] + abs(b - floor);
                    } else {
                        dp[i + 1][nxt][b] = min(dp[i + 1][nxt][b], 
                                            dp[i][type][floor] + abs(b - floor));
                    }
                }

                for (int b : bits) {
                    int nxt = mapa[msk[type] - st[b]];
                    if (dp[i][nxt][b] == -1) {
                        dp[i][nxt][b] = dp[i][type][floor] + abs(b - floor);
                    } else {
                        dp[i][nxt][b] = min(dp[i][nxt][b], 
                                        dp[i][type][floor] + abs(b - floor));
                    }
                }
            }
        }
    }

    int res = 1e9;

    for (int i = 0; i < 9; ++i) {
        if (dp[n][0][i] != -1) {
            res = min(res, dp[n][0][i] + 2 * n);
        }
    }

    cout << res << endl;

    return 0;
}