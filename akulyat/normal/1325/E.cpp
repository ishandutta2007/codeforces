#include <bits/stdc++.h>
 
using namespace std;
  
#define F first
#define S second
typedef int   ll;
typedef long double ld;
typedef pair<ll, ll> pll;  
 
bool viv = false;
 
const int ml = 1000000;
 
int ANS = 10 * ml;
vector<int> cnt;
vector<int> d;
vector<vector<int>> e;
vector<int> col;
 
void ans(ll val) {
	ANS = min(ANS, val);
	if (ANS <= 2) {
		cout << ANS << endl;
		exit(0);
	}
 
}
 
void DFS(int v, int c) {
}
 
vector<int> BFS(vector<int> star) {
	vector<int> d(ml + 10, 10 * ml);
	vector<int> st;
	for (auto i : star)
		st.push_back(i);
	for (auto i : star)
		d[i] = 0;
	int s = 0;
	while (s < st.size()) {
		int v = st[s];
		s++;
		for (auto ss : e[v])
			if (d[ss] > d[v] + 1) {
				st.push_back(ss);
				d[ss] = d[v] + 1;
			}
	}
	return d;
}
 
vector<int> aaa() {
	vector<int> res(ml + 10, -1);
	for (int i = 2; i < res.size(); i++) {
		if (res[i] == -1) {
			auto j = i;
			while (j < res.size())
				res[j] = i, j += i;
		}
	}
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<ll> v;
	v.resize(n);
	vector<vector<pll>> who(n);
	for (auto &i : v)
		cin >> i;
 
	auto aa = aaa();
	for (int i = 0; i < n; i++) {
		int me = v[i];
		unordered_map<int, int> cc;
		vector<int> a1;
		while (me != 1) {
			auto z = aa[me];
			cc[z]++;
			a1.push_back(z);
			me /= z;
		}
		for (auto i : a1)
			cc[i] &= 1;
		for (auto p : cc)
			if (p.S & 1)
				who[i].push_back({p.F, 1});
	}
 
	for (int i = 0; i < n; i++) {
		if (who[i].size() == 0) 
			ans(1);
	}
 
	cnt.resize(ml + 10, 0);
	for (int i = 0; i < n; i++) {
		if (who[i].size() == 1) {
			cnt[who[i][0].F]++;
		}
	}
	for (int i = 0; i < cnt.size(); i++)
		if (cnt[i] >= 2)
			ans(2);
 
	e.resize(ml + 10);
	for (int i = 0; i < n; i++) {
		if (who[i].size() == 2) {
			int a = who[i][0].F;
			int b = who[i][1].F;
			e[a].push_back(b);
			e[b].push_back(a);
		}
	}
 
 
	vector<int> star;
	for (int i = 0; i < ml + 10; i++)
		if (cnt[i] > 0)
			star.push_back(i);
	if (viv) {
		for (auto i : star)
			cout << i << ' ';
		cout << endl;
		for (int i = 0; i <= 7; i++) {
			cout << i << ": ";
			for (auto s : e[i])
				cout << s << ' ';
			cout << endl;
		}
	}
 
 
	for (int it = 0; it < 20; it++) {
		int k = (1ll << it);
		vector<int> a, b;
		for (int i = 0; i < star.size(); i++)
			if ((i | k) == i)
				a.push_back(star[i]);
			else
				b.push_back(star[i]);			
		auto da = BFS(a);
		auto db = BFS(b);
		for (int i = 0; i < da.size(); i++)
			ans(da[i] + db[i] + 2);
	}
 
	vector<int> vvv;
	for (int i = 0; i < 1000; i++)
		if (e[i].size() > 1)
			vvv.push_back(i);
 
	for (auto v : vvv) {
		auto d = BFS({v});
		for (int i = 0; i < ml + 10; i++) 
			if (i != v) {
				pair<int, int> best = {10000000, 10000000};
				for (auto s : e[i]) {
					if (d[s] <= d[i]) {
						int res = d[s] + d[i] + 1;
						if (res >= best.F)
							best.S = min(best.S, res);
						else
							best.S = best.F, best.F = res;
					}
				}
				ans(best.S);
			}
	}
 
 
	if (ANS > ml + 10)
		ANS = -1;
 
	cout << ANS << endl;
 
 
 
	return 0;
}