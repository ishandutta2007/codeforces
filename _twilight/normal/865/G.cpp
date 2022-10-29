#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Input {
	protected:
		const static int limit = 65536;
		FILE* file; 

		int ss, st;
		char buf[limit];
	public:
		
		Input():file(NULL)	{	};
		Input(FILE* file):file(file) {	}

		void open(FILE *file) {
			this->file = file;
		}

		void open(const char* filename) {
			file = fopen(filename, "r");
		}

		char pick() {
			if (ss == st)
				st = fread(buf, 1, limit, file), ss = 0;//, cerr << "str: " << buf << "ed " << st << endl;
			return buf[ss++];
		}
} Input;

#define digit(_x) ((_x) >= '0' && (_x) <= '9')

Input& operator >> (Input& in, unsigned& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, unsigned long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, int& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input in (stdin);

#define ll long long

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}

const int Mod = 1e9 + 7;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~(const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
		}
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
		} 
};

Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

typedef Z<> Zi;
typedef vector<Zi> Poly; 

Poly operator + (Poly A, const Poly& B) {
	if (A.size() < B.size())
		A.resize(B.size());
	for (int i = 0; i < (signed) B.size(); i++)
		A[i] += B[i];
	return A;
}

Poly operator * (const Poly& A, const Poly& B) {
	int n = A.size(), m = B.size();
	Poly rt (n + m - 1, Zi(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rt[i + j] += A[i] * B[j];
		}
	}
	return rt;
}

Poly operator % (Poly A, const Poly& B) {
	int n = A.size(), m = B.size();
	if (n < m) {
		return A;
	}
	assert(m > 0);
	Zi iv = ~B.back();
	for (int i = n - 1; i >= m - 1; i--) {
		Zi x = A[i] * iv;
		for (int j = 1; j <= m; j++) {
			A[i - j + 1] -= B[m - j] * x;
		}
	}
	A.resize(m - 1);
	return A;
}

Poly mod_pow(Poly A, ll p, Poly Q) {
	Poly pa = A, rt = Poly {1};
	for ( ; p; p >>= 1, pa = pa * pa % Q) {
		if (p & 1) {
			rt = rt * pa % Q;
		}
	}
	return rt;
}

int F, B;
ll N;
int p[15], c[105];

int main() {
	in >> F >> B >> N;
	for (int i = 1; i <= F; i++)
		in >> p[i];
	Poly Q (251);
	Q[250] = 1;
	for (int i = 1; i <= B; i++) {
		in >> c[i];
		Q[250 - c[i]] -= 1;
	}
	Poly F0 (250);
	F0[0] = 1;
	for (int i = 1; i < 250; i++) {
		for (int j = 1; j <= B; j++) {
			if (i >= c[j]) {
				F0[i] += F0[i - c[j]];
			} 
		}
	}
	Poly P {0};
	for (int i = 1; i <= F; i++) {
		P = P + mod_pow(Poly {0, 1}, p[i], Q);
	}
	P = mod_pow(P, N, Q);
	Zi ans = 0;
	P.resize(250);
	for (int i = 0; i < 250; i++) {
		ans += F0[i] * P[i];
	}
	printf("%d\n", ans.v);
	return 0;
}