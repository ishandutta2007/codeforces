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

int n, m;
string s[N];

struct union_find {
	int n, components;
	vector <int> p, sz, sumx, sumy;

	union_find() {}
	union_find(int n) : n(n), components(n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		sz.assign(n + 1, 1);
		sumx.assign(n + 1, 0);
		sumy.assign(n + 1, 0);
		for (int i = 0; i < n; i++) {
			sumx[i] = i / m;
			sumy[i] = i % m;
		}
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
			sumx[b] += sumx[a];
			sumy[b] += sumy[a];
			components--;
		}
	}
};

vector <int> dx = {-1, -1, -1, 0, 0, 1, 1, 1}, dy = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	union_find dsu(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') continue;
			for (int k = 0; k < 8; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= n || x < 0) continue;
				if (y >= m || y < 0) continue;
				if (s[x][y] == '*') dsu.merge(x * m + y, i * m + j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') continue;
			if (dsu.sz[dsu.find(i * m + j)] != 3) {
				deb1("NO")
				return;
			}
			if (dsu.sumx[dsu.find(i * m + j)] % 3 == 0) {
				deb1("NO")
				return;
			}
			if (dsu.sumy[dsu.find(i * m + j)] % 3 == 0) {
				deb1("NO")
				return;
			}
		}
	}
	deb1("YES")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}