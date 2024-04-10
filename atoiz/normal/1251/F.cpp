/*input
5 5
1 2 3 4 5
1 2 3 4 5
4
4 8 10 14


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int MOD = 998244353, ROOT = 3;
int add(int a, int b) { return a -= ((a += b) >= MOD ? MOD : 0); }
int sub(int a, int b) { return a += ((a -= b) < 0 ? MOD : 0); }
int mul(int a, int b) { return (int) ((int64_t) a * b % MOD); }
int inv(int a, int m = MOD) { return (a == 1 ? 1 : int(m - (int64_t) m * inv(m % a, a) / a)); }
int bpow(int a, int p)
{
	int ans = 1;
	for (; p > 0; p >>= 1) {
		if (p & 1) ans = mul(ans, a);
		a = mul(a, a);
	}
	return ans;
}

const int MAXN = 300007, MAXP = 20;

void fft(int *A, int P, bool doInv)
{
	for (int i = 1, j = 0; i < (1 << P); ++i) {
		int k;
		for (k = P - 1; (j >> k) & 1; --k) j ^= (1 << k);
		j ^= (1 << k);
		if (i < j) swap(A[i], A[j]);
	}

	for (int k = 1; k <= P; ++k) {
		int mult = bpow(ROOT, (MOD - 1) >> k);
		if (doInv) mult = inv(mult);
		for (int i = 0; i < (1 << P); i += (1 << k)) {
			int w = 1;
			for (int j = 0; j < (1 << (k - 1)); ++j) {
				int tmp = mul(w, A[i + j + (1 << (k - 1))]);
				A[i + j + (1 << (k - 1))] = sub(A[i + j], tmp);
				A[i + j] = add(A[i + j], tmp);
				w = mul(w, mult);
			}
		}
	}

	if (doInv) {
		int invN = inv(1 << P);
		for (int i = 0; i < (1 << P); ++i) {
			A[i] = mul(A[i], invN);
		}
	}
}

int cnt[MAXN], fact[MAXN], invfact[MAXN], pow2[MAXN];
int p1[1 << MAXP], p2[1 << MAXP];

int choose(int n, int k)
{
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
	invfact[MAXN - 1] = inv(fact[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; --i) invfact[i] = mul(invfact[i + 1], i + 1);
	pow2[0] = 1;
	for (int i = 1; i < MAXN; ++i) pow2[i] = add(pow2[i - 1], pow2[i - 1]);

	int N, K;
	cin >> N >> K;
	vector<int> A(N), B(K);
	for (int &x : A) cin >> x;
	for (int &x : B) cin >> x;
	int M;
	cin >> M;
	vector<int> Q(M);
	for (int &x : Q) cin >> x;

	vector<int> ans(M, 0);
	for (int b : B) {
		memset(cnt, 0, sizeof(cnt[0]) * b);
		for (int x : A) if (x < b) ++cnt[x];
		int num1 = 0, num2 = 0;
		for (int x = 1; x < b; ++x) {
			if (cnt[x] >= 2) ++num2;
			else if (cnt[x] >= 1) ++num1;
		}

		// num1 + 2 * num2 < (1 << 19)
		assert(num1 + (num2 << 1) < (1 << MAXP));
		memset(p1, 0, sizeof p1);
		memset(p2, 0, sizeof p2);

		for (int i = 0; i <= num1; ++i) {
			p1[i] = mul(choose(num1, i), pow2[i]);
		}
		for (int i = 0; i <= num2 * 2; ++i) {
			p2[i] = choose(num2 * 2, i);
		}

		int P = __lg(num1 + num2 * 2) + 1;

		fft(p1, P, false);
		fft(p2, P, false);
		for (int i = 0; i < (1 << P); ++i) {
			p1[i] = mul(p1[i], p2[i]);
		}
		fft(p1, P, true);

		for (int i = 0; i < M; ++i) {
			int id = (Q[i] >> 1) - 1 - b;
			if (0 <= id && id < (1 << P)) ans[i] = add(ans[i], p1[id]);
		}
	}

	for (int i = 0; i < M; ++i) cout << ans[i] << '\n';
}