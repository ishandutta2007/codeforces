#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;
typedef unsigned int uint;

int n, m;

bitset<512> a[2][61][512];

void tmul(bitset<512>* a, bitset<512>* b, bitset<512>* c) {
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            if (a[i][j]) {
                c[i] |= b[j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n, m);

    for (int i = 0; i < m; i++) {
        scid(x, y, z);
        --x; --y;
        a[z][0][x][y] = 1;
    }

    for (int i = 1; i < 61; i++) {
        tmul(a[0][i - 1], a[1][i - 1], a[0][i]);
        tmul(a[1][i - 1], a[0][i - 1], a[1][i]);
    }

    lint ans = 0;

    int* cr = new int[n];
    int* nx = new int[n];
    memset(cr, 0, sizeof(int) * n);
    cr[0] = 1;

    int f = 0;
    for (int i = 60; i >= 0; i--) {
        memset(nx, 0, sizeof(int) * n);
        int have = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (cr[k] & a[f][i][k][j]) {
                    nx[j] = 1;
                    have = 1;
                    break;
                }
            }
        }
        if (have) {
            memcpy(cr, nx, sizeof(int) * n);
            ans += 1LL << i;
            f ^= 1;
        }
    }

    if (ans > 1e18) {
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}