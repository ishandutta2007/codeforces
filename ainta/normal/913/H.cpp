#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int Inv[31], Mod = 998244353, Comb[31][31], Invbase;
int X[10100], base = 1000000, cnt;
struct Poly {
	int n;
	vector<int>P;
	Poly() {
		n = 0;
		P.clear();
	}
	Poly(int c) {
		n = 0;
		P.resize(1);
		P[0] = c;
	}
	Poly operator +(const Poly &p)const {
		int i;
		Poly ret;
		ret.n = max(n, p.n);
		ret.P.resize(ret.n + 1);
		for (i = 0; i <= ret.n; i++) {
			ret.P[i] = 0;
			if (i <= n)ret.P[i] += P[i];
			if (i <= p.n)ret.P[i] += p.P[i];
			if (ret.P[i] >= Mod)ret.P[i] -= Mod;
		}
		return ret;
	}
	Poly operator -(const Poly &p)const {
		int i;
		Poly ret;
		ret.n = max(n, p.n);
		ret.P.resize(ret.n + 1);
		for (i = 0; i <= ret.n; i++) {
			ret.P[i] = Mod;
			if (i <= n)ret.P[i] += P[i];
			if (i <= p.n)ret.P[i] -= p.P[i];
			if (ret.P[i] >= Mod)ret.P[i] -= Mod;
		}
		return ret;
	}
	Poly operator *(const int &p)const {
		int i;
		Poly ret;
		ret.n = n;
		ret.P.resize(ret.n + 1);
		for (i = 0; i <= ret.n; i++) {
			ret.P[i] = (long long)P[i] * p%Mod;
		}
		return ret;
	}
	int Gap(int x) {
		int i, s = 0, tt = 1;
		for (i = 0; i <= n; i++) {
			s = (s + (long long)P[i] * tt) % Mod;
			tt = (long long)tt*x%Mod;
		}
		return s;
	}
	Poly integral() const{
		Poly ret;
		ret.n = n + 1;
		ret.P.resize(n + 2);
		int i;
		for (i = 0; i <= n; i++) {
			ret.P[i + 1] = (long long)P[i] * Inv[i + 1] % Mod;
		}
		return ret;
	}
	Poly ToRight() const{
		Poly ret;
		ret.n = n;
		ret.P.resize(n + 1);
		int i, j;
		for (i = 0; i <= ret.n; i++) {
			int t = P[i];
			for (j = i; j >= 0; j--) {
				ret.P[j] = (ret.P[j] + (long long)t*Comb[i][j]) % Mod;
				t = (long long)t * (Mod-base) % Mod;
			}
		}
		return ret;
	}
};
struct ord {
	int x;
	Poly P;
	bool operator <(const ord &p)const {
		return x < p.x;
	}
};
vector<ord>R, TP;

int Pow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r = (long long)r*a%Mod;
		a = (long long)a*a%Mod; b >>= 1;
	}
	return r;
}
int w[31];
void Cut(int M) {
	int i;
	while (!R.empty()) {
		if (R.back().x >= M)R.pop_back();
		else break;
	}
	ord tp;
	tp.P = Poly(0);
	for (i = 0; i < R.size(); i++) {
		tp.P = tp.P - R[i].P;
	}
	tp.x = M;
	R.push_back(tp);
}

void Do(Poly tp, int b, int e) {
	int i;
	Poly T = tp.integral();
	Poly p1 = T - Poly(T.Gap(b));
	Poly p2 = Poly(T.Gap(e)) - Poly(T.Gap(b));
	Poly p3 = Poly(T.Gap(e)) - T.ToRight();
	Poly OO = Poly(0);
	p1 = p1*Invbase;
	p2 = p2*Invbase;
	p3 = p3*Invbase;
	TP.push_back({ b, p1 });
	TP.push_back({ e, p2 - p1 });
	TP.push_back({ b + base, p3 - p2 });
	TP.push_back({ e + base, OO - p3 });
}


int main() {
	int i, n, j;
	for (i = 1; i <= 30; i++)Inv[i] = Pow(i, Mod - 2);
	for (i = 0; i <= 30; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = Comb[i - 1][j - 1] + Comb[i - 1][j];
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		double a;
		scanf("%lf", &a);
		w[i] = (int)(a*1e6 + 0.5);
	}
	Invbase = Pow(base, Mod - 2);
	ord tp;
	tp.P = Poly(Invbase);
	tp.x = 0;
	R.push_back(tp);
	tp.P = Poly(Mod- Invbase);
	tp.x = base;
	R.push_back(tp);
	Cut(w[1]);

	for (i = 2; i <= n; i++) {
		TP.clear();
		Poly ss = Poly(0);
		for (j = 0; j < R.size() - 1; j++) {
			ss = ss + R[j].P;
			Do(ss, R[j].x, R[j+1].x);
		}
		sort(TP.begin(), TP.end());
		R.clear();
		for (j = 0; j < TP.size(); j++) {
			Poly t = Poly(0);
			int k;
			for (k = j; k < TP.size(); k++) {
				if (TP[k].x != TP[j].x)break;
				t = t + TP[k].P;
			}
			R.push_back({ TP[j].x, t });
			j = k-1;
		}
		Cut(w[i]);
	}
	int res = 0;
	Poly ss = Poly(0);
	for (i = 0; i < R.size() - 1; i++) {
		int b = R[i].x, e = R[i + 1].x;
		ss = ss + R[i].P;
		Poly T = ss.integral();
		res = (0ll + res + T.Gap(e) - T.Gap(b) + Mod)%Mod;
	}
	printf("%d\n", res);
	return 0;
}