/*input
5000000
2
1919810 998244353 114514 19260817
5000000 233333333 623532 7175

*/
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 5000003;
int N, _A[MAXN], A[MAXN], L, S[MAXN * 2], Z;
int64_t total[2];
bool T[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int M, pos = 1;
	cin >> N >> M;
	while (M--) {
		int p, k, b, w;
		cin >> p >> k >> b >> w;
		int64_t seed = b, base = w;
		for (; pos <= p; ++pos) {
			T[pos] = (bool) (seed & 1);
			seed = (seed * base + 233) % 1000000007;
			A[pos] = (int) ((seed % k) + 1);
			seed = (seed * base + 233) % 1000000007;
			total[T[pos]] += A[pos];
		}
	}

	memcpy(_A, A, sizeof(A[0]) * (N + 1));
	L = (total[T[1]] <= total[!T[1]]) ? T[1] : !T[1];
	if (T[1] != L) --A[1];

	Z = 0;
	for (int i = N; i >= 1; --i) {
		if (T[i] != L) {
			S[++Z] = i;
		}
	}
	for (int i = N; i >= 1; --i) {
		if (T[i] != L) {
			S[++Z] = i;
		} else {
			while (A[i]) {
				int c = min(A[i], A[S[Z]]);
				A[i] -= c, A[S[Z]] -= c;
				while (!A[S[Z]]) --Z;
			}
		}
	}

	int64_t output = 1;
	for (int i = 1; i <= N; ++i) {
		output *= (((_A[i] - A[i]) ^ ((int64_t) i * i)) + 1) % 1000000007;
		output %= 1000000007;
	}
	cout << output << endl;
}