/*input
3
1 1 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 300007;
const int MAX_VAL = 1.51e7;

int A[MAXN], N;
int pfactor[MAX_VAL], cnt[MAX_VAL];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];

	int gcd = 0;
	for (int i = 0; i < N; ++i) gcd = __gcd(gcd, A[i]);
	for (int i = 0; i < N; ++i) A[i] /= gcd;

	int maxVal = *max_element(A, A + N);
	if (maxVal == 1) return cout << -1 << endl, 0;
	for (int i = 2; i <= maxVal; ++i) {
		if (!pfactor[i]) {
			for (int j = i; j <= maxVal; j += i) {
				pfactor[j] = i;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int x = A[i]; x > 1; ) {
			int factor = pfactor[x];
			while (pfactor[x] == factor) x /= factor;
			++cnt[factor];
		}
	}

	cout << N - *max_element(cnt, cnt + maxVal + 1) << endl;
}