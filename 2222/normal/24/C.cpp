#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef pair <int, int> pii;

typedef vector <int> bigint;

void print(bigint a) {
	if (a.size() == 0) {
		cout << 0;
		return ;
	}
	for (int i = 1; i < a.size(); ++i) 
		if (a[i - 1] < 0) a[i - 1] += 1000000000, a[i] --;
	for (; sz(a) && a.back() == 0; a.pop_back());
	if (a.back() < 0) {
		for (int i = 1; i < a.size(); ++i)
			if (a[i - 1] > 0) a[i - 1] -= 1000000000, a[i] ++;
		for (; sz(a) && a.back() == 0; a.pop_back());
	}
    cout << a.back();
    for (int i = sz(a) - 1; i > 0; printf("%09d", abs(a[--i])));
}

bigint operator * (const bigint &a, const bigint &b) {
        bigint c(sz(a) + sz(b));
        for (int i = 0; i < sz(a); ++i) {
                ll q = 0;
                for (int j = 0; j < sz(b); ++j) {
                        q += c[i + j] + a[i] * ll(b[j]);
                        c[i + j] = q % 1000000000;
                        q /= 1000000000;
                }
                for (int j = i + sz(b); q && j < sz(c); ++j, q /= 1000000000) {
                        q += c[j];
                        c[j] = q % 1000000000;
                }
        }
        for (; sz(c) > 1 && c.back() == 0; c.pop_back());
        return c;
}

void operator += (bigint &a, const bigint &b) {
	for (; sz(a) < sz(b); a.pb(0));
	for (int i = 0; i < b.size(); ++i)
		a[i] += b[i];
	a.pb(0);
	FOR (i, 1, sz(a)) {
		a[i] += a[i - 1] / 1000000000;
		a[i - 1] %= 1000000000;
	}
	for (; sz(a) > 0 && a.back() == 0; a.pop_back());
}

struct matrix {
	bigint a[3][3];
	void print() {
		REP (i, 3) {
			REP (j, 3) {
				::print(a[i][j]);
				cout << ' ';
			}
			cout << endl;
		} cout << endl;
	} 
	void operator = (const matrix &c) {
		REP (i, 3) REP (j, 3) a[i][j] = c.a[i][j];
	}
};

bigint big(int n) {
	bigint r;
	for (; n; n /= 1000000000) r.pb(n % 1000000000);
	return r;
}

matrix operator * (const matrix &a, const matrix &b) {
	matrix c;
	REP (i, 3) REP (j, 3) {
		bigint t;
		REP (k, 3) t += a.a[i][k] * b.a[k][j];
		c.a[i][j] = t;
	}
	return c;
}

int n;
ll m;
pii A[111111];

matrix qpow(matrix A, int n) {
	matrix B;
	REP (i, 3) B.a[i][i] = big(1);
	for (; n; n /= 2, A = A * A)
		if (n & 1) B = A * B;
	return B;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int x0, y0;
	cin >> n >> m >> x0 >> y0;
	matrix T, R;
	REP (i, 3) T.a[i][i] = R.a[i][i] = big(1);
	REP (i, n) { 
		scanf("%d%d", &A[i].X, &A[i].Y);
		matrix t;
		t.a[0][0] = big(1);
		t.a[1][0] = big(2 * A[i].X);
		t.a[1][1] = big(-1);
		t.a[2][0] = big(2 * A[i].Y);
		t.a[2][2] = big(-1);
		T = t * T;
	}
	T = qpow(T, m / n);
	m %= n;
	REP (i, m) {
		matrix t;
		t.a[0][0] = big(1);
		t.a[1][0] = big(2 * A[i].X);
		t.a[1][1] = big(-1);
		t.a[2][0] = big(2 * A[i].Y);
		t.a[2][2] = big(-1);
		T = t * T;
	}
	bigint V[3] = {big(1), big(x0), big(y0)}, Q[3];
	REP (i, 3) {
		Q[i] = big(0);
		REP (j, 3) Q[i] += T.a[i][j] * V[j];
	}
	print(Q[1]);
	cout << ' ';
	print(Q[2]);
	cout << endl;
	return 0;
}