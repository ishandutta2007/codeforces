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

const int MAXN = 111;
const int P = 1e9 + 7;

int dp[10][MAXN];
int fact[MAXN], rfact[MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
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
    int res = fact[n];
    mul(res, rfact[k]);
    mul(res, rfact[n - k]);
    return res;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin >> n;

    vector<int> d(10);
    for (int i = 0; i < 10; ++i) {
        cin >> d[i];
    }

    for (int i = d[9]; i <= n; ++i) {
        dp[9][i] = 1;
    }

    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }
    for (int i = 0; i <= n; ++i) {
        rfact[i] = binPow(fact[i], P - 2);
    }

    for (int j = 8; j >= 0; --j) {
        for (int i = 0; i <= n; ++i) {
            for (int k = d[j]; k <= i; ++k) {
                int tmp = dp[j + 1][i - k];
                mul(tmp, choose(i - (j == 0), k));
                add(dp[j][i], tmp);
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        add(res, dp[0][i]);
    }

    cout << res << endl;
}