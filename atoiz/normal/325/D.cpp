#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cassert>

using namespace std;

const int MAXD = 3007, MAXN = 300007;
int A[MAXD][MAXD], par[MAXN], dsu[MAXN], R, C, N;

int get(int x) { return (dsu[x] < 0 ? (x << 1) : dsu[x] = get(dsu[x] >> 1) ^ (dsu[x] & 1)); }
void join(int x, int y, int w) 
{
	x = get(x), y = get(y);
	w ^= (x & 1) ^ (y & 1);
	x >>= 1, y >>= 1;

	if (x == y) {
		assert(w == 0);
		return;
	}

	if (dsu[x] > dsu[y]) swap(x, y);
	par[y] = w, dsu[x] += dsu[y], dsu[y] = (x << 1) ^ w;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C >> N;
	int ans = 0;
	if (C == 1) return cout << 0 << endl, 0; // why do you exist?

	for (int id = 1; id <= N; ++id) {
		int r, c;
		cin >> r >> c;
		// cout << endl;
		// cout << "cur " << r << ' ' << c << endl;

		vector<int> vec;
		for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
			if ((dx == 0 && dy == 0) || r + dx < 1 || r + dx > R) continue;
			int r0 = r + dx, c0 = c + dy, w = 0;
			if (c0 == 0) c0 = C, w = 1;
			else if (c0 == C + 1) c0 = 1, w = 1;
			if (!A[r0][c0]) continue;
			// cout << r << ' ' << c << " -> " << r0 << ' ' << c0 << ": " << w << endl;
			vec.push_back(get(A[r0][c0]) ^ w);
		}
		// cout << "S" << endl;

		sort(vec.begin(), vec.end());
		// for (int x : vec) cout << (x >> 1) << ' ' << (x & 1) << endl;
		bool bad = false;
		for (int i = 0; i < (int) vec.size() - 1; ++i) if ((vec[i] ^ vec[i + 1]) == 1) { bad = true; break; }
		if (bad) continue;
		// cout << "yes" << endl;
		++ans;
		A[r][c] = id, dsu[id] = -1;
		for (int x : vec) join(id, x >> 1, x & 1);
	}

	cout << ans << endl;

	// for (int r = 2; r < R; ++r) for (int c = 1; c <= C; ++c) if (!A[r][c]) {
	// 	int cur = !A[r - 1][c] + !A[r + 1][c] + !A[r][c % C + 1] + !A[r][(c + C - 2) % C + 1];
	// 	assert(cur == 2);
	// }

}