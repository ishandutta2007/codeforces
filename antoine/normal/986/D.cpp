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
#define SZ(x) int((x).size())
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
} // multiplication of polynomials in O(n log n)
vector<ll> convolve(vector<ll> a1, vector<ll> a2) {
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

const int DIGITS = 3, BASE = 1000; // remark: number_of_blocks*BASE^2 has to fit into longlong
#define SIZ int(size())
struct bignum: public vi{
bignum() {
	pb(0);
}
bignum(ll num) {
	if (num < BASE)
	pb(num);
	else
	while (num > 0) {
		pb(num % BASE);
		num /= BASE;
	}
}

bignum(const string &s) {
	for (int i = 0; i < SZ(s); i += DIGITS) {
		int kon = SZ(s) - i, pocz = max(0, kon - DIGITS);
		pb(atoi(s.substr(pocz, kon - pocz).c_str()));
	}
	cut0();
}
string str() const {
	stringstream ss;
	ss << back() << setfill('0');
	for (int i = SIZ - 2; i >= 0; --i)
	ss << setw(DIGITS) << at(i);
	return ss.str();
}
bignum& operator+=(const bignum& y) {
	int maxsz = max(SIZ, SZ(y));
	bool carry = 0;
	FOR(i, maxsz)
	{
		int sum = carry + (i < SIZ ? at(i) : 0) + (i < SZ(y) ? y[i] : 0);
		if (sum >= BASE) {
			carry = 1;
			sum -= BASE;
		} else {
			carry = 0;
		}
		if (i < SIZ)
		at (i) = sum;
		else
		pb(sum);
	}
	if (carry)
	pb(1);
	return *this;
}
void cut0() {
	while (size() > 1 && back() == 0)
	pop_back();
}
bignum operator*(const bignum& y) const {
	/*vector<ll> w(size() + SZ(y) + 2, 0);
	 FOR(i, SIZ)
	 FOR(j, SZ(y))
	 w[i + j] += (ll) at(i) * y[j];
	 */
	vector<ll> w = convolve(vector<ll>(begin(), end()), vector<ll>(y.begin(), y.end()));
	w.resize(size() + SZ(y) + 2, 0);

	ll carry = 0;
	FOR(i, SZ(w))
	{
		w[i] += carry;
		carry = w[i] / BASE;
		w[i] %= BASE;
	}
	bignum res;
	res.resize(SZ(w));
	FOR(i, SZ(w))
	res[i] = w[i];
	res.cut0();
	return res;
}
bignum& operator -=(const bignum &y) { // only works for x>=y!
	FOR(i, SIZ)
	{
		if (i < SZ(y))
		at(i) -= y[i];
		if (at(i) < 0) {
			at(i) += BASE;
			at(i + 1) -= 1;
		}
	}
	cut0();
	return *this;
}
int compare(const bignum &y) const {
	if (SIZ < SZ(y))
	return -1;
	if (SIZ > SZ(y))
	return 1;
	for (int i = size() - 1; i >= 0; --i)
	if (at(i) != y[i]) {
		if (at(i) < y[i])
		return -1;
		else
		return 1;
	}
	return 0;
}
int operator %(int m) const {
	ll w = back() % m;
	for (int i = size() - 2; i >= 0; --i)
	w = (w * BASE + at(i)) % m;
	return w;
}
bignum& operator /=(int y) { // only works for y < BASE!
	ll dz = 0;
	for (int i = size() - 1; i >= 0; --i) {
		ll x = dz * BASE + at(i);
		at(i) = x / y;
		dz = x % y;
	}
	cut0();
	return *this;
}
bool operator <(const bignum &y) const {
	return compare(y) < 0;
}
bool operator >(const bignum &y) const {
	return compare(y) > 0;
}
bool operator <=(const bignum &y) const {
	return compare(y) <= 0;
}
bool operator >=(const bignum &y) const {
	return compare(y) >= 0;
}
bool operator ==(const bignum &y) const {
	return compare(y) == 0;
}
bool operator !=(const bignum &y) const {
	return compare(y) != 0;
}
bignum operator +(const bignum& y) const {
	bignum res = *this;
	res += y;
	return res;
}
bignum operator -(const bignum &y) const {
	bignum res = *this;
	res -= y;
	return res;
} // only works for x>=y!
bignum& operator *=(const bignum &y) {
	return *this = *this * y;
}
bignum operator /(int y) const {
	bignum res = *this;
	res /= y;
	return res;
} // only works for y < BASE!
};

ostream& operator <<(ostream &s, const bignum &y) {
	return s << y.str();
}

bignum bnPow(bignum n, int k) {
	bignum res(1LL);
	for (; k; k >>= 1) {
		if (k & 1)
			res *= n;
		n *= n;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string __s;
	cin >> __s;
	// __s = string((int) 1.5e6, '9');

	const bignum n(__s);
	const int L = __s.size();

	const bignum BN_2(2);
	const bignum BN_3(3);
	const bignum BN_4(4);

	const int cnt3 = max(0, int(L * log(10) / log(3)) + 5);

	bignum num = bnPow(3, cnt3) * BN_4;

	cerr << "pow done\n";

	int ans = 1 << 30;

	for (int m2 = 0; m2 <= 2; ++m2) {
		bignum curr = num;
		assert(curr >= n);
		for (int m3 = 0; m3 <= cnt3; ++m3) {
			ans = min(ans, (2 - m2) * 2 + (cnt3 - m3) * 3);
			curr /= 3;
			if (curr < n)
				break;
		}
		num /= 2;
	}

	cout << max(1, ans) << '\n';
	return 0;
}