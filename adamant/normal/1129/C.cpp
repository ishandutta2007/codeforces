#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define int int64_t
const double pi = acos(-1);

using namespace std;

const int maxn = 1e5 + 42;

int len[maxn], link[maxn];
map<char, int> to[maxn];
int sz = 1, last;

void add_letter(char c) {
	int p = last;
	last = sz++;
	len[last] = len[p] + 1;
	for(; to[p][c] == 0; p = link[p]) {
		to[p][c] = last;
	}
	if(to[p][c] == last) {
		return;
	}
	int q = to[p][c];
	if(len[q] == len[p] + 1) {
		link[last] = q;
		return;
	}
	int cl = sz++;
	len[cl] = len[p] + 1;
	link[cl] = link[q];
	to[cl] = to[q];
	link[last] = link[q] = cl;
	for(; to[p][c] == q; p = link[p]) {
		to[p][c] = cl;
	}
}

const int mod = 1e9 + 7;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    string s;
    int ans = 0;
    map<string, int> ok;
    ok["0011"] = ok["0101"] = ok["1110"] = ok["1111"] = 1;
    for(int i = 0; i < m; i++) {
		char c;
		cin >> c;
		s += c;
		add_letter(c);
		int nw = len[last] - len[link[last]];
		int dp[i + 2];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int j = 1; j <= i + 1; j++) {
			dp[j] = dp[j - 1];
			if(j >= 2) dp[j] += dp[j - 2];
			if(j >= 3) dp[j] += dp[j - 3];
			if(j >= 4 && !ok[s.substr(i - j + 1, 4)]) dp[j] += dp[j - 4];
			dp[j] %= mod;
			if(j + nw > i + 1) {
				ans += dp[j];
			}
			ans %= mod;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}