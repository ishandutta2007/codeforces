#pragma GCC optimize("Ofast", "unroll-loops")

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

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int P = 998244353;

void add(int &a, int b, int mod = P) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int &a, int b, int mod = P) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(int &a, int b, int mod = P) {
    ll c = (ll)a * b;
    c %= mod;
    a = c;
}

int binPow(int a, int b, int mod = P) {
    int pw = a;
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, pw, mod);
        }
        mul(pw, pw, mod);
    }
    return res;
}

int reverse(int a, int mod = P) {
    return binPow(a, mod - 2, mod);
}

namespace fft {

const int MAXK = 20;
const int MAXN = 1 << MAXK;

vector<int> rev[MAXK + 1];
int used[MAXK + 1];
vector<int> w[MAXK + 1];
int g = 31;

void fft_init(int k) {
    if (used[k]) {
        return;
    }
    used[k] = 1;
    int n = 1 << k;
    rev[k].resize(n);
    w[k].resize(n);
    rev[k][0] = 0;
    int height = -1;
    for (int i = 1; i < n; ++i) {
        if ((i & (i - 1)) == 0) {
            ++height;
        }
        rev[k][i] = rev[k][i ^ (1 << height)] | (1 << (k - height - 1));
    }
    w[k][0] = 1;
    w[k][1] = binPow(g, (P - 1) / n);
    for (int i = 2; i < n; ++i) {
        w[k][i] = w[k][i - 1];
        mul(w[k][i], w[k][1]);
    }
}

void fft(vector<int> &arr) {
    int k = 0;
    int n = sz(arr);
    for (; (1 << k) < n; ++k);
    fft_init(k);
    for (int i = 0; i < n; ++i) {
        if (rev[k][i] < i) {
            swap(arr[i], arr[rev[k][i]]);
        }
    }
    for (int len = 1; len < n; len <<= 1) {
        int step = n / (2 * len);
        for (int pos = 0; pos < n; pos += len) {
            for (int i = 0; i < len; ++i, ++pos) {
                int val = w[k][i * step];
                mul(val, arr[pos + len]);
                arr[pos + len] = arr[pos];
                sub(arr[pos + len], val);
                add(arr[pos], val);
            }
        }
    }
}

void fftRev(vector<int> &arr) {
    int n = sz(arr);
    fft(arr);
    int r = reverse(n);
    for (int i = 0; i < n; ++i) { 
        mul(arr[i], r);
    }
    reverse(arr.begin() + 1, arr.end());
}

}


class Polynomial : public vector<int> {
public:
    using vector::vector;

    int operator()(int x) {
        int res = 0;
        for (int i = sz(*this) - 1; i >= 0; --i) {
            mul(res, x);
            add(res, (*this)[i]);
        }
        return res;
    }

    Polynomial operator+=(const Polynomial &other) {
        int n = max(sz(*this), sz(other));
        this->resize(n);
        for (int i = 0; i < sz(other); ++i) {
            add((*this)[i], other[i]);
        }
        return *this;
    }

    Polynomial operator-=(const Polynomial &other) {
        int n = max(sz(*this), sz(other));
        this->resize(n);
        for (int i = 0; i < sz(other); ++i) {
            sub((*this)[i], other[i]);
        }
        return *this;
    }

    Polynomial operator*=(const Polynomial &other) {
        int n = 1;
        for (; n < sz(*this) + sz(other) - 1; n <<= 1);
        vector<int> p(n), q(n);
        for (int i = 0; i < sz(*this); ++i) {
            p[i] = (*this)[i];
        }
        for (int i = 0; i < sz(other); ++i) {
            q[i] = other[i];
        }
        fft::fft(p);
        fft::fft(q);
        for (int i = 0; i < n; ++i) {
            mul(p[i], q[i]);
        }
        fft::fftRev(p);
        (*this).resize(sz(*this) + sz(other) - 1);
        for (int i = 0; i < sz(*this); ++i) {
            (*this)[i] = p[i];
        }
        return *this;
    }

    Polynomial operator*=(int c) {
        for (int i = 0; i < sz(*this); ++i) {
            mul((*this)[i], c);
        }
        return *this;
    }

    void norm() {
        while (sz(*this) > 1 && (*this).back() == 0) {
            (*this).pop_back();
        }
    }

    bool operator==(const Polynomial &other) const {
        for (int i = 0; i < max(sz(*this), sz(other)); ++i) {
            int x = (i < sz(*this) ? (*this)[i] : 0);
            int y = (i < sz(other) ? other[i] : 0);
            if (x != y) {
                return false;
            }
        }
        return true;
    }

    int deg() const {
        return sz(*this) - 1;
    }
};

int deg(const Polynomial &a) {
    return a.deg();
}


Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    Polynomial c = a;
    c += b;
    return c;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial c = a;
    c -= b;
    return c;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    Polynomial c = a;
    c *= b;
    return c;
}

Polynomial operator*(const Polynomial &a, int c) {
    Polynomial b = a;
    b *= c;
    return b;
}

Polynomial operator*(int c, const Polynomial &a) {
    Polynomial b = a;
    b *= c;
    return b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif  

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = (a[i] == 0 ? 0 : P - a[i]);
    }

    int m;
    cin >> m;
    for (int qq = 0; qq < m; ++qq) {
        vector<int> c = a;
        int t, q;
        cin >> t >> q;

        if (t == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            a[pos] = val == 0 ? val : P - val;
        } else {
            int l, r, val; 
            cin >> l >> r >> val;
            --l;
            for (int i = l; i < r; ++i) {
                sub(a[i], val);
            }
        }

        for (int i = 0; i < n; ++i) {
            add(a[i], q);
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        vector<Polynomial> poly(n);
        for (int i = 0; i < n; ++i) {
            poly[i] = {a[i], 1};
        }
        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += 2 * step) {
                poly[i] *= poly[i + step];
            }
        }   
        int res = poly[0][n - k]; 
        cout << res << endl;

        a = c;
    }

    



#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}