#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<string> a(n);
		map<string,int> as;
		for(int i = 0; i < n; i++) {
			cin >> a[i]; as[a[i]] = i;
		}
		int m;
		cin >> m;
		vector<vector<bool>> say(m, vector<bool>(n, false));
		vector<string> t(m);
		string s;
		getline(cin, s);
		for(int i = 0; i < m; i++) {
			getline(cin, s);
			t[i] = s;
			int r = s.find(':');
			if(s[0] != '?') {
				int num = as[s.substr(0,r)];
				if(i)
					say[i - 1][num] = true;
				if(i < m - 1)
					say[i + 1][num] = true;
			}
			string word;
			for(int j = r + 1; j < s.length(); j++)
				if(isalpha(s[j]) || '0'<=s[j]&&s[j]<='9')
					word += s[j];
				else {
					if(as.count(word) != 0)
						say[i][as[word]] = true;
					word.clear();
				}
			if(as.count(word) != 0)
				say[i][as[word]] = true;
		}
		vector<vector<bool>> dp(m, vector<bool>(n, false));
		vector<vector<int>> pr(m, vector<int>(n, -1));
		for(int i = 0; i < n; i++)
			dp[0][i] = !say[0][i];
		for(int i = 1; i < m; i++)
			for(int j = 0; j < n; j++)
				if(say[i][j] == false)
					for(int k = 0; k < n; k++)
						if(k != j && (i == 0 || dp[i - 1][k] == true)) {
							dp[i][j] = true;
							pr[i][j] = k;
							break;
						}
		int v;
		for(v = 0; v < n; v++)
			if(dp[m - 1][v] == true)
				break;
		if(v == n) {
			cout << "Impossible\n";
			continue;
		}
		vector<int> p;
		for(int i = m - 1; i >= 0; i--) {
			p.push_back(v);
			v = pr[i][v];
		}
		reverse(p.begin(), p.end());
		for(int i = 0; i < m; i++) {
			if(t[i][0] != '?') {
				cout << t[i] << "\n";
				continue;
			}
			cout << a[p[i]];
			cout << t[i].substr(1) << "\n";
		}
	}
	return 0;
}