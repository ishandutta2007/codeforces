#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define endl '\n'

const int MAXN = 20000 + 7;
vector <pair <int, pair <int, int> > > e;
int r[MAXN], p[MAXN];

int get(int v) {
	if (v == p[v]) {
		return v;
	} else {
		p[v] = get(p[v]);
		return p[v];
	}
}

void uni(int u, int v) {
	u = get(u);
	v = get(v);
	if (u != v) {
		if (r[u] < r[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (r[u] == r[v]) {
			r[u]++;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("sum.in");
	//ofstream cout("sum.out");
	//ifstream cin("period.in");
	//ofstream cout("period.out");
	int n, x;
	multiset <int> s;
	cin >> n;
	vector <int> ans;
	for (int i = 0; i < n * n; i++) {
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < n; i++) {
		int cur = *s.rbegin();
		for (int j = 0; j < (int) ans.size(); j++) {
			s.erase(s.find(__gcd(cur, ans[j])));
			s.erase(s.find(__gcd(ans[j], cur)));
		}
		ans.push_back(cur);
		s.erase(s.find(cur));
	}
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}