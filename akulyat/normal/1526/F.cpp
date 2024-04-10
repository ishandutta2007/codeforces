#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;

int ask(vector<int> ind) {	
	cout << "? ";
	for (auto i : ind)
		cout << i + 1 << ' ';
	cout << endl;
	ll res;
	cin >> res;
	return res;
}

int ask(int a, int b, int c) {
	return ask({a, b, c});
}

void build() {
	cin >> n;
	for (int i = 0; i < n; i++)
		v.push_back(i);
	shuffle(v.begin(), v.end(), rng);
	while (v.size() > 13)
		v.pop_back();	
}

vector<int> get() {
	vector<pair<int, vector<int>>> bst;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int u = j + 1; u < v.size(); u++) {
				bst.push_back({ask(i, j, u), {i, j, u}});
			}
		}
	}
	sort(bst.begin(), bst.end());

	return bst[0].S;
}

int one, cat, two;
vector<int> twos;
void get_one(vector<int> bst) {
	int a = bst[0];
	int b = bst[1];
	bst.pop_back();
	vector<pair<int, vector<int>>> all;
	for (int i = 0; i < n; i++)
		if (a != i && b != i) {
			bst.push_back(i);
			all.push_back({ask(bst), bst});
			bst.pop_back();
		}
	sort(all.rbegin(), all.rend());
	one = all[0].S[2];
	cat = a;
	twos.clear();
	for (int i = 1; i < 5; i++)
		if (all[i].F + 1 == all[0].F)
			twos.push_back(all[i].S[2]);
}

void get_two() {
	vector<int> vec = {one, cat};
	vector<pair<int, vector<int>>> all;
	for (auto cand : twos) {
		vec.push_back(cand);
		all.push_back({ask(vec), vec});		
		vec.pop_back();
	}
	sort(all.begin(), all.end());
	two = all[0].S[2];
}

void fix(vector<int> &ans) {
	for (auto &val : ans)
		val = n - 1 - val;
}

void get_all() {
	vector<int> ans(n);
	ans[one] = 0;
	ans[two] = 1;
	for (int i = 0; i < n; i++)
		if (i != one && i != two) 
			ans[i] = 1 + ask(one, two, i);
	if (ans[0] > ans[1])
		fix(ans);
	cout << "! ";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << endl;

	int cor;
	cin >> cor;
	if (cor == -1) {
		exit(0);
	}
}

void solve() {
	build();	
	vector<int> lbst = get();
	get_one(lbst);
	get_two();
	get_all();
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}