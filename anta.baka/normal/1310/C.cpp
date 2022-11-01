#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>
#include <ctime>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

#define int ll

const int N = 1001;
const ll inf = 1e18 + 228;

int n, m;
ll k;
string s;
int lcp[N][N];
int po;
pii ord[(N - 1) * (N - 1)];
int pos[N - 1][N - 1];
int bnd[N - 1];
ll dp[N - 1][N - 1];
ll suf[N - 1][N - 1];

bool cmp(const pii& a, const pii& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	int l = lcp[a.first][b.first];
	int l1 = a.second - a.first + 1;
	int l2 = b.second - b.first + 1;
	if(l1 <= l && l2 <= l) {
	    return l1 < l2;
	}
	if (l2 <= l) {
		return false;
	}
	if (l1 <= l) {
		return true;
	}
	return s[a.first + l] < s[b.first + l];
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k >> s;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			lcp[j][i] = lcp[i][j] = (s[i] == s[j]) * (1 + lcp[i + 1][j + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ord[po++] = { i, j };
		}
	}
	sort(ord, ord + po, cmp);
	for (int i = 0; i < po; i++) {
		pos[ord[i].first][ord[i].second] = i;
	}
	int lf = 0, rg = po - 1;
	while (lf < rg) {
		int md = (lf + rg + 1) >> 1;
		for (int i = 0; i < n; i++) {
			int j = i;
			while (j < n && pos[i][j] < md) {
				j++;
			}
			bnd[i] = j;
		}
		for (int i = n - 1; i >= 0; i--) {
			dp[0][i] = (bnd[i] == n ? 0 : 1);
			suf[0][i] = dp[0][i] + (i < n - 1 ? suf[0][i + 1] : 0);
		}
		for (int s = 1; s < m; s++) {
			for (int i = n - 1; i >= 0; i--) {
				if (bnd[i] >= n - 1) {
					dp[s][i] = 0;
				}
				else {
					dp[s][i] = suf[s - 1][bnd[i] + 1];
				}
				suf[s][i] = dp[s][i] + (i < n - 1 ? suf[s][i + 1] : 0);
				if (suf[s][i] > inf) {
					suf[s][i] = inf;
				}
			}
		}
		if (dp[m - 1][0] >= k) {
			lf = md;
		}
		else {
			rg = md - 1;
		}
	}
	cout << s.substr(ord[lf].first, ord[lf].second - ord[lf].first + 1);
}