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
mt19937 rr(random_device{}());

const int MAXN = 100;
const int INF = 1e9;

int dp[MAXN][MAXN][MAXN][3];
int f[MAXN][MAXN];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    vector<int> b;
    vector<int> c;

    vector<int> x(n);
    vector<int> y(n);
    vector<int> z(n);

    string t;
    for (int i = 0; i < n; ++i) {
        x[i] = sz(a);
        y[i] = sz(b);
        z[i] = sz(c);
        if (s[i] == 'V')
            a.push_back(i);
        else if (s[i] == 'K')
            b.push_back(i);
        else 
            c.push_back(i);
    }

    // for (int i = 0; i < n; ++i)
    //     cout << x[i] << " " << y[i] << " " << z[i] << endl;


    for (int i = 0; i <= sz(a); ++i) {
        for (int j = 0; j <= sz(b); ++j) {
            for (int k = 0; k <= sz(c); ++k) {
                for (int l = 0; l < 3; ++l)
                    dp[i][j][k][l] = INF;
            }
        }
    }
    dp[0][0][0][2] = 0;

    for (int i = 0; i <= sz(a); ++i) {
        for (int j = 0; j <= sz(b); ++j) {
            for (int k = 0; k <= sz(c); ++k) {
                if (i < sz(a)) {
                    int pos = i + max(j, y[a[i]]) + max(k, z[a[i]]);
                    dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][0] + pos - (i + j + k));
                    dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][1] + pos - (i + j + k));
                    dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][2] + pos - (i + j + k));
                }

                if (j < sz(b)) {
                    int pos = j + max(i, x[b[j]]) + max(k, z[b[j]]);
                    dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][1] + pos - (i + j + k));
                    dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][2] + pos - (i + j + k));
                } 

                if (k < sz(c)) {
                    int pos = k + max(i, x[c[k]]) + max(j, y[c[k]]);
                    dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2], dp[i][j][k][0] + pos - (i + j + k));
                    dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2], dp[i][j][k][1] + pos - (i + j + k));
                    dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2], dp[i][j][k][2] + pos - (i + j + k));
                } 
            } 
        }
    }

    // for (int i = 0; i <= sz(a); ++i) {
    //     for (int j = 0; j <= sz(b); ++j) {
    //         for (int k = 0; k <= sz(c); ++k) {
    //             for (int l = 0; l < 3; ++l) {
    //                 cout << i << " " << j << " " << k << " " << l << " " << dp[i][j][k][l] << endl;
    //             }
                
    //         }
    //     }
    // }

    int ans = INF;
    for (int l = 0; l < 3; ++l) {
        ans = min(ans, dp[sz(a)][sz(b)][sz(c)][l]);
    }
    cout << ans << endl;


    return 0;
}