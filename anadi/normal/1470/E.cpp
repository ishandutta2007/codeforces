#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 30'007;
const int Q = 300'007;

struct Query {
	LL id;
	int p, ans;
	
	Query() {}
	
	void read() {
		scanf("%d %lld", &p, &id);
		ans = 0;
	}
};

int n, c, q;
int in[N];
LL dp[N][5];

LL pref[5][N];
LL better[5][N];

void calc_dp() {
	for(int t = 0; t <= c; ++t)
		dp[0][t] = 1;

	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= c; ++j) {
			dp[i][j] = 0;
			for(int k = 0; k <= j and k < i; ++k)
				dp[i][j] += dp[i - k - 1][j - k];
		}
}

void prepare() {
	for(int t = 0; t <= c; ++t) {
		for(int i = 1; i <= n; ++i) {
			better[t][i] = 0;
			for(int j = 1; j <= t and i + j <= n; ++j)
				if(in[i + j] < in[i])
					better[t][i] += dp[n - i - j][t - j];

			pref[t][i] = pref[t][i - 1] + better[t][i];
		}
	}
}

int get(LL id, int p) {
	int ptr = 0, left = c;
	while(ptr < p) {
		int s = ptr, e = n;
		while(s < e) {
			int mid = (s + e + 1) / 2;
			LL sum = pref[left][mid] - pref[left][ptr];

			if(id <= sum || sum + dp[n - mid][left] < id)
				e = mid - 1;
			else
				s = mid;
		}

		id -= pref[left][s] - pref[left][ptr];		

		int nxt = s + 1;
		if(nxt > p)
			return in[p];
		
		vector <int> vals;
		for(int i = 0; i <= left and nxt + i <= n; ++i)
			vals.push_back(i + nxt);
		
		sort(vals.begin(), vals.end(), [&](const int &a, const int &b) {
			return in[a] < in[b];
		});
		
		ptr = nxt;
		for(auto v: vals) {
			int tmp_left = left - (v - ptr);
			if(dp[n - v][tmp_left] >= id) {
				nxt = v;
				break;
			}
			
			id -= dp[n - v][tmp_left];
		}
		
		assert(ptr < nxt);
		left -= (nxt - ptr);
		
		if(p <= nxt) {
			reverse(in + ptr, in + nxt + 1);
			int ans = in[p];
			reverse(in + ptr, in + nxt + 1);
			return ans;
		}
		
		ptr = nxt;
	}
}

void solve() {
	scanf("%d %d %d", &n, &c, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);

	calc_dp();
	prepare();
	
	for(int i = 1; i <= q; ++i) {
		int p;
		LL id;
		scanf("%d %lld", &p, &id);
		
		if(id > dp[n][c]) {
			puts("-1");
			continue;
		}
		
		printf("%d\n", get(id, p));
	}
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}