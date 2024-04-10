#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
const int LOG = 22;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAX = 1 << 21;

typedef long long ll;
typedef complex <double> comp;

struct bignum {
	vector <ll> d;
	void norm() {
		ll carry = 0;
		for (int i = 0; i < d.size() || carry; i++) {
			if (i >= d.size())
				d.push_back(0);
			d[i] += carry;
			carry = d[i] / 1000;
			d[i] %= 1000;
		}
		while (!d.back())
			d.pop_back();
	}
};

bool operator <(const bignum &A, const bignum &B) {
	if (A.d.size() != B.d.size())
		return A.d.size() < B.d.size();
	for (int i = (int)A.d.size() - 1; i >= 0; i--)
		if (A.d[i] != B.d[i])
			return A.d[i] < B.d[i];
	return false;
}

bignum num;
char s[MAXN];

int N;
comp omega[MAX];
comp a1[MAX], a2[MAX];
comp z1[MAX], z2[MAX];

void fft(comp *a, comp *z, int m = N) {
	if (m == 1) {
		z[0] = a[0];
	} else {
		int s = N/m;
		m /= 2;

		fft(a, z, m);
		fft(a+s, z+m, m);

		REP(i, m) {
			comp c = omega[s*i] * z[m+i];
			z[m+i] = z[i] - c;
			z[i] += c;
		}
	}
}

void mult(const vector <ll> &a, vector <ll> &c) {
	N = 2 * a.size();
	while (N & (N-1)) ++N;
	assert(N <= MAX);

	REP(i, N) a1[i] = 0;
	REP(i, a.size()) a1[i] = a[i];
	
	REP(i, N) omega[i] = polar(1.0, 2*M_PI/N*i);
	fft(a1, z1, N);
	
	REP(i, N) omega[i] = comp(1, 0) / omega[i];
	REP(i, N) a1[i] = z1[i] * z1[i] / comp(N, 0);
	fft(a1, z1, N);
	
	c.resize(2 * a.size());
	REP(i, c.size()) c[i] = round(z1[i].real());
}

bignum square(const bignum &A) {
	bignum C;
	mult(A.d, C.d);
	C.norm();
	return C;
}

void load() {
	scanf("%s", s);
}

double log3(double x) {
	return log(x) / log(3);
}

void naive(bignum &A, int x) {
	for (auto &it : A.d)
		it *= x;
	A.norm();	
}

int solve() {
	int len = strlen(s);
	if (len == 1 && s[0] == '1')
		return 1;
		
	for (int i = len - 1; i >= 0; i -= 3) {
		int digit = 0;
		for (int j = max(i - 2, 0); j <= i; j++)
			digit = 10 * digit + s[j] - '0';
		num.d.push_back(digit);
	}
		
	bignum pot = {{1}};
	int ex = max((int)ceil((len - 1) * log3(10) - log3(4)), 0);
	for (int i = LOG - 1; i >= 0; i--) {
		pot = square(pot);
		if (ex >> i & 1)
			naive(pot, 3);
	}
	
	int sol = 1e9;
	for (int i = 0; i < 4; i++) {
		bignum curr = pot;
		int cnt = 0;
		for (; curr < num; naive(curr, 2))
			cnt++;
		sol = min(sol, 2 * cnt + 3 * (ex + i)); 
		naive(pot, 3);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}