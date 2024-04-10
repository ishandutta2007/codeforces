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
#include <limits>
#include <complex>

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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------


const int m = 1;
const int maxn = 1e6 + 5;
const ll base[] = {rand() % 255 + 7, 73};
const ll mod[] = {1000000007, 1000000009};
ll pw[m][maxn];

struct H {
    ll a[m];

    H() {
        fill(a, a + m, 0);
    }

    H(ll x) {
        fill(a, a + m, x);
    }

    H operator + (const H &rhs) const {
        H res;
        for (int i = 0; i < m; i++) {
            res.a[i] = (a[i] + rhs.a[i]) % mod[i];
        }
        return res;
    }

    H operator - (const H &rhs) const {
        H res;
        for (int i = 0; i < m; i++) {
            res.a[i] = (a[i] - rhs.a[i] + mod[i]) % mod[i];
        }
        return res;
    }

    H operator << (const int x) const {
        H res;
        for (int i = 0; i < m; i++) {
            res.a[i] = (a[i] * pw[i][x]) % mod[i];
        }
        return res;
    }

    bool operator == (const H &rhs) const {
        for (int i = 0; i < m; i++) {
            if (a[i] != rhs.a[i]) {
                return false;
            }
        }
        return true;
    }
};

char a[maxn], b[maxn];
H ha[maxn], hb[maxn];
H haI[maxn], hbI[maxn];

int enc(char c) {
    if (c == 'S') {
        return 1;
    } else if (c == 'N') {
        return 2;
    } else if (c == 'W') {
        return 3;
    } else if (c == 'E') {
        return 4;
    }
}

int encI(char c) {
    if (c == 'S') {
        return 2;
    } else if (c == 'N') {
        return 1;
    } else if (c == 'W') {
        return 4;
    } else if (c == 'E') {
        return 3;
    }
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif



    for (int i = 0; i < m; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < maxn; j++) {
            pw[i][j] = pw[i][j - 1] * base[i] % mod[i];
        }
    }

    int n;
    scanf("%d\n", &n);
    n--;

    scanf("%s\n", a);
    scanf("%s\n", b);


    for (int i = 0; i < n; i++) {
        ha[i] = H(enc(a[i])) << i;
        if (i) {
            ha[i] = ha[i] + ha[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        hb[i] = H(enc(b[i])) << i;
        if (i) {
            hb[i] = hb[i] + hb[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        haI[i] = H(encI(a[i])) << (n - 1 - i);
        if (i + 1 < n) {
            haI[i] = haI[i + 1] + haI[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        hbI[i] = H(encI(b[i])) << (n - 1 - i);
        if (i + 1 < n) {
            hbI[i] = hbI[i + 1] + hbI[i];
        }
    }

    auto getA = [&](int l, int r) {
        H res = ha[r];
        if (l) {
            res = res - ha[l - 1];
        }
        return res << (n - 1 - r);
    };

    auto getB = [&](int l, int r) {
        H res = hb[r];
        if (l) {
            res = res - hb[l - 1];
        }
        return res << (n - 1 - r);
    };

    auto getAI = [&](int l, int r) {
        H res = haI[l];
        if (r + 1 < n) {
            res = res - (haI[r + 1]);
        }
        return res << (l);
    };

    auto getBI = [&](int l, int r) {
        H res = hbI[l];
        if (r + 1 < n) {
            res = res - (hbI[r + 1]);
        }
        return res << (l);
    };


    int p1 = 0, p2 = 0;

    while (p1 < n || p2 < n) {


        if (p1 < n && p2 > 0 && enc(a[p1]) == encI(b[p2 - 1])) {
            int lo = 0, hi = min(n - p1, p2) + 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) >> 1;

                if (getA(p1, p1 + mid - 1) == getBI(p2 - mid, p2 - 1)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            p1 += lo;
            p2 -= lo;
        }


        if (p1 < n) {
            if (p2 < n) {
                if (a[p1] == b[p2]) {
                    p2++;
                }
            }
            p1++;
            continue;
        }

        if (p2 < n && p1 > 0 && enc(b[p2]) == encI(a[p1 - 1])) {
            int lo = 0, hi = min(n - p2, p1) + 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) >> 1;


                if (getAI(p1 - mid, p1 - 1) == getB(p2, p2 + mid - 1)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }

            p2 += lo;
            p1 -= lo;
        }

        if (p2 < n) {
            if (p1 < n) {
                if (a[p1] == b[p2]) {
                    p1++;
                }
            }
            p2++;
            continue;
        }

        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;


    return 0;
}