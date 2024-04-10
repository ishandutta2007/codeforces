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

const int MAXN = 1111;
const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mult(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

int f(int k) {
    int ans = 0;
    for (; k > 0; k /= 2) {
        ans += (k & 1);
    }
    return ans;
}

int c[MAXN][MAXN];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = sz(s);

    int k;
    cin >> k;

    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }

    if (k == 1) {
        cout << n - 1 << endl;
        return 0;
    }

    if (k >= 10) {
        cout << 0 << endl;;
        return 0;
    }


    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1];
            add(c[i][j], c[i - 1][j]);
        }
    }

    int ans = 0;

    for (int d = 1; d <= n; ++d) {
        int l = 1;
        for (int c = d; c > 1; c = f(c), ++l);
        if (k != l) {
            continue;
        }
        int cur = 0;
        int bits = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                continue;
            }
            if (bits <= d) {
                add(ans, c[n - i - 1][d - bits]);
            }
            ++bits;
        }
        if (bits == d) {
            add(ans, 1);
        }
    }

    cout << ans << endl;

    return 0;
}