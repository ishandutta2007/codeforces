#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
//#define int long long
const int maxn = 1e5, mod = 1e9 + 9, INF = 1e9;
const int L = 316;

string s, a[maxn];
int n, ans[maxn], tsz = 1, term[maxn + 1], q[maxn];
vector<vector<int>> to(maxn + 1, vector<int>(26, -1));
vector<int> poses[maxn];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s >> n;
	memset(term, -1, sizeof(term));
	memset(ans, -1, sizeof(ans));
	for(int i = 0; i < n; i++) {
		cin >> q[i] >> a[i];
		int len = sz(a[i]);
		if(len < L) {
			int v = 0;
			for(int j = 0; j < len; j++) {
				int ch = a[i][j] - 'a';
				if(to[v][ch] == -1) to[v][ch] = tsz++;
				v = to[v][ch];
			}
			term[v] = i;
		} else {
			string t = a[i] + '#' + s;
			int lent = sz(t);
			vector<int> p(lent);
			p[0] = 0;
			for(int j = 1; j < lent; j++) {
				int k = p[j - 1];
				while(k > 0 && t[k] != t[j]) k = p[k - 1];
				if(t[k] == t[j]) k++;
				p[j] = k;
			}
			vector<int> pos;
			for(int j = len + 1; j < lent; j++)
				if(p[j] == len)
					pos.push_back(j - lent - 1);
			if(sz(pos) >= q[i]) {
				ans[i] = INF;
				for(int j = q[i] - 1; j < sz(pos); j++)
					ans[i] = min(ans[i], pos[j] - pos[j - q[i] + 1] + len);
			}
		}
	}
	for(int i = 0; i < sz(s); i++) {
		int v = 0;
		for(int j = 0; j < L; j++) {
			if(i + j == sz(s)) break;
			int ch = s[i + j] - 'a';
			v = to[v][ch];
			if(v == -1) break;
			if(term[v] != -1) {
				poses[term[v]].push_back(i);
			}
		}
	}
	for(int i = 0; i < n; i++)
		if(sz(poses[i]) >= q[i]) {
			ans[i] = INF;
			for(int j = q[i] - 1; j < sz(poses[i]); j++)
				ans[i] = min(ans[i], poses[i][j] - poses[i][j - q[i] + 1] + sz(a[i]));
		}
	for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}