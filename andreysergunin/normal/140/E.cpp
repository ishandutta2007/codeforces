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
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 5010;

int p;
int dp[MAXN][MAXN];

void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= p;
    a = c;
}

void add(int &a, int b) {
    a += b;
    if (a >= p) {
        a -= p;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n, m;
    cin >> n >> m >> p;
    // n = 1000000;
    // m = 1000000;
    // p = 1000000000;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        // l[i] = 10;
    }

    dp[0][0] = 1;
    for (int i = 0; i < MAXN - 1; ++i) {
        for (int j = 0; j <= min(i, m); ++j) {
            int tmp;

            tmp = dp[i][j];
            // mul(tmp, m - j);
            add(dp[i + 1][j + 1], tmp);
            
            if (j > 0) {
                tmp = dp[i][j];
                mul(tmp, j - 1);
                add(dp[i + 1][j], tmp);
            } 
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j <= l[i]; ++j) {
    //         cout << dp[l[i]][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i < MAXN; ++i) {
    //     a[i][i - 1] = 1;
    //     for (int j = i; j < MAXN; ++j) {
    //         a[i][j] = a[i][j - 1];
    //         mul(a[i][j], j);
    //     }
    // }

    vector<vector<int>> res(n);

    int cur = 1;

    res[0].resize(l[0] + 1);
    for (int i = 0; i <= l[0]; ++i) {
        if (i > m) {
            continue;
        }
        res[0][i] = dp[l[0]][i];
        mul(res[0][i], cur);
        mul(cur, m - i);
    }   

    for (int i = 1; i < n; ++i) {
        res[i].resize(l[i] + 1);
        int sum = 0;
        for (int j = 0; j <= l[i - 1]; ++j) {
            add(sum, res[i - 1][j]);
        }

        int cur = 1;
        int fact = 1;

        for (int j = 0; j <= l[i]; ++j) {
            if (j > m) {
                continue;
            }

            res[i][j] = sum;
            mul(res[i][j], dp[l[i]][j]);
            mul(res[i][j], cur);
            mul(cur, m - j);

            if (l[i - 1] >= j) {
                int tmp = res[i - 1][j];
                mul(tmp, dp[l[i]][j]);
                mul(tmp, fact);
                mul(fact, j + 1);

                sub(res[i][j], tmp);
            }
        }

        if (i >= 2) {
            res[i - 2].clear();
            res[i - 2].shrink_to_fit();
        }
    }

    int ans = 0;
    for (int i = 0; i <= l[n - 1]; ++i) {
        add(ans, res[n - 1][i]);
    }

    cout << ans << endl;
    return 0;
}