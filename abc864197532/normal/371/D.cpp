#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second

struct Dsu {
	int n;
	vector <int> dsu;
	Dsu (int n): n(n) {
		dsu.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (x > y) swap(x, y);
		dsu[x] = y;
		return true;
	}
};

int main () {
	int n, q, a, b, c;
	cin >> n;
	int limit[n], now[n];
	fop (i,0,n) cin >> limit[i], now[i] = 0;
	Dsu dsu(n + 1);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		b--;
		if (a == 1) {
			cin >> c;
			while (c > 0) {
				int x = dsu.Find(b);
				if (now[x] + c >= limit[x]) {
					if (x == n) break;
					dsu.Union(x, x+1);
					if (x == n - 1) break;
					c -= (limit[x] - now[x]);
				} else {
					now[x] += c;
					c = 0;
				}
			}
		} else {
			if (dsu.Find(b) == b) {
				cout << now[b] << endl;
			} else {
				cout << limit[b] << endl;
			}
		}
	}
}