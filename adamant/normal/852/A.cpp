#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e7 + 7;
map<int, map<int, int>> ans;

bool factorize(string s, int k = 2, bool print = false)
{
	if(ans[stol(s)][k] && print == false)
		return ans[stol(s)][k] - 1;
	int n = s.size();
	if(k == 0)
	{
		ans[stol(s)][k] = (n == 1) + 1;
		return n == 1;
	}
	if(n == 1)
	{
		if(print)
			for(int i = 0; i < k; i++)
				cout << s << endl;
		ans[stol(s)][k] = 2;
		return true;
	}
	for(int a = 1; a < n; a++)
		for(int b = a; b < n; b++)
			for(int c = b; c < n; c++)
				for(int d = c; d < n; d++)
					for(int e = d; e < n; e++)
						for(int f = e; f < n; f++)
						{
							int sum = 0;
							vector<string> split;
							split.push_back(s.substr(0, a));
							split.push_back(s.substr(a, b - a));
							split.push_back(s.substr(b, c - b));
							split.push_back(s.substr(c, d - c));
							split.push_back(s.substr(d, e - d));
							split.push_back(s.substr(e, f - e));
							split.push_back(s.substr(f));
							for(auto it: split)
								if(it.size())
									sum += stol(it);
							if(factorize(to_string(sum), k - 1, 0))
							{
								if(print)
								{
									cout << split[0];
									for(size_t i = 1; i < split.size(); i++)
										if(split[i].size())
											cout << '+' << split[i];
									cout << endl;
									factorize(to_string(sum), k - 1, 1);
								}
								ans[stol(s)][k] = 2;
								return true;
							}
						}
	ans[stol(s)][k] = 1;
	return 0;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int n;
	cin >> n;

	cin >> s;
	if(s.size() <= 6) {
		factorize(s, 3, 1);
		return 0;
	}
	while (true) {
		vector<int> digs, cuts;
		for (size_t i = 0; i < s.size(); ++i)
			digs.push_back(s[i] - '0');
		int sum = accumulate(digs.begin(), digs.end(), 0);

		for (size_t i = 0; i + 1 < s.size(); ++i) {
			if (digs[i] != 0) {
				cuts.push_back(i);
			}
		}
		vector<int> del(s.size());
		for (int it = 0; it < 10; ++it) {
			if (factorize(to_string(sum), 2)) {
				bool first = true;
				for (size_t i = 0; i < s.size(); ++i) {
					if (del[i]) continue;
					if (!first) cout << "+";
					cout << digs[i];
					first = false;
				}
				cout << endl;
				factorize(to_string(sum), 2, 1);
				return 0;
			}

			int c = cuts[rand() % cuts.size()];
			sum -= digs[c] + digs[c + 1];
			digs[c] = digs[c] * 10 + digs[c + 1];
			digs[c + 1] = 0;
			del[c + 1] = 1;
			sum += digs[c];
		}
	}
	return 0;
}