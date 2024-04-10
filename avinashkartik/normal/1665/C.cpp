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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
    int n, m;
    vector <int> v, w;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
    }
};

int n, p[N];

void solve() {
	cin >> n;
	graph g(n);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g.add_edge(p[i], i);
	}
	int d1 = n, d2 = 1;
	multiset <int, greater<>> s;
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		if (g.adj[i].size() > 1) {
			v.pb(g.adj[i].size() - 1);
		}
	}
	sort(all(v), greater<>());
	for (auto it : v) {
		for (int j = 1; j <= it; j++) {
			d1--;
			s.insert(d2 + j);
		}
		d2++;
	}
	while (s.size()) {
		if (*s.begin() > d1) {
			d1++;
			s.erase(s.begin());
		} else break;
	}
	deb1(d1)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}