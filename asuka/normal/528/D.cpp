/*
a_i = \sum_{j=0}^{m-1} t{j} (s_{i + j} - t_{j})
= \sum s{i + j} t_j  - t_j^2
*/
#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015, M = 555555;
const double PI = acos(-1.0);
struct cp {
	double x, y;
	cp operator +(const cp &rhs) const {return (cp) {x + rhs.x, y + rhs.y};}
	cp operator -(const cp &rhs) const {return (cp) {x - rhs.x, y - rhs.y};}
	cp operator *(const cp &rhs) const {return (cp) {x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x};}
	cp operator *(const double &o) const {return (cp) {x * o, y * o};}
	cp operator /(const double &o) const {return (cp) {x / o, y / o};}
} A[M], B[M];
int lim, w, rev[M];
void init(int n, int m) {
	lim = 1; w = 0;
	while (lim <= n + m - 2) lim <<= 1, w++;
	rep(i, 0, lim - 1) rev[i] = 0;
	rep(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (w - 1));
	rep(i, 0, lim - 1) A[i] = B[i] = (cp) {0.0, 0.0};
}
void FFT(cp a[], int flag) {
	rep(i, 0, lim - 1) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		cp wn = (cp) {cos(PI / i), flag * sin(PI / i)};
		for (int j = 0; j < lim; j += (i << 1)) {
			cp w = (cp) {1.0, 0.0};
			for (int k = 0; k < i; ++k, w = w * wn) {
				cp x = a[j + k], y = w * a[j + k + i];
				a[j + k] = x + y;
				a[j + k + i] = x - y;
			}
		}
	}
	if (flag < 0) rep(i, 0, lim - 1) a[i] = a[i] / lim;
}
VI mul(VI a, VI b) { // a_i+j b_j -> c_i
	/*
	j -> m - j - 1
	i - j -> i + (m - j - 1) = i - j + m - 1
	*/
	init(SZ(a), SZ(b));
	rep(i, 0, SZ(a) - 1) A[i].x = 1.0 * a[i];
	rep(i, 0, SZ(b) - 1) B[SZ(b) - i - 1].x = 1.0 * b[i];
	FFT(A, 1); FFT(B, 1);
	rep(i, 0, lim - 1) A[i] = A[i] * B[i];
	FFT(A, -1);
	VI res(SZ(a) + SZ(b) - 1, 0);
	rep(i, 0, SZ(a) + SZ(b) - 2) res[i] = (int) (A[i].x + 0.5);
	return res;
}
int n, m, k, match[N];
char s[N], t[N];
VI getS(char ch) {
	VI res(n, 0);
	int lst = 0;
	rep(i, 0, n - 1) {
		if (s[i] == ch) lst = k + 1;
		if (lst -- > 0) res[i] = 1;
	}
	lst = 0;
	per(i, 0, n - 1) {
		if (s[i] == ch) lst = k + 1;
		if (lst -- > 0) res[i] = 1;
	}
	return res;
}
VI getT(char ch) {
	VI res(m, 0);
	rep(i, 0, m - 1) if (t[i] == ch) res[i] = 1;
	return res;
}
void solve(char ch) {
	VI S = getS(ch), T = getT(ch), O = mul(S, T);
	int o = 0;
	rep(i, 0, m - 1) o += T[i];
	rep(i, 0, n - m) match[i] += (O[i + m - 1] - o) == 0;	
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", s, t);
	for (auto ch : {'A', 'G', 'C', 'T'}) {
		solve(ch);
	}
	int ans = 0;
	rep(i, 0, n - 1) if (match[i] == 4) ans++;
	printf("%d\n", ans);
	return 0;
}