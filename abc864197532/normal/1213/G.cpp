#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 200000
lli ans = 0;
vector <pair <int, pii>> edges;
pii query[MAXN];

struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int n): n(n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		ans += (1ll * size[x] * size[y]);
		if (size[x] > size[y]) {
			dsu[x] = y;
			size[y] += size[x];
			size[x] = 0;
		} else {
			dsu[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		return true;
	}
};

int main () {
    int n, m, a, b, c;
    cin >> n >> m;
    fop (i,0,n-1) {
        cin >> a >> b >> c;
        edges.pb({c, {a-1, b-1}});
    }
    sort(edges.begin(), edges.end());
    fop (i,0,m) {
        cin >> query[i].X;
        query[i].Y = i;
    }
    Dsu dsu(n);
    lli anss[m];
    sort(query, query + m);
    int now = 0;
    fop (i,0,m) {
        while (now < n - 1 and edges[now].X <= query[i].X) {
            dsu.Union(edges[now].Y.X, edges[now].Y.Y);
            now++;
        }
        anss[query[i].Y] = ans;
    }
    fop (i,0,m) cout << anss[i] << " \n"[i == m - 1];
}