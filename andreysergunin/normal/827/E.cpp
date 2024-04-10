#include <stdio.h>
#include <iostream>
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
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef unsigned int uint;


const double PI = acos(-1);

typedef complex<double> Complex;

const int MAXN = 2e6;

int rev[MAXN];
Complex w[MAXN];
Complex cur[MAXN];
Complex nCur[MAXN];

vector<Complex> fft(const vector<Complex> &arr) {
    int k = 0;
    for ( ; 1 << k < sz(arr); ++k);
    int n = 1 << k;
    rev[0] = 0;
    int height = -1;
    for (int i = 1; i < n; ++i) {
        if ((i & (i - 1)) == 0)
            ++height;
        rev[i] = rev[i ^ (1 << height)] | (1 << (k - height - 1));
    }

    for (int i = 0; i < n; ++i) {
        double alpha = 2 * PI * i / n;
        w[i] = Complex(cos(alpha), sin(alpha));
    }

    for (int i = 0; i < n; ++i)
        cur[i] = arr[rev[i]];

    for (int len = 1; len < n; len <<= 1) {
        int step = n / (2 * len);
        for (int pos = 0; pos < n; pos += len) {
            for (int i = 0; i < len; ++i, ++pos) {
                Complex val = w[i * step] * cur[pos + len];
                nCur[pos] = cur[pos] + val;
                nCur[pos + len] = cur[pos] - val;
            }
        }
        memcpy(cur, nCur, sizeof(Complex) * n);
    }
    vector<Complex> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = cur[i];
    return res;
}

vector<Complex> fftRev(const vector<Complex> &arr) {
    vector<Complex> res = fft(arr);
    for (int i = 0; i < sz(res); ++i) 
        res[i] /= sz(res);
    reverse(res.begin() + 1, res.end());
    return res;
}

vector<int> mult(const vector<int> &a, const vector<int> &b) {
    vector<Complex> p(sz(a)), q(sz(b));
    for (int i = 0; i < sz(a); ++i)
        p[i] = a[i];
    for (int i = 0; i < sz(b); ++i)
        q[i] = b[i];
    int k = 1;
    for (; k < max(sz(p), sz(q)); k *= 2);
    k *= 2;
    p.resize(k);
    q.resize(k);
    p = fft(p);
    q = fft(q);
    vector<Complex> res(k);
    for (int i = 0; i < k; ++i)
        res[i] = p[i] * q[i];
    res = fftRev(res);
    vector<int> ans(sz(a) + sz(b) - 1);
    for (int i = 0; i < sz(ans); ++i)
        ans[i] = round(res[i].real());
    return ans;
}

vector<int> dot(vector<int> a, vector<int> b) {
    int n = sz(a);
    reverse(all(b));
    vector<int> p = mult(a, b);
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = p[n - 1 + i] + p[n - 1 - i];
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v(n), k(n);
        for (int i = 0; i < n; ++i) {
            v[i] = (s[i] == 'V');
            k[i] = (s[i] == 'K');
        }

        vector<int> p = dot(v, k);

        vector<int> ans;

        for (int i = 1; i < n; ++i) {
            int cnt = 0;
            for (int j = 1; i * j < n; ++j)
                cnt += p[i * j];
            if (cnt == 0)
                ans.push_back(i);
        }

        ans.push_back(n);

        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }
    

}