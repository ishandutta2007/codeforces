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

ll n, k, need;
string s;
vector<int> cnt;
bool viv = false;

void add(int c, int cf = 1) {
	need += cf * ((k - cnt[c] % k) % k);
}

void solve() {
	cin >> n >> k;
	cin >> s;
	if (n % k) {
		cout << "-1\n";
		return;
	}
	string t;
	cnt.assign(26, 0);
	need = 0;
	pii bst = {-1, 0};
	for (int i = 0; i < n; i++) {
		char st = s[i];
		if (i + 1 != n)
			st++;
		for (char c = st; c <= 'z'; c++) {
			t += c;
			add(c - 'a', -1);
			cnt[c - 'a'] += (1);
			add(c - 'a');

			// if (i == 8) {
			// 	cout << need << ": ";
			// 	for (auto i : cnt)
			// 		cout << i << ' ';
			// 	cout << endl;
			// }

			if (i + 1 + need <= n) {
				if (bst.F < i) {
					bst = {i, c - 'a'};
				}
			}

			t.pop_back();
			add(c - 'a', -1);
			cnt[c - 'a'] += (-1);
			add(c - 'a');
		}
		t += s[i];
		add(s[i] - 'a', -1);
		cnt[s[i] - 'a'] += (1);
		add(s[i] - 'a');
	}
	if (viv)
		cout << "end " << bst.F << ' ' << bst.S << '\n';
	t.clear();
	for (int i = 0; i < bst.F; i++)
		t += s[i];
	t += char('a' + bst.S);

	cnt.assign(26, 0);
	for (auto i : t) {
		add(i - 'a', -1);
		cnt[i - 'a'] += (1);
		add(i - 'a');
	}

	for (auto &i : cnt)
		i = (k - i % k) % k;
	int will = t.size();
	for (auto i : cnt)
		will += i;
	while (will < n)
		t += 'a', will++;

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < cnt[i]; j++)
			t += char('a' + i);
	assert(!(t.size() % k));
	assert(t >= s);
	assert(t.size() == n);
	cnt.assign(26, 0);
	for (auto i : t)
		cnt[i - 'a']++;
	for (auto i : cnt)
		assert(!(i % k));

	cout << t << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}