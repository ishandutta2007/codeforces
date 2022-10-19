/*input
5
3
aab
bcc
4
cabc
abcb
3
abc
tsr
4
aabd
cccd
5
abcbd
bcdda
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int C = 20;
int inMask[C], dp[1 << C];

struct DSU
{
	int a[C];
	void init() { memset(a, -1, sizeof a); }
	int get(int x) { return (a[x] < 0 ? x : a[x] = get(a[x])); }
	bool same(int x, int y) { return get(x) == get(y); }
	void join(int x, int y)
	{
		x = get(x), y = get(y);
		if (x == y) return;
		if (a[x] > a[y]) swap(x, y);
		a[x] += a[y], a[y] = x;
	}
} dsu;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int N;
		string A, B;
		cin >> N >> A >> B;
		memset(inMask, 0, sizeof inMask);
		memset(dp, 0, sizeof dp);
		dsu.init();
		for (int i = 0; i < N; ++i) {
			inMask[B[i] - 'a'] |= 1 << (A[i] - 'a');
			dsu.join(A[i] - 'a', B[i] - 'a');
		}

		int ans = 0;
		for (int p = 0; p < C; ++p) if (dsu.get(p) == p) {
			int allMask = 0;
			for (int i = 0; i < C; ++i) if (dsu.same(i, p)) allMask |= (1 << i);
			for (int mask = 1; mask <= allMask; ++mask) if ((mask & allMask) == mask) {
				dp[mask] = N;
				for (int i = 0; i < C; ++i) if ((mask >> i) & 1) {
					dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + ((inMask[i] & mask) != inMask[i]));
				}
			}
			ans += dp[allMask] + __builtin_popcount(allMask) - 1;
		}

		cout << ans << '\n';
	}
}