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

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");
 
	int val;
 
	constexpr static_mint() : val() {}
 
	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
 
	constexpr static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}
 
	constexpr static_mint inv() const {
		return pow(M - 2);
	}
 
	constexpr static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}
 
	constexpr static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}
 
	constexpr static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}
 
	constexpr static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}
 
	constexpr static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}
 
	constexpr static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}
 
	constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}
 
	constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}
 
	constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}
 
	constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}
 
	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}
 
	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}
 
	constexpr static_mint &operator++() {
		return *this += 1;
	}
 
	constexpr static_mint &operator--() {
		return *this -= 1;
	}
 
	constexpr static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}
 
	constexpr static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}
 
	template<typename T>
	constexpr explicit operator T() const {
		return T(val);
	}
 
	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}
 
	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};

using mint = static_mint<mod>;


int n, m, s, t;

void solve() {
	cin >> n >> m;
	cin >> s >> t;
	graph g(n);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
		g.add_edge(v, u);
	}
	
	vector <int> d(n + 1, INFi), vis(n + 1, 0);
	vector <mint> no(n + 1, 0);
	queue <int> q;
	q.push(s);
	d[s] = 0; no[s] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto i : g.adj[x]) {
			if (d[g.v[i]] > d[x] + 1) {
				d[g.v[i]] = d[x] + 1;
				q.push(g.v[i]);
			}
			if (d[g.v[i]] == d[x] + 1) no[g.v[i]] += no[x];
		}
	}
	
	vector <vector <mint>> nw(n + 1, vector <mint>(2, 0));
	for (int i = 1; i <= n; i++) {
		for (auto it : g.adj[i]) {
			if (d[g.v[it]] == d[i]) nw[i][0] += no[g.v[it]];
		}
	}
	nw[s][0] = 1, nw[s][1] = 0;
	q.push(s);
	while (q.size()) {
		auto x = q.front();
		q.pop();
		for (auto i : g.adj[x]) {
			if (d[g.v[i]] == d[x] + 1) {
				nw[g.v[i]][0] += nw[x][0];
				nw[g.v[i]][1] += nw[x][1];
				if (!vis[g.v[i]]) {
					q.push(g.v[i]);
					vis[g.v[i]] = 1;
				}
			}
		}
	}
	
	deb1(nw[t][0] + nw[t][1])
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}