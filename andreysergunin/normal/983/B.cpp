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

const int MAXN = 5010;

int f[MAXN][MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> st(n + 1);
    st[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (st[i - 1] * 2 == i) {
            st[i] = st[i - 1] * 2;
        } else {
            st[i] = st[i - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        f[i][i] = a[i];
    }

    for (int len = 1; len < n; ++len) {
        if (st[len] == len) {
            for (int i = 0; i + len < n; ++i) {
                f[i][i + len] = a[i] ^ a[i + len];
            }
            continue;
        }

        for (int i = 0; i + len < n; ++i) {
            int x = len - st[len];
            f[i][i + len] = f[i][i + x] ^ f[i + st[len]][i + st[len] + x];
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = i; j < n; ++j) {
    //         cout << i << " " << j << " " << f[i][j] << endl;
    //     }
    // }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = max(f[i][j - 1], f[i][j]);
        }
    }

    for (int j = n - 1; j >= 0; --j) {
        for (int i = j - 1; i >= 0; --i) {
            f[i][j] = max(f[i + 1][j], f[i][j]);
        }
    }


    

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << f[l][r] << endl;
    }

    return 0;
}