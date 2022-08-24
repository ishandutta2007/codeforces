#include <bits/stdc++.h>

using namespace std;

vector<int> tovec(int x)
{
	vector<int> ans;
	for (int i = 29; i >= 0; --i)
		ans.push_back(x >> i & 1);
	return ans;
}

int fromvec(vector<int> x)
{
	int ans = 0;
	for (int i = 29; i >= 0; --i)
		if (x[i])
			ans ^= 1 << (30 - i - 1);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector<int> p(n);
	for (auto& x : p)
		cin >> x;
	vector<vector<int>> go(1, vector<int>(2));
	vector<int> cnt(1);
	for (auto& x : p)
	{
		int cur = 0;
		for (int ch : tovec(x))
		{
			//cerr << ch << ' ';
			if (go[cur][ch] == 0)
			{
				go[cur][ch] = go.size();
				go.push_back(vector<int>(2));
				cnt.push_back(0);
			}
			cur = go[cur][ch];
			++cnt[cur];
		}
	}
	vector<int> ans;
	for (int x : a)
	{
		vector<int> nw;
		int cur = 0;
		for (int ch : tovec(x))
		{
			if (go[cur][ch] && cnt[go[cur][ch]])
				cur = go[cur][ch], nw.push_back(ch);
			else
				cur = go[cur][1 ^ ch], nw.push_back(1 ^ ch);
			--cnt[cur];
			//cerr << nw.back() << ' ';
		}
		//cerr << '\n';
		ans.push_back(x ^ fromvec(nw));
	}
	for (auto& x : ans)
		cout << x << ' ';
	cout << '\n';

}