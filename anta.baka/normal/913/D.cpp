#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 3e18;
const int maxn = 2e5;

struct task {
	int a, t, id;
	bool operator < (const task &x) const {
		return t < x.t;
	}
};

int n, tot, a[maxn], t[maxn];
vector<task> vec;

bool can(int x) {
	vec.clear();
	for(int i = 0; i < n; i++)
		if(x <= a[i])
			vec.push_back({a[i], t[i], i});
	if(vec.size() < x) return false;
	sort(vec.begin(), vec.end());
	ll tm = 0;
	for(int i = 0; i < x; i++) tm += vec[i].t;
	return tm <= tot;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> tot;
	for(int i = 0; i < n; i++) cin >> a[i] >> t[i];
	int lf = 0, rg = n;
	while(lf < rg) {
		int md = (lf + rg) / 2;
		if(lf == md) md++;
		if(can(md)) lf = md;
		else rg = md - 1;
	}
	can(lf);
	cout << lf << endl << lf << endl;
	for(int i = 0; i < lf; i++) cout << vec[i].id + 1 << ' ';
}