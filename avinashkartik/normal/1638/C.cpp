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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct union_find {
	int n, components;
	vector <int> p, sz;

	union_find() : n(), components() {}

	union_find(int n) : n(n), components(n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		sz.assign(n + 1, 1);
	}

	int find(int x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}

	void merge(int x, int y) {
		int a = find(x);
		int b = find(y);
		if (a != b) {
			if (sz[a] >= sz[b]) swap(a, b);
			p[a] = b;
			sz[b] += sz[a];
			components--;
		}
	}
};

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	union_find dsu(n);
	set <int> s;
	s.insert(0);
	for (int i = 1; i <= n; i++) {
		int mx = a[i];
		while (s.lower_bound(a[i]) != s.end()) {
			auto it = s.lower_bound(a[i]);
			dsu.merge(*it, a[i]);
			mx = max(mx, *it);
			s.erase(it);
		}
		s.insert(mx);
	}
	deb1(dsu.components)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}