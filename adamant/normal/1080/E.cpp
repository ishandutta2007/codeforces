#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define link afkla

const int maxn = 255, sigma = 26;
int H[sigma][maxn];

int get(int c, int n) {
	return H[c][n] ? H[c][n] : H[c][n] = rng();
}

gp_hash_table<int, int> to[maxn];
int len[maxn], link[maxn], s[maxn], par[maxn];
int last, n, sz;


void init() {
	for(int i = 0; i < sz; i++) {
		to[i].clear();
	} 
	len[1] = -1;
	link[0] = 1;
	s[0] = -1;
	last = 0;
	sz = 2;
	n = 1;
}

int get_link(int v) {
	while(s[n - 1] != s[n - len[v] - 2]) {
		v = link[v];
	}
	return v;
}

void add_letter(int c) {
	s[n++] = c;
	last = get_link(last);
	if(!to[last][c]) {
		len[sz] = len[last] + 2;
		link[sz] = to[get_link(link[last])][c];
		to[last][c] = sz++;
	}
	last = to[last][c];
	par[last] = par[link[last]] + 1;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for(int l = 0; l < m; l++) {
		vector<vector<int>> prof(n, vector<int>(26));
		vector<int> cnt(n), hsh(n);
		for(int r = l; r < m; r++) {
			int prev = -1;
			init();
			for(int i = 0; i < n; i++) {
				cnt[i] -= prof[i][s[i][r] - 'a'] % 2;
				hsh[i] ^= get(s[i][r] - 'a', prof[i][s[i][r] - 'a']);
				prof[i][s[i][r] - 'a']++;
				hsh[i] ^= get(s[i][r] - 'a', prof[i][s[i][r] - 'a']);
				cnt[i] += prof[i][s[i][r] - 'a'] % 2;
				if(cnt[i] > 1) {
					prev = i;
				}
				add_letter(hsh[i]);
				while(len[last] > i - prev) {
					last = link[last];
				}
				ans += par[last];
			}
		}
	}
	cout << ans << endl;
	return 0;
}