//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10, maxlog = 18;

struct suf_array {
	string s;

	suf_array() {

	}

	suf_array(string s) : s(s) {

	}

	vector <int> cl;
	vector <int> p;
	vector <int> cnt;

	void build() {
		vector <int> g;

		for (int i = 0; i < (int)s.size(); i++) {
			g.push_back(s[i] - 'a' + 1);
		}

		g.push_back(0);

		for (int i = 0; i < maxlog; i++) {
			vector <pair <pii, int> > f;

			for (int j = 0; j < (int)g.size(); j++) {
				f.push_back(mp(mp(g[j], g[(j + (1 << i)) % (int)g.size()]), j));
			}

			sort(f.begin(), f.end());

			g[f[0].second] = 0;
			int cur = 0;

			for (int i = 1; i < (int)f.size(); i++) {
				if (f[i].first != f[i - 1].first) {
					cur++;
				}

				g[f[i].second] = cur;
			}
		}

		cl = g;
	}

	vector <int> tab[maxlog];

	void lcp() {
		/*cl.pop_back();
		for (int i = 0; i < (int)cl.size(); i++) {
			cl[i]--;
		}*/
		p.resize(cl.size());
		cnt.resize(cl.size());

		for (int i = 0; i < (int)cl.size(); i++) {
			p[cl[i]] = i;
		}

		int cur = 0;

		for (int i = 0; i < (int)cl.size(); i++) {
			int cli = cl[i];

			cur--;
			if (cur < 0) {
				cur = 0;
			}
			
			if (cli == (int)s.size()) {
				cur = 0;
				cnt[cli] = 0;
				continue;
			}

			int j = p[cli + 1];

			while (max(i, j) + cur < (int)s.size() && s[i + cur] == s[j + cur]) {
				cur++;
			}

			cnt[cli] = cur;
		}

		for (int i = 0; i < (int)cnt.size(); i++) {
			tab[0].push_back(cnt[i]);
		}

		for (int it = 1; it < maxlog; it++) {
			for (int i = 0; i <= (int)cnt.size() - (1 << it); i++) {
				tab[it].push_back(min(tab[it - 1][i], tab[it - 1][i + (1 << (it - 1))]));
			}
		}
	}

	int get_lcp(int a, int b) {
		if (a > b) {
			swap(a, b);
		}

		b--;

		int k = 0;

		while ((1 << (k + 1)) <= b - a + 1) {
			k++;
		}

		return min(tab[k][a], tab[k][b - (1 << k) + 1]);
	}
};

int p[maxn];
set <int> w[maxn];
ll tot[maxn];
ll sum = 0;

int getp(int x) {
	return (p[x] == x ? x : p[x] = getp(p[x]));
}

string s;

void add(suf_array &rsa, int it, int pos) {
	sum -= tot[it];
	pos = (int)s.size() - 1 - pos;
	tot[it] += (int)s.size() - pos;
	pos = rsa.cl[pos];

	auto itr = w[it].lower_bound(pos);

	if (itr != w[it].end() && itr != w[it].begin()) {
		int b = *itr;
		itr--;
		int a = *itr;
		tot[it] += rsa.get_lcp(a, b);
	}

	itr = w[it].insert(pos).first;

	if (itr != w[it].begin()) {
		itr--;
		int a = *itr;
		tot[it] -= rsa.get_lcp(a, pos);
		itr++;
	}

	itr++;
	if (itr != w[it].end()) {
		int b = *itr;
		tot[it] -= rsa.get_lcp(pos, b);
	}

	sum += tot[it];
}

void merg(suf_array &rsa, int a, int b) {
	if (w[a].size() < w[b].size()) {
		swap(a, b);
	}

	sum -= tot[b];

	for (auto x : w[b]) {
		int y = rsa.p[x];
		y = (int)s.size() - 1 - y;
		add(rsa, a, y);
	}

	p[b] = a;
}

int main() {
	cin >> s;

	suf_array sa = suf_array(s);
	sa.build();
	sa.lcp();

	reverse(s.begin(), s.end());
	suf_array rsa = suf_array(s);
	rsa.build();
	rsa.lcp();

	ll ans = 0;

	for (int i = 0; i < (int)sa.cnt.size(); i++) {
		ans += ((int)s.size() - sa.p[i]) - sa.cnt[i];
	}

	vector <pii> g;

	for (int i = 0; i < (int)sa.cnt.size() - 1; i++) {
		g.push_back(mp(sa.cnt[i], i));
	}

	sort(g.rbegin(), g.rend());
	
	int pos = 0;

	p[sa.cl[0]] = sa.cl[0];

	for (int i = (int)s.size() - 1; i >= 0; i--) {
		int cur = (int)s.size() - i;
		cur = sa.cl[cur];
		p[cur] = cur;
		tot[cur] = 1;
		sum++;
		add(rsa, cur, sa.p[cur] - 2);

		while (pos < (int)g.size() && g[pos].first == i) {
			int a = g[pos].second;
			int b = g[pos].second + 1;
			a = getp(a);
			b = getp(b);

			merg(rsa, a, b);
			pos++;
		}

		ans += sum;
	}

	cout << ans + 1 << endl;

	//system("pause");
}