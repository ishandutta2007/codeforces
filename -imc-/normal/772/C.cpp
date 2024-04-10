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
int phi[N];
int erat[N];

long long pw(long long a, long long b, long long mod) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

int inv(int a, int mod) {
	return pw(a, phi[mod] - 1, mod);
}

int main(){
	erat[1] = phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			phi[i] = i - 1;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		} else {
			if (erat[i / erat[i]] == erat[i]) {
				phi[i] = phi[i / erat[i]] * erat[i];
			} else {
				phi[i] = phi[i / erat[i]] * (erat[i] - 1);
			}
		}
	}

	int n = nxt(), m = nxt();
	vector<int> banned(n);
	for (int i = 0; i < n; ++i) {
		banned[i] = nxt();
	}

	vector<int> divs;
	for (int i = 1; i <= m; ++i) {
		if (m % i == 0) {
			divs.push_back(i);
		}
	}

	vector<char> permitted(m, 1);
	for (int x : banned) {
		permitted[x] = 0;
	}

	int count = divs.size();
	vector<int> cnt(count);
	vector<vector<int>> guys(count);
	for (int i = 0; i < m; ++i) {
		if (!permitted[i]) {
			continue;
		}
		cnt[lower_bound(all(divs), __gcd(i, m)) - divs.begin()] += 1;
		guys[lower_bound(all(divs), __gcd(i, m)) - divs.begin()].push_back(i);
	}

	vector<int> next_vertex(count, -1);
	vector<int> len = cnt;
	for (int i = count - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (divs[i] % divs[j]) {
				continue;
			}
			if (len[j] < cnt[j] + len[i]) {
				next_vertex[j] = i;
				len[j] = cnt[j] + len[i];
			}
		}
	}

	int start = max_element(all(len)) - len.begin();
	vector<int> prefix;
	for (int v = start; v != -1; v = next_vertex[v]) {
		for (int x : guys[v]) {
			prefix.push_back(x);
		}
	}

	int lst = 1;
	cout.sync_with_stdio(0);
	cout << len[start] << "\n";
	for (int x : prefix) {
		// lst * y = x (mod m)
		int gcd2 = __gcd(x, m), gcd1 = __gcd(lst, m);
		int g = gcd2 / gcd1;
		int other = 1ll * (x / gcd2) * inv(lst / gcd1, m / gcd1) % m;
		cout << 1ll * g * other % m << " ";
		lst = x;
	}
	cout << "\n";

	return 0;
}