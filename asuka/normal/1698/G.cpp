#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using ull = unsigned ll;
int n;
string s;
unordered_map<ull, int> M;

struct mat {
	bool a[34][34];
	mat() { memset(a, 0, sizeof a); }
	bool* operator [](int i) { return a[i]; }

	mat operator * (mat o) {
		mat r;
		rep(i, 0, n - 2) rep(j, 0, n - 2) rep(k, 0, n - 2)
			r[i][k] ^= a[i][j] & o[j][k];
		return r;
	}

	vector<ull> get() {
		vector<ull> res;

		rep(j, 0, n - 2) {
			ull o = 0;
			rep(i, 0, n - 2) o |= (ull) a[i][j] << i;
			res.pb(o);
		}

		return res;
	}
} Bas, Inv;

mat qpow(mat a, int b) {
	mat r;
	rep(i, 0, n - 2) r[i][i] = 1;
	for (; b; b >>= 1, a = a * a)
		if (b & 1) r = r * a;
	return r;
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int zero = 0;
	cin >> s;
	while (!s.empty() && s.back() == '0')
		s.pop_back();
	if (s.empty()) return puts("-1"), 0;
	while (s[0] == '0') s.erase(s.begin()), zero++;
	if (s.size() == 1) return printf("%d %d\n", zero + 1, zero + 2), 0;
	n = SZ(s);
	rep(i, 0, n - 3) Bas[i + 1][i] = Inv[i][i + 1] = 1;
	rep(i, 1, n - 1) Bas[n - 1 - i][n - 2] = Inv[(n - 2 - i + n - 1) % (n - 1)][0] = s[i] - '0';
	int c = 1 << (n / 2);
	Bas = qpow(Bas, c);
	auto P = Bas.get();
	auto Q = Inv.get();
	ull x = 1ull << (n - 2), y = 1ull;

	rep(i, 0, c - 1) {
		if (M.count(y) == 0)
			M[y] = i;

		ull ny = 0;
		rep(j, 0, n - 2) 
			ny ^= (ull) __builtin_parityll(y & Q[j]) << j;
		y = ny;
	}

	rep(i, 0, c - 1) {
		if (M.count(x) > 0) {
			ll o = (ll) i * c + M[x];
			printf("%d %lld\n", zero + 1, zero + o + 2);
			return 0;
		}

		ull nx = 0;
		rep(j, 0, n - 2)
			nx ^= (ull) __builtin_parityll(x & P[j]) << j;
		x = nx;
	}

	puts("-1");
	return 0;
}