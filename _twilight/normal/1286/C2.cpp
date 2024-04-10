#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 105;

typedef vector<int> vec;

vec operator - (vec a, vec b) {
	for (int i = 0; i < 26; i++)
		a[i] = a[i] - b[i];
	return a;
}
vec operator - (vec a, char x) {
	a[x - 'a']--;
	return a;
}

vec to_vec(string s) {
	vec rt (26, 0);
	for (auto c : s)
		rt[c - 'a']++;
	return rt;
}
char findc(vec x) {
	int c = 0;
	while (!x[c])
		c++;
	return 'a' + c;
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if (n <= 3) {
		string ans = "", tmp;
		for (int i = 1; i <= n; i++) {
			cout << "? " << i << " " << i << endl;
			cin >> tmp;
			ans += tmp;
		}
		cout << "! " << ans << endl;
		return 0;
	}
	int L = (n * 2 + 2) / 3;
	int R = (n - L) << 1;
	
	vector<map<vec, int>> G (L + 1);
	
	cout << "? " << 1 << " " << L << endl;
	for (int i = 1; i <= L * (L + 1) / 2; i++) {
		string s;
		cin >> s;
		G[s.length()][to_vec(s)]++;
	}

	cout << "? " << 2 << " " << L << endl;
	for (int i = 1; i <= L * (L - 1) / 2; i++) {
		string s;
		cin >> s;
		G[s.length()][to_vec(s)]--;
	}
	
	vector<char> ans (n + 2, 0);
	vec las (26, 0);
	for (int i = 1; i <= L; i++) {
		for (auto& P : G[i]) {
			if (P.second) {
				ans[i] = findc(P.first - las);
				las = P.first;
				break;
			}
		}
	}

	for (auto& x : G)
		x.clear();

	cout << "? " << n - R + 1 << " " << n << endl;
	for (int i = 1; i <= R * (R + 1) / 2; i++) {
		string s;
		cin >> s;
		G[s.length()][to_vec(s)]++;
	}
	vec lspr = (*G[R].begin()).first;
	vector<vec> cur {lspr - ans[n - R + 1]}, nxt;
	for (int i = R - 1; i >= (R >> 1); i--) {
		for (auto& s : cur)
			G[i][s]--;
		for (auto& s : G[i]) {
			if (s.second) {
				vec pr = s.first;
				ans[n - R + 1 + i] = findc(lspr - pr);
				cur.insert(cur.begin(), pr);
				lspr = pr;
				break;
			}
		}
		nxt.clear();
		for (int j = 0; j < (signed) cur.size(); j++) {
			nxt.push_back(cur[j] - ans[n - R + 1 + j]);
		}
		swap(cur, nxt);
	}

	cout << "! " << (ans.data() + 1) << endl;
	return 0;
}