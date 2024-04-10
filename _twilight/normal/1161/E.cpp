#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

string query(vector<pii> S) {
	if (!S.size())
		return "";
	cout << "Q " << (signed) S.size();
	for (auto par : S) {
		cout << " " << par.first << " " << par.second;
	}
	cout << endl;
	string s;
	cin >> s;
	return s;
}

string query(vector<int> S) {
	if (S.size() <= 1)
		return "";
	string s[2];
	vector<pii> Q;
	int n = S.size();
	for (int i = 0; i < n - 1; i += 2) {
		Q.emplace_back(S[i], S[i + 1]);
	}
	s[0] = query(Q);
	Q.clear();
	for (int i = 1; i < n - 1; i += 2) {
		Q.emplace_back(S[i], S[i + 1]);
	}
	s[1] = query(Q);
	Q.clear();
	string rt = "";
	for (int i = 0; i < n - 1; i++) {
		rt += s[i & 1][i >> 1];
	}
	return rt;
}

const int N = 1e5 + 5;

int T, n;
int col[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> S, T;
		for (int i = 1; i <= n; i++) {
			S.push_back(i);
		}
		string s1 = "  " + query(S);
		T = {1};
		for (int i = 2; i <= n; i++) {
			if (s1[i] == '0') {
				T.push_back(i);
			}
		}
		int m = (signed) T.size();
		S.clear();
		for (int i = 0; i < m; i += 2) {
			S.push_back(T[i]);
		}
		string a = query(S);
		S.clear();
		for (int i = 1; i < m; i += 2) {
			S.push_back(T[i]);
		}
		string b = query(S);
		string s2 = "  ";
		for (int i = 2; i < m; i++) {
			if (i & 1) {
				s2 += b[(i - 3) >> 1];
			} else {
				s2 += a[(i - 2) >> 1];
			}
		}
		col[0] = 0, col[1] = 1;
		for (int i = 2; i < m; i++) {
			if (s2[i] == '1') {
				col[i] = col[i - 2];
			} else {
				col[i] = 3 - col[i - 1] - col[i - 2];
			}
		}
		vector<int> ans[3];
		int id = 0;
		for (int i = 1; i <= n; i++) {
			id += (s1[i] == '0');
			ans[col[id]].push_back(i);
		}
		cout << "A " << ans[0].size() << " " << ans[1].size() << " " << ans[2].size() << '\n';
		for (auto x : ans[0]) {
			cout << x << ' ';
		}
		cout << '\n';
		for (auto x : ans[1]) {
			cout << x << ' ';
		}
		cout << '\n';
		for (auto x : ans[2]) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}