#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int x = nxt() - 1, y = nxt() - 1;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	vector<int> color(n, -1);
	vector<int> cnts;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (color[i] == -1) {
			vector<int> st = {i};
			cnts.push_back(0);
			color[i] = cur;
			while (!st.empty()) {
				int v = st.back();
				st.pop_back();
				++cnts.back();
				for (int x : a[v]) {
					if (color[x] == -1) {
						st.push_back(x);
						color[x] = cur;
					}
				}
			}
			++cur;
		}
	}

	long long actual = 0;
	for (int x : cnts) {
		actual += 1ll * x * (x - 1) / 2;
	}

	if (actual == m) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}