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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;

mt19937 rr(random_device{}());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 55;
const int P = 1e9 + 7;

int f[MAXN][MAXN], g[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
int c[MAXN][MAXN][MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= P)
        a -= P;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0)
        a += P;
}

void mul(int &a, int b) {
    ll ans = (ll)a * b;
    ans %= P;
    a = ans;
}

int binPow(int a, int b) {
    if (b == 0)
        return 1;
    int x = binPow(a, b / 2);
    mul(x, x);
    if (b & 1) {
        mul(x, a);
    }
    return x;
}


int r[MAXN];

int choose(int n, int k)  {
    if (n == -1 && k == 0)
        return 1;
    if (k < 0 || k > n)
        return 0;
    int ans = 1;
    for (int i = 0; i < k; ++i) {
        int x = n;
        sub(x, i);
        mul(ans, x);
        mul(ans, r[i + 1]);
    }
    return ans;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i < MAXN; ++i)
        r[i] = binPow(i, P - 2);

    g[0][1] = 1;
    f[0][1] = 1;
    dp[0][1][0][1] = 1;
    dp[0][1][0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            dp[0][0][i][j] = 1;
        }
    }
    

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            for (int x = 0; x <= i - 1; ++x) {
                int y = i - 1 - x;
                int tmp = 0;
                tmp = f[x][j];
                mul(tmp, f[y][j]);
                add(g[i][j], tmp);

                for (int k = j + 1; k < MAXN; ++k) {
                    tmp = f[x][j];
                    mul(tmp, f[y][k]);
                    add(g[i][j], tmp);

                    tmp = f[y][j];
                    mul(tmp, f[x][k]);
                    add(g[i][j], tmp);
                }
            }
            // cout << i << " " << j << " " << g[i][j] << endl;

            for (int k = 0; k < MAXN; ++k)
                c[i][j][k] = choose(g[i][j] + k - 1, k);

            for (int l = i; l >= 1; --l) {
                for (int cut = (l == i ? j : MAXN - 1); cut >= 1; --cut) {
                    for (int cnt = 0; cnt * l <= i && cnt * cut <= j; ++cnt) {

                        int tmp = c[l][cut][cnt];
                        if (cut == MAXN - 1) {
                            mul(tmp, dp[i - cnt * l][j - cnt * cut][l + 1][1]);
                        } else {
                            mul(tmp, dp[i - cnt * l][j - cnt * cut][l][cut + 1]);
                        }
                        add(dp[i][j][l][cut], tmp);
                        // if (i == 2 && j == 1 && l == 1 && cut == MAXN - 1 && cnt == 0) {
                        //     cout << "HERE" << endl;
                        //     cout << g[l][cut] << endl;
                        //     cout << dp[i][j][l][cut] << endl;
                        // }
                    }
                }
            }

            f[i][j + 1] = dp[i][j][1][1];
        }
    }

    // cout << dp[2][1][2][1] << endl;
    // cout << dp[2][1][1][MAXN - 1] << endl;

    cout << f[n][m] << endl;
}