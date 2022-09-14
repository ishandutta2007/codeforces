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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int P = 998244353;
const int MAXN = 2018;

int pw[MAXN * MAXN];

int fact[MAXN];
int rfact[MAXN];

int pwr[MAXN * MAXN];
int dp[MAXN][MAXN];

int scc[MAXN];
int res[MAXN];

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
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

int binPow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = binPow(a, b / 2);
    mul(res, res);
    if (b & 1) {
        mul(res, a);
    }
    return res;
}

int choose(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int p = a;
    mul(p, binPow(b, P - 2));

    pw[0] = 1;
    pwr[0] = 1;
    for (int i = 1; i <= n * n; ++i) {
        pw[i] = pw[i - 1];
        mul(pw[i], p);

        pwr[i] = pwr[i - 1];
        mul(pwr[i], P + 1 - p);
    }

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binPow(fact[i], P - 2);
    }

    // int tmp = 1;
    // mul(tmp, binPow(4, P - 2));
    // cout << tmp << endl << endl;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int tmp = dp[i][j];
            mul(tmp, pw[j]);
            add(dp[i + 1][j], tmp);
            tmp = dp[i][j];
            mul(tmp, pwr[i - j]);
            add(dp[i + 1][j + 1], tmp);
        }
    }


    for (int i = 1; i <= n; ++i) {

        scc[i] = 1;
        for (int j = 1; j <= i - 1; ++j) {
            int x = dp[i][j];
            mul(x, scc[j]);
            sub(scc[i], x);
        }
        // cout << i << " " << scc[i] << endl;
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            int x = dp[i][j];
            mul(x, scc[j]);

            int z = res[j];
            add(z, res[i - j]);
            add(z, j * (j - 1) / 2);
            add(z, j * (i - j));

            mul(x, z);

            // int y = choose(i - 1, j - 1);
            // int x = pw[j * (i - j)];
            // add(x, pwr[j * (i - j)]);
            // mul(x, y);
            // mul(x, scc[j]);

            add(res[i], x);
        }

        int x = i * (i - 1) / 2;
        mul(x, scc[i]);
        add(res[i], x);

        mul(res[i], binPow(P + 1 - scc[i], P - 2));

        // cout << i << " " << res[i] << endl;
    }

    cout << res[n] << endl;

    return 0;
}