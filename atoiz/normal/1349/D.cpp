/*input
5
8 4 2 0 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MOD = 998244353;

int inv(int a, int p = MOD) { return (a == 1 ? 1 : int(p - (int64_t) p * inv(p % a, a) / a)); }
int add(int a, int b) { return a -= ((a += b) >= MOD ? MOD : 0); }
int sub(int a, int b) { return a += ((a -= b) < 0 ? MOD : 0); }
int mul(int a, int b) { return int(int64_t(a) * b % MOD); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int &x : A) cin >> x;
	int S = accumulate(A.begin(), A.end(), 0);

	int invS = inv(S), invN1 = inv(N - 1);

	vector<int> a(S + 1), b(S + 1), f(S + 2, 0);
	a[0] = b[0] = 0;

	// function<void(int, int, int)> calc = [&](int i, int a, int b) {
	// 	int x = mul(mul(i, invS), invN1);
	// 	int y = mul(mul(i, invS), mul(N - 2, invN1));
	// 	int z = mul(S - i, invS);

	// 	int p = add(mul(x, a[i - 1]), y);
	// 	int q = z;
	// 	int r = add(1, mul(x, b[i - 1]));

		
	// };

	// calc(1, 0, 0);

	for (int i = 1; i <= S; ++i) {
		int x = mul(mul(i, invS), invN1);
		int y = mul(mul(i, invS), mul(N - 2, invN1));
		int z = mul(S - i, invS);

		int p = add(mul(x, a[i - 1]), y);
		int q = z;
		int r = add(1, mul(x, b[i - 1]));

		p = sub(1, p);

		if (p == 0) {
			if (i != S) {
				++i;
				assert(q != 0);
				a[i] = 0, b[i] = mul(sub(0, r), inv(q));
			} else {
				assert(0);
			}
		} else {
			a[i] = mul(q, inv(p));
			b[i] = mul(r, inv(p));
		}
	}

	assert(a[S] == 0);
	f[S] = b[S];

	for (int i = S; i >= 1; --i) {
		int x = mul(mul(i, invS), invN1);
		// int y = mul(mul(i, invS), mul(N - 2, invN1));
		int z = mul(S - i, invS);

		f[i - 1] = mul(sub(mul(add(x, z), f[i]), add(mul(z, f[i + 1]), 1)), inv(x));
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = add(ans, f[S - A[i]]);
	}
	ans = sub(ans, mul(f[S], N - 1));
	ans = mul(ans, inv(N));
	cout << ans << endl;
	return 0;
}