#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	int cnt = 0;
	Node * adj[2] = { 0, 0 };
};

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int insert(Node * x, const string s) { // return num nodes created
	int res = 0;
	for (char c : s) {
		x->cnt++;
		Node*&y = x->adj[c - '0'];
		if (!y) {
			y = new Node();
			res++;
		}
		x = y;
	}
	x->cnt++;
	return res;
}

const int MxN = 3005;
ll dp[MxN + 1][MxN + 1];
const int mod = (int) 1e9 + 7;
vector<string> words;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	{
		for (int len = 1; len <= 4; ++len) {
			for (int mask = 0; mask < (1 << len); ++mask) {
				string w(len, 'x');
				for (int i = 0; i < len; ++i)
					w[i] = mask & (1 << i) ? '1' : '0';
				words.push_back(w);
			}
		}

		for (string w : { "0011", "0101", "1110", "1111" })
			words.erase(find(words.begin(), words.end(), w));

	}
	Node * root = new Node();

	int n;
	cin >> n;
	string s(n, 'a');
	for (char &c : s)
		cin >> c;

	for (int diff = 0; diff < n; ++diff) {
		for (int i = 0; i + diff < n; ++i) {
			const int j = i + diff;
			ll &res = dp[i][j];
			for (const string &w : words) {
				if ((int) w.size() <= diff + 1 && s.substr(i, w.size()) == w) {
					if ((int) w.size() == diff + 1)
						res++;
					else
						res += dp[i + (int) w.size()][j];
				}
			}
			res %= mod;
		}
	}

	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		const int cntNew = insert(root, rev(s.substr(0, i + 1)));
		// cerr << cntNew << endl;
		for (int j = 0; j < cntNew; ++j) {
			ans += dp[j][i];
			ans %= mod;
		}
		cout << ans << '\n';
	}
	return 0;
}