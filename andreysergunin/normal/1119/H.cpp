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
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int P = 998244353;
const int MAXM = 17;
const int MAXN = 100100;

int cnt[1 << 3][1 << MAXM];
int pw[1 << 3][MAXN];

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

vector<int> xorConvolution(vector<int> cur) {
    int n = sz(cur);
    vector<int> ncur(n);
    for (int len = 1; len < n; len <<= 1) {
        for (int pos = 0; pos < n; pos += len) {
            for (int i = 0; i < len; ++pos, ++i) {
                ncur[pos] = cur[pos];
                add(ncur[pos], cur[pos + len]);
                ncur[pos + len] = cur[pos];
                sub(ncur[pos + len], cur[pos + len]);
            }
        }
        cur.swap(ncur);
    }
    return cur;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> x(3);
    cin >> x[0] >> x[1] >> x[2];

    for (int i = 0; i < 3; ++i) {
        x[i] %= P;
    }

    vector<int> s(8);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i & (1 << j)) {
                add(s[i], x[j]);
            } else {
                sub(s[i], x[j]);
            }
        }
    }

    for (int i = 0; i < 8; ++i) {
        pw[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            pw[i][j] = pw[i][j - 1];
            mul(pw[i][j], s[i]);
        }
    }
    

    vector<vector<int>> arr(1 << 3, vector<int>(1 << k));

    for (int i = 0; i < n; ++i) {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        for (int mask = 0; mask < (1 << 3); ++mask) {
            int cur = 0; 
            for (int j = 0; j < 3; ++j) {
                if (mask & (1 << j)) {
                    cur ^= a[j];
                }
            }
            ++arr[mask][cur];
        }
    }

    for (int i = 0; i < (1 << 3); ++i) {   
        arr[i] = xorConvolution(arr[i]);
    }
    
    vector<int> res(1 << k, 1);

    for (int i = 0; i < (1 << k); ++i) {    
        vector<int> b;
        for (int j = 0; j < (1 << 3); ++j) {
            b.push_back(arr[j][i]);
        }
        b = xorConvolution(b);

        for (int j = 0; j < (1 << 3); ++j) {
            b[j] /= 8;
        }
        reverse(all(b));

        for (int j = 0; j < (1 << 3); ++j) {
            int cur = pw[j][b[j]];
            mul(res[i], cur);
        }
    }

    res = xorConvolution(res);

    int rev = 1;

    for (int i = 0; i < k; ++i) {
        mul(rev, (P + 1) / 2);
    }

    for (int i = 0; i < (1 << k); ++i) {
        mul(res[i], rev);
        cout << res[i] << " ";
    }

    cout << endl;
}