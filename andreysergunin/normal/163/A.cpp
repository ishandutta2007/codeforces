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
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 5050;
const int  P = 1e9 + 7;
int dp[MAXN][MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

void mul(int &a, int b) {
    ll ans = (ll)a * b;
    ans %= P;
    a = ans;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    string s, t;
    cin >> s >> t;

    int n = sz(s);
    int m = sz(t);

    for (int j = 0; j <= m; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = 1;
        for (int j = 0; j < m; ++j) {
            dp[i + 1][j + 1] = dp[i + 1][j];
            if (s[i] == t[j]) {
                add(dp[i + 1][j + 1], dp[i][j]);
            }
        }   
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        add(ans, dp[i + 1][m]);
        sub(ans, 1);
    }

    cout << ans << endl;
}