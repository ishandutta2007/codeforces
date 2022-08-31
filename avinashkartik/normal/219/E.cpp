#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m;
map <int, int> w;
set <pll, greater<>> s;
set <int> cur;

void add(int i, int j) {
	if (j - i <= 1) return;
	int mid = (i + j) / 2;
	s.insert({mid - i, -mid});
}

void del(int i, int j) {
	if (j - i <= 1) return;
	int mid = (i + j) / 2;
	s.erase({mid - i, -mid});
}

void insert(int x, int y) {
	deb1(x)
	w[y] = x;
	auto it = cur.lower_bound(x);
	int r = *it;
	it--;
	if (r != INFi) {
		add(x, r);
	} else {
		s.erase({n - *it, -n});
	}
	if (*it == -INFi) {
		s.erase({r - 1, -1});
	} else {
		del(*it, r);
		add(*it, x);
	}
	cur.insert(x);
}

void remove(int x) {
	cur.erase(x);
	auto it = cur.lower_bound(x);
	if (*it == INFi) {
		it--;
		del(*it, x);
		s.erase({n - x, -n});
		s.insert({n - *it, -n});
	} else {
		int r = *it;
		del(x, r);
		it--;
		if (*it == -INFi) {
			s.erase({x - 1, -1});
			s.insert({r - 1, -1});
		} else {
			del(*it, x);
			add(*it, r);
		}
	}
}

void solve() {
	cin >> n >> m;
	cur.insert(-INFi);
	cur.insert(INFi);
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		if (x == 1) {
			if (cur.size() == 2) {
				deb1(1)
				w[y] = 1;
				cur.insert(1);
				s.insert({n - 1, -n});
			} else {
				auto it = *s.begin();
				s.erase(s.begin());
				insert(-it.s, y);
			}
		} else {
			if (cur.size() == 3) {
				cur.erase(w[y]);
				s.clear();
			} else {
				remove(w[y]);
			}
		}
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}