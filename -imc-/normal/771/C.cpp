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

const int N = 222222;
vector<int> a[N];
int size[N];
const int K = 7;
int cnt[N][K];
long long num[N][K];

int k;

void dfs(int v, int p = -1) {
	size[v] = 1;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		size[v] += size[x];

		for (int j = 0; j < k; ++j) {
			cnt[v][(j + 1) % k] += cnt[x][j];
		}

		for (int i = 0; i < k; ++i) {
			num[v][(i + i + 2) % k] -= 1ll * cnt[x][i] * (cnt[x][i] - 1) / 2;
			for (int j = i + 1; j < k; ++j) {
				num[v][(i + j + 2) % k] -= 1ll * cnt[x][i] * cnt[x][j];
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		num[v][(i + i) % k] += 1ll * cnt[v][i] * (cnt[v][i] - 1) / 2;
		for (int j = i + 1; j < k; ++j) {
			num[v][(i + j) % k] += 1ll * cnt[v][i] * cnt[v][j];
		}
		num[v][i] += cnt[v][i];
	}

	cnt[v][0] += 1;
}

int main(){

	int n = nxt();
	k = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(0);

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += 1ll * size[i] * (n - size[i]);
		for (int j = 1; j < k; ++j) {
			sum += 1ll * num[i][j] * (k - j);
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	cerr << i + 1 << ":";
	// 	for (int j = 0; j < k; ++j) {
	// 		cerr << " " << num[i][j];
	// 	}
	// 	cerr << "\n";
	// }

	assert(sum % k == 0);
	cout << sum / k << "\n";

	return 0;
}