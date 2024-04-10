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
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 1e6 + 100;
const int MAXK = 20;
const int P = 1e9 + 7;

int sp[MAXK][MAXN];
int pos[MAXK][MAXN];
int p[MAXN];
int a[MAXN];

int k;

int res = 0;

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

int get(int lf, int rg) {
    int d = p[rg - lf];
    return (sp[d][lf] > sp[d][rg - (1 << d)] ? pos[d][lf] : pos[d][rg - (1 << d)]);
}

ll f(int lf, int rg) {
    if (lf > rg) {
        swap(lf, rg);
    }

    // cout << lf << " " << rg << endl;


    int l = lf / (k - 1);
    int ans = l;

    int tmp = k - 1;
    mul(tmp, l + 1);
    mul(tmp, l);
    mul(tmp, (P + 1) / 2);

    add(ans, tmp);

    int m = rg / (k - 1);

    tmp = m - l;
    mul(tmp, lf + 1);
    add(ans, tmp);

    int r = (lf + rg) / (k - 1);
    // cout << l << " " << r << endl;

    tmp = (rg + lf + 1);
    mul(tmp, r - m);
    add(ans, tmp);

    tmp = (k - 1);
    mul(tmp, r - m);
    mul(tmp, r + m + 1);
    mul(tmp, (P + 1) / 2);

    sub(ans, tmp);

    return ans;

}

void solve(int lf, int rg) {
    if (rg - lf <= 1) {
        return;
    }

    int pos = get(lf, rg);

    solve(lf, pos);
    solve(pos + 1, rg);

    // cout << lf << " " << pos << " " << rg << endl;

    int cur = f(pos - lf, rg - pos - 1);
    mul(cur, a[pos]);
    add(res, cur);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sp[0][i] = a[i];
        pos[0][i] = i;
    }

    p[1] = 0;
    for (int i = 2; i <= n; ++i) {
        p[i] = p[i / 2] + 1;
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            if (sp[i - 1][j] < sp[i - 1][j + (1 << (i - 1))]) {
                sp[i][j] = sp[i - 1][j + (1 << (i - 1))];
                pos[i][j] = pos[i - 1][j + (1 << (i - 1))];
            } else {
                sp[i][j] = sp[i - 1][j];
                pos[i][j] = pos[i - 1][j];
            }
        }
    }

    solve(0, n);

    cout << res << endl;
}