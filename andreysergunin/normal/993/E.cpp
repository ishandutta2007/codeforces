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
typedef complex<double> Complex;

const double PI = acos(-1);

vector<Complex> fft(const vector<Complex> &arr) {
    int k = 0;
    for ( ; 1 << k < sz(arr); ++k);
    int n = 1 << k;
    vector<int> rev(n);
    rev[0] = 0;
    int height = -1;
    for (int i = 1; i < n; ++i) {
        if ((i & (i - 1)) == 0)
            ++height;
        rev[i] = rev[i ^ (1 << height)] | (1 << (k - height - 1));
    }

    vector<Complex> w(n);
    for (int i = 0; i < n; ++i) {
        double alpha = 2 * PI * i / n;
        w[i] = Complex(cos(alpha), sin(alpha));
    }

    vector<Complex> cur(n);
    for (int i = 0; i < n; ++i)
        cur[i] = arr[rev[i]];

    for (int len = 1; len < n; len <<= 1) {
        vector<Complex> nCur(n);
        int step = n / (2 * len);
        for (int pos = 0; pos < n; pos += len) {
            for (int i = 0; i < len; ++i, ++pos) {
                Complex val = w[i * step] * cur[pos + len];
                nCur[pos] = cur[pos] + val;
                nCur[pos + len] = cur[pos] - val;
            }
        }
        swap(cur, nCur);
    }
    return cur;
}

vector<Complex> fftRev(vector<Complex> arr) {
    vector<Complex> res = fft(arr);
    for (int i = 0; i < sz(res); ++i) 
        res[i] /= sz(res);
    reverse(res.begin() + 1, res.end());
    return res;
}

class Polynom {
public:
    Polynom() {};
    Polynom(int n) {
        p.resize(n);
    };

    Polynom(vector<ll> &a) {
        p = a;
    }

    ll& operator [] (int k) {
        return p[k];
    }

    ll operator [] (int k) const {
        return p[k];
    }

    size_t size() const {
        return p.size();
    }

    Polynom operator +=(const Polynom &q) {
        if (sz(p) < sz(q)) {
            p.resize(sz(q));
        }
        for (int i = 0; i < sz(p); ++i) {
            if (i < sz(q)) {
                p[i] += q[i];
            }
        }
        return *this;
    }

    Polynom operator +(const Polynom &q) const {
        Polynom tmp(*this);
        return tmp += q;
    }

    Polynom operator *(const Polynom &q) {
        vector<Complex> a(sz(p)), b(sz(q));
        for (int i = 0; i < sz(a); ++i)
            a[i] = p[i];
        for (int i = 0; i < sz(b); ++i)
            b[i] = q[i];
        int k = 1;
        for (; k < max(sz(a), sz(b)); k *= 2);
        k *= 2;
        a.resize(k);
        b.resize(k);
        a = fft(a);
        b = fft(b);
        vector<Complex> res(k);
        for (int i = 0; i < k; ++i)
            res[i] = a[i] * b[i];
        res = fftRev(res);
        Polynom ans(sz(p) + sz(q) - 1);
        for (int i = 0; i < sz(ans); ++i)
            ans[i] = round(res[i].real());
        return ans;
    }
    
    Polynom operator *=(const Polynom &q) {
        *this = (*this) * q;
        return *this;
    }


private:
    vector<ll> p;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("input.txt", "w", stdout);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i] < x;
    }

    vector<ll> b;

    int cur = 0;

    for (int i = 0; i <= n; ++i) {
        ++cur;
        if (i == n || a[i] == 1) {
            b.push_back(cur);
            cur = 0;
        }
    }

    b.resize(n + 1);

    // for (int i = 0; i <= n; ++i) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    Polynom p(b);

    reverse(all(b));

    Polynom q(b);

    Polynom r = p * q;

    vector<ll> res(n + 1);
    for (int i = 0; i <= n; ++i) {
        res[i] = r[n + i];
    }

    res[0] = 0;
    for (int i = 0; i <= n; ++i) {
        res[0] += b[i] * (b[i] - 1) / 2;
    }

    for (int i = 0; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;




    return 0;
}