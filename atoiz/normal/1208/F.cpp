// spoiled

#include <iostream>

using namespace std;

const int LOG = 21, MAXN = 1000070;
int N, A[MAXN], F[1 << LOG][2];

void upd(int i, int x)
{
	if (x == F[i][0] || x == F[i][1]) return;
	if (x > F[i][1]) swap(x, F[i][1]);
	if (F[i][1] > F[i][0]) swap(F[i][1], F[i][0]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
		upd(A[i], i);
	}

	for (int i = LOG - 1; i >= 0; --i) {
		for (int x = 0; x < (1 << LOG); ++x) {
			if (!((x >> i) & 1)) {
				upd(x, F[x ^ (1 << i)][0]);
				upd(x, F[x ^ (1 << i)][1]);
			}
		}
	}

	int ans = 0;
	for (int lg = LOG - 1; lg >= 0; --lg) {
		bool bad = 1;
		ans ^= (1 << lg);
		for (int i = 1; i <= N && bad; ++i) {
			if (F[ans ^ (ans & A[i])][1] > i) bad = 0;
		}
		if (bad) ans ^= (1 << lg);
	}
	cout << ans << endl;
}