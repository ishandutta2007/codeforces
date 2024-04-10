#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const signed int inf = (signed) (~0u >> 1);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

#define pii pair<int, int>

const int N = 1005;

typedef class Pair4 {
	public:
		int x1, y1, x2, y2;

		Pair4(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {	}
} Pair3;

int n;
int match[N];
bitset<N> vis;
bitset<N> vL, vR;
pii px[N], py[N];
vector<int> G[N];
vector<Pair4> vert, hori;

inline void init() {
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		px[i] = pii(x, y);
		py[i] = pii(x, y);
	}
	sort(px + 1, px + n + 1, [&] (const pii& x, const pii& y) {
		return (x.first != y.first) ? (x.first < y.first) : (x.second < y.second);
	});
	sort(py + 1, py + n + 1, [&] (const pii& x, const pii& y) {
		return (x.second != y.second) ? (x.second < y.second) : (x.first < y.first);
	});
	for (int i = 1; i < n; i++) {
		if (px[i].first == px[i + 1].first) {
			int x = px[i].first, y1 = px[i].second, y2 = px[i + 1].second;
			for (int j = 1; j < n; j++) {
				if (py[j].second == py[j + 1].second) {
					int x1 = py[j].first, x2 = py[j + 1].first, y = py[j].second;
					if (x > x1 && x < x2 && y > y1 && y < y2) {
						G[i].push_back(j);
					}		
				}
			}
		}
	}
}

boolean argument(int p) {
	for (auto e : G[p]) {
		if (vis.test(e)) {
			continue;
		}
		vis.set(e);
		if (match[e] == -1 || argument(match[e])) {
			match[e] = p;
			return true;
		}
	}
	return false;
}

void dfs(int p) {
	if (vL.test(p)) {
		return;
	}
	vL.set(p);
	for (auto e : G[p]) {
		if (match[e] != p) {
			vR.set(e);
			dfs(match[e]);
		}
	}
}

bitset<N> inmatch;
inline void solve() {
	pfill(match, match + n, -1);
	for (int i = 1; i < n; i++) {
		vis.reset();
		argument(i);
	}
	for (int i = 1; i < n; i++) {
		if (match[i] != -1) {
			inmatch.set(match[i]);
		}
	}
	for (int i = 1; i < n; i++) {
		if (!inmatch.test(i)) {
			dfs(i);
		}
	}
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (j < n && px[j].first == px[j + 1].first && vL.test(j)) {
			j++;
		}
		vert.push_back(Pair4(px[i].first, px[i].second, px[j].first, px[j].second));
	}
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (j < n && py[j].second == py[j + 1].second && !vR.test(j)) {
			j++;
		}
		hori.push_back(Pair4(py[i].first, py[i].second, py[j].first, py[j].second));
	}
	printf("%d\n", (signed) hori.size());
	for (auto &par4 : hori) {
		printf("%d %d %d %d\n", par4.x1, par4.y1, par4.x2, par4.y2);
	}
	printf("%d\n", (signed) vert.size());
	for (auto &par4 : vert) {
		printf("%d %d %d %d\n", par4.x1, par4.y1, par4.x2, par4.y2);
	}
}

int main() {
	init();
	solve();
	return 0;
}