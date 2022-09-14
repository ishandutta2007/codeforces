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

const int MAXN = 800;
int c[MAXN][MAXN];
int sc[10][MAXN][MAXN];
int poww[12][MAXN];

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

int  binPow(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int x = binPow(a, b / 2);
    mul(x, x);

    if (b & 1) {
        mul(x, a);
    }
    return x;
}

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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }

    int res = 0;

    for (int d = 0; d <= 10; ++d) {
        poww[d][0] = 1;
        for (int i = 1; i <= n; ++i) {
            poww[d][i] = poww[d][i - 1];
            mul(poww[d][i], d);
        }
    }

    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        
        
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j];
            add(c[i][j], c[i - 1][j - 1]);
        }

        for (int j = 0; j <= i; ++j) {
            for (int d = 1; d <= 9; ++d) {

                sc[d][i][j] = c[i][j];
                mul(sc[d][i][j], poww[10 - d][j]);
                mul(sc[d][i][j], poww[d][i - j]);
            }
        }
    }

    for (int d = 1; d <= 9; ++d) {

        vector<int> cnt(n + 1);

        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int x = max(0, min(a[i], d));
            int y = a[i] - x;

            for (int j = 0; j <= n - 1 - i; ++j) {
                int tmp = sc[d][n - 1 - i][j];
                mul(tmp, x);
                add(cnt[cur + j], tmp);

                tmp = sc[d][n - 1 - i][j];
                mul(tmp, y);
                add(cnt[cur + j + 1], tmp);
            }
            cur += (a[i] >= d);
        }
        add(cnt[cur], 1);

        vector<int> suff(n + 1);
        suff[n] = cnt[n];
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = suff[i + 1];
            add(suff[i], cnt[i]);
        }
        
        int pw = 1;
        for (int i = 1; i <= n; ++i) {
            int tmp = pw;
            mul(tmp, suff[i]);
            add(res, tmp);

            mul(pw, 10);
        } 
    }

    cout << res << endl;

}