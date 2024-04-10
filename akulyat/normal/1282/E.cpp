#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, t, a, b;
bool viv = false;
vector<vector<ll>> m;
vector<pll> sd;
map<pll, ll> cnt;
map<ll, set<ll>> who;

void add(ll a, ll b) {
	if (a > b)
		swap(a, b);
	cnt[{a, b}]++;
}

void erase() {
	map<pll, vector<ll>> fr;
	map<vector<ll>, ll> cnt;
	set<vector<ll>> ready;
	set<pll> used;

	for (auto t : m) {
		fr[{t[0], t[1]}].push_back(t[2]);
		fr[{t[0], t[2]}].push_back(t[1]);
		fr[{t[1], t[2]}].push_back(t[0]);
	}

	for (auto i : sd) {
		ll a = i.F;
		ll b = i.S;
		for (auto c : fr[{a, b}]) {
			vector<ll> add;
			add.push_back(a);
			add.push_back(b);
			add.push_back(c);
			sort(add.begin(), add.end());
			cnt[add]++;
			if (cnt[add] == 2)
				ready.insert(add);
		}
	}
	sd.clear();
	vector<ll> ans;

	map<vector<ll>, ll> num;
	for (ll i = 0; i< n - 2; i++) {
		num[m[i]] = i;
	}
	while (ans.size() < n - 2) {
		for (auto p : ready) {
			ans.push_back(num[p]);
			if (used.find({p[0], p[1]}) == used.end()) {
				sd.push_back({p[0], p[1]});
				used.insert({p[0], p[1]});
			}
			if (used.find({p[0], p[2]}) == used.end()) {
				sd.push_back({p[0], p[2]});
				used.insert({p[0], p[2]});
			}
			if (used.find({p[1], p[2]}) == used.end()) {
				sd.push_back({p[1], p[2]});
				used.insert({p[1], p[2]});
			}
		}
		ready.clear();
		for (auto i : sd) {
			ll a = i.F;
			ll b = i.S;
			for (auto c : fr[{a, b}]) {
				vector<ll> add;
				add.push_back(a);
				add.push_back(b);
				add.push_back(c);
				sort(add.begin(), add.end());
				cnt[add]++;
				if (cnt[add] == 2)
					ready.insert(add);
			}
		}
		sd.clear();
	}
	if (viv) 
		cout << "Deleter: ";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}

void solve() {
	cin >> n;
	cnt.clear();
	m.clear();
	for (ll i = 0; i < n - 2; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		add(a, b);
		add(c, b);
		add(a, c);
		m.push_back({a, b, c});
		sort(m.back().begin(), m.back().end());
	}
	sd.clear();
	for (auto p : cnt) {
		if (p.S == 1) {
			sd.push_back(p.F);
		}
	}

	who.clear();
	for (auto p : sd) {
		who[p.F].insert(p.S);
		who[p.S].insert(p.F);
	}

	ll st = 0;
	vector<ll> p;
	p.push_back(st);
	for (ll i = 0; i < n - 1; i++) {
		ll nx = *who[st].begin();
		p.push_back(nx);
		who[st].erase(nx);
		who[nx].erase(st);
		st = nx;
	}
	if (viv)
		cout << "Permut: ";
	for (auto i : p)
		cout << i + 1 << ' ';
	cout << '\n';

	erase();
}
 
int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}