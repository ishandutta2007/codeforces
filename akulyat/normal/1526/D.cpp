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
vector<int> v;
vector<int> cnt;
bool viv = false;

map<char, int> num;
map<int, char> ch;

void prepare() {
	string t = "ANTO";
	int k = 0;
	for (auto c : t)
		num[c] = k++;
	for (auto p : num)
		ch[p.S] = p.F;
}

vector<int> pl[4];
vector<int> p[4];

void build() {
	for (int i = 0; i < 4; i++) {
		pl[i].clear();
		p[i].clear();
		p[i].resize(1, 0);
	}
	for (int i = 0; i < n; i++) {
		pl[v[i]].push_back(i);
		for (int j = 0; j < 4; j++)
			p[j].push_back(p[j].back() + (v[i] == j));
	}
	cnt.assign(4, 0);
	for (auto i : v)
		cnt[i]++;
}

int sum(int l, int r, int val) {
	r++;
	return p[val][r] - p[val][l];
}

ll counter(vector<int> p) {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int val = v[i];
		int lb = 0;		
		int rb = i - 1;		
		int la = i + 1;		
		int ra = n - 1;		

		bool was = false;
		for (int j = 0; j < 4; j++) {
			if (p[j] == val)
				was = true;
			else {
				if (was) 
					ans += sum(lb, rb, p[j]);
				else
					ans += sum(la, ra, p[j]);
			}
		}
	}
	ans /= 2;
	return ans;
}

pair<ll, vector<int>> ans;
void use(vector<int> p) {
	vector<int> s;
	for (auto nu : p) {
		for (int i = 0; i < cnt[nu]; i++)
			s.push_back(nu);
	}
	ll val = counter(p);
	if (viv) {
		cout << val << ": ";
		for (auto i : s)
			cout << i << ' ';
		cout << '\n';
	}
	pair<ll, vector<int>> lans = {val, s};
	if (lans > ans)
		ans = lans;
}

void solve() {
	string s;
	cin >> s;
	n = s.size();
	v.clear();
	for (auto i : s)
		v.push_back(num[i]);
	if (viv) {
		cout << "v = ";
		for (auto i : v)
			cout << i << ' ';
		cout << '\n';
	}
	build();

	vector<int> p;
	for (int i = 0; i < 4; i++)
		p.push_back(i);
	ans = {-inf, {}};
	use(p);
	while (next_permutation(p.begin(), p.end())) {
		use(p);
	}
	string sans;
	for (auto nu : ans.S)
		sans += ch[nu];
	cout << sans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	prepare();
	while (t--)
		solve();

	return 0;
}