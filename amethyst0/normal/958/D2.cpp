#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int p = 998244353, q = (int)1e9 + 123;

pii operator +(pii a, pii b) {
    a.first += b.first;
    a.second += b.second;

    if (a.first >= p) {
        a.first -= p;
    }

    if (a.second >= q) {
        a.second -= q;
    }

    return a;
}

pii operator -(pii a, pii b) {
    a.first -= b.first;
    a.second -= b.second;

    if (a.first < 0) {
        a.first += p;
    }

    if (a.second < 0) {
        a.second += q;
    }

    return a;
}

pii operator *(pii a, pii b) {
    a.first = (ll)a.first * b.first % p;
    a.second = (ll)a.second * b.second % q;

    return a;
}

const int maxn = (int)30010;

pii t[maxn];
pii s[maxn];
int g[maxn];

map <pii, int> hs;
int d;

pii v[10][10];

void sswap(int x, int y) {
    for (int i = 0; i < d; i++) {
        swap(v[x][i], v[y][i]);
    }
}

int my_pow(int x, int y, int mod) {
    if (y == 0) {
        return 1;
    }

    if (y & 1) {
        return (ll)x * my_pow(x, y - 1, mod) % mod;
    }

    ll z = my_pow(x, y >> 1, mod);

    return z * z % mod;
}

pii rev(pii a) {
    if (a.first == 0 || a.second == 0) {
        throw 1;
    }

    a.first = my_pow(a.first, p - 2, p);
    a.second = my_pow(a.second, q - 2, q);

    return a;
}

pii get_hsh(int k) {
    int pos = 0;

    for (int i = 0; i < d; i++) {
        bool fl = false;

        for (int j = pos; j < k; j++) {
            if (v[j][i] != mp(0, 0)) {
                sswap(j, pos);
                fl = true;
                break;
            }
        }

        if (!fl) {
            continue;
        }

        pii g = rev(v[pos][i]);

        for (int j = 0; j < d; j++) {
            v[pos][j] = v[pos][j] * g;
        }

        for (int j = pos + 1; j < k; j++) {
            pii cf = v[j][i];

            for (int w = 0; w < d; w++) {
                v[j][w] = v[j][w] - v[pos][w] * cf;
            }
        }

        pos++;
    }

    for (int i = k - 1; i >= 0; i--) {
        int e = -1;

        for (int j = 0; j < d; j++) {
            if (v[i][j] != mp(0, 0)) {
                e = j;
                break;
            }
        }

        if (e == -1) {
            continue;
        }

        if (v[i][e] != mp(1, 1)) {
            throw 1;
        }

        for (int j = i - 1; j >= 0; j--) {
            pii cf = v[j][e];

            for (int w = 0; w < d; w++) {
                v[j][w] = v[j][w] - v[i][w] * cf;
            }
        }
    }

    pii hsh = mp(0, 0);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < d; j++) {
            //cout << v[i][j].first << ' ';
            hsh = hsh + t[i] * s[j] * v[i][j];
        }

        //cout << endl;
    }

    return hsh;
}

int main() {
    t[0] = mp(1, 1);
    s[0] = mp(1, 1);

    for (int i = 0; i < maxn; i++) {
        t[i] = {rand() % p, rand() % q};
        s[i] = {rand() % p, rand() % q};
    }

    int n;

    scanf("%d %d", &n, &d);

    int num = 1;

    for (int i = 0; i < n; i++) {
        int k;

        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            for (int f = 0; f < d; f++) {
                int x;
                scanf("%d", &x);
                if (x >= 0) {
                    v[j][f] = mp(x, x);
                } else {
                    v[j][f] = mp(x + p, x + q);
                }
            }
        }

        pii f = get_hsh(k);

        if (!hs.count(f)) {
            hs[f] = num++;
        }

        g[i] = hs[f];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", g[i]);
    }

    return 0;
}