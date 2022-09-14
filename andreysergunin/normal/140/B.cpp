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

const double EPS = 1e-9;
const double PI = acos(-1);

const int MAXN = 333;
int p[MAXN][MAXN];
int q[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
            --p[i][j];
        }

        for (int j = 0; j < n; ++j) {
            q[i][p[i][j]] = j;
        }
    }

    vector<int> res(n);
    vector<int> opt(n, n);

    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < n; ++j) {
            int cur = n;
            for (int k = 0; k <= i; ++k) {
                if (k == j) {
                    continue;
                }
                cur = min(q[n][k], cur);
            }
            if (cur < n) {
                if (opt[j] > q[j][p[n][cur]]) {
                    opt[j] = q[j][p[n][cur]];
                    res[j] = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    // for (int i = 0; i < n; ++i) {
    //     cout << opt[i] << " ";
    // }
    // cout << endl;

    return 0;
}