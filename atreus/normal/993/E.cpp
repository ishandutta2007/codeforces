#include<bits/stdc++.h>
using namespace std;
typedef complex<long double> cd;
typedef long long ll;

const int maxn = 2e5 + 5;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<ll> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int par[maxn];
ll ans[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> par[i];
		par[i] = par[i - 1] + (par[i] < x);
	}
	vector<int> a(n + 1, 0), b(n + 1, 0);
	for (int i = 0; i <= n; i++){
		a[par[i]] ++;
		b[n - par[i]] ++;
	}
	vector<ll> c = multiply(a, b);
	for (int i = 1; i <= n; i++)
		ans[i] = c[i + n];
	int t = 0;
	for (int i = 1; i <= n; i++){
		if (par[i] != par[i - 1])
			t = 0;
		else
			t ++;
		ans[0] += t;
	}
	for (int i = 0; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
}