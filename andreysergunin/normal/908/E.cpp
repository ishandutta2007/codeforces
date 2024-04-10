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

const int P = 1e9 + 7;
const int MAXM = 1111;
const int MAXN = 55;

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


bitset<MAXM> b[55];
int c[MAXM][MAXM];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);        

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            b[i][j] = (s[j] == '1');
        }
    }

    vector<int> used(m);
    vector<int> cnt;

    for (int j = 0; j < m; ++j) {
        if (used[j]) {
            continue;
        }
        int k = -1;

        for (int i = 0; i < n; ++i) {
            if (b[i][j] == 1) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            continue;;
        }

        for (int i = 0; i < n; ++i) {
            if (i == k) {
                continue;
            }

            if (b[i][j] == 1) {
                b[i] ^= b[k];
            }
        }

        int cur = 0;
        for (int l = 0; l < m; ++l) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                s += b[i][l];
            }
            if (s == 1 && b[k][l]) {
                ++cur;
                used[l] = 1;
            }
        }

        cnt.push_back(cur);
    }

    int s = m;
    for (int i = 0; i < sz(cnt); ++i) {
        s -= cnt[i];
    }

    cnt.push_back(s);

    for (int i = 0; i <= m; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j];
            add(c[i][j], c[i - 1][j - 1]);
        }
    }

    vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int k = 1; k <= i; ++k) {
            int cur = f[i - k];
            mul(cur, c[i - 1][k - 1]);
            add(f[i], cur);
        }
    }

    int res = 1;
    for (int i = 0; i < sz(cnt); ++i) {
        mul(res, f[cnt[i]]);
    }

    cout << res << endl;


}