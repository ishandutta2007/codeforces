#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

typedef complex<double> cmplx;
typedef vector<complex<double> > VC;
const double PI = acos(-1);
struct FFT {
    static void fft(VC &u, int sign) {
        int n = u.size();
        double theta = 2. * PI * sign / n;
        for (int m = n; m >= 2; m >>= 1, theta *= 2.) {
            cmplx w(1, 0), wDelta = polar(1., theta);
            for (int i = 0, mh = m >> 1; i < mh; i++) {
                for (int j = i; j < n; j += m) {
                    int k = j + mh;
                    cmplx temp = u[j] - u[k];
                    u[j] += u[k];
                    u[k] = w * temp;
                }
                w *= wDelta;
            }
        }
        for (int i = 1, j = 0; i < n; i++) {
            for (int k = n >> 1; k > (j ^= k); k >>= 1);
            if (j < i) {
                swap(u[i], u[j]);
            }
        }
    }

    static vector<int> mul(const vector<int> &a, const vector<int> &b) {
        int newSz = a.size() + b.size() - 1;
        int fftSz = 1;
        while (fftSz < newSz) {
            fftSz <<= 1;
        }
        VC aa(fftSz, 0.), bb(fftSz, 0.);
        for (int i = 0; i < a.size(); i++) {
            aa[i] = a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            bb[i] = b[i];
        }
        fft(aa, 1);
        fft(bb, 1);
        for (int i = 0; i < fftSz; i++) {
            aa[i] *= bb[i];
        }
        fft(aa, -1);
        vector<int> res(newSz);
        for (int i = 0; i < newSz; i++) {
            res[i] = (int)(aa[i].real() / fftSz + 0.5);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int &e : a) cin >> e;
    vector<int> foo1(x + 1, 0);
    vector<int> foo2(3 * x + 1, 0);
    for (int e : a) foo1[e] = 1, foo2[3 * x - e] = 1;
    vector<int> check = FFT::mul(foo1, foo2);

    const int MX = 1000001;
    vector<vector<int>> div(MX);
    
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) div[j].pb(i);
    }

    vector<int> ans(MX + 1, -2);

    int q;
    cin >> q;
    while (q--) {
        int u;
        cin >> u;
        if (ans[u] != -2) {
            cout << ans[u] << ' ';
            continue;
        }

        sort(div[u].rbegin(), div[u].rend());

        for (int e : div[u]) {
            if (e % 2 == 1) continue;
            int len = e - 2 * y;
            if (len <= 0) continue;
            len /= 2;
            if (3 * x + len > check.size()) continue;
            if (check[3 * x + len]) {
                ans[u] = e;
                break;
            }
        }

        if (ans[u] == -2) ans[u] = -1;

        cout << ans[u] << ' ';


    }

    return 0;
}