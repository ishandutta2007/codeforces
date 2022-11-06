#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)

typedef long double T; // long doubles work a little slower (~20%), better use them
T PI = 2 * acos(0.0L);
T rnd(T x) {
	return x < 0.0 ? ceil(x - 0.5) : floor(x + 0.5);
}

struct Complex {
	T re, im;
	Complex() {
	}
	Complex(T r) :
			re(r), im(0) {
	}
	Complex(T r, T i) :
			re(r), im(i) {
	}
	Complex operator *(const Complex &c) const {
		return Complex(re * c.re - im * c.im, im * c.re + re * c.im);
	}
	Complex operator +(const Complex &c) const {
		return Complex(re + c.re, im + c.im);
	}
	Complex operator -(const Complex &c) const {
		return Complex(re - c.re, im - c.im);
	}
};
T real(Complex x) {
	return x.re;
}

void FFT(Complex *a, int N, int dir) {
	int lgN;
	for (lgN = 1; (1 << lgN) < N; lgN++)
		;
	//assert((1 << lgN) == N);
	FOR(i,N)
	{
		int j = 0;
		FOR(k,lgN)
		{
			j |= ((i >> k) & 1) << (lgN - 1 - k);
		}
		if (i < j)
			swap(a[i], a[j]);
	}
	FORI(s,lgN)
	{
		int h = 1 << (s - 1);
		Complex t, w, w_m(cos(dir * PI / h), sin(dir * PI / h));
		for (int k = 0; k < N; k += h + h) {
			w = 1;
			FOR(j,h)
			{
				t = w * a[k + j + h];
				a[k + j + h] = a[k + j] - t;
				a[k + j] = a[k + j] + t;
				w = w * w_m;
			}
		}
	}
}

// multiplication of polynomials in O(n log n)
vector<ll> convolve(vector<ll> &a1, vector<ll> &a2) {
	int N = 8;
	while (N < SZ(a1) + SZ(a2) + 2)
		N *= 2;
	Complex *t1 = new Complex[N], *t2 = new Complex[N];
	FOR(i,N)
		t1[i] = t2[i] = 0;
	FOR(i,SZ(a1))
		t1[i] = a1[i];
	FOR(i,SZ(a2))
		t2[i] = a2[i];
	FFT(t1, N, 1);
	FFT(t2, N, 1);
	FOR(i,N)
		t1[i] = t1[i] * t2[i];
	delete[] t2;
	FFT(t1, N, -1);
	vector<ll> res(SZ(a1) + SZ(a2) - 1);
	FOR(i,SZ(res))
		res[i] = (ll) rnd(real(t1[i]) / N);
	delete[] t1;
	return res;
}

// =========================================================================================

int n;
int a[(int) 2e5];
ll ans[(int) 2e5 + 1] = { 0 };

void f(const int l, const int r) {
	assert(l <= r);
	if (l == r) {
		++ans[a[l]];
		return;
	}
	int mid = (l + r) / 2;
	f(l, mid);
	f(mid + 1, r);

	const int m = max(mid - l + 1, r - mid) + 1;
	vector<ll> left(m, 0), right(m, 0);

	int sum = 0;
	for (int i = mid; i >= l; --i) {
		sum += a[i];
		left[sum]++;
	}

	sum = 0;
	for (int i = mid + 1; i <= r; ++i) {
		sum += a[i];
		right[sum]++;
	}

	vector<ll> res = convolve(left, right);
	for (int i = 0; i < (int) res.size(); ++i)
		ans[i] += res[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = a[i] < x;
	}

	f(0, n - 1);
	for (int i = 0; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}