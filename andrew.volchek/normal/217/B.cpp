#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}


const ll mod = 1000000007;

ll add(ll x, ll y) {
    return (x + y) % mod;
}

ll sub(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

const int maxn = 1e6 + 5;

int tc[maxn], bc[maxn];


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 1; i < maxn; i++) {
        tc[i] = tc[i - 1];
        if (i & 1) {
            tc[i]++;
        }
    }

    for (int i = 1; i < maxn; i++) {
        bc[i] = bc[i - 1];
        if (i % 2 == 0) {
            bc[i]++;
        }
    }

    int n, r;
    cin >> n >> r;

    const int inf = 1e9;

    pair<int, int> bst(inf, -1);
    vector<int> ansC;

    for (int i = r; i > 0; i--) {
        int a = r, b = i;
        int op = 0;
        vector<int> c;

        while (a && b) {
            if (a > b) {
                swap(a, b);
            }

            int k = b / a;
            if (a == 1 && b > 1) {
                k--;
            }
            op += k;
            c.pb(k);
            b -= a * k;
        }

        if (op != n || a + b != 1) {
            continue;
        }

        reverse(c.begin(), c.end());

        int l = 0;
        int m = 0;

        int p = 0;

        for (int x : c) {
            m += x - 1;
        }

        if (bst.fst > m) {
            ansC = c;
            bst = mp(m, i);
        }
    }

    if (bst.fst == inf) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << bst.fst << endl;

    int x = 0, y = 1;

    int p = 0;
    for (int z : ansC) {
        for (int i = 0; i < z; i++) {
            if (!p) {
                x += y;
            } else {
                y += x;
            }
            printf("%c", p ? 'B' : 'T');
        }
        p ^= 1;
    }



    return 0;
}