#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 520;

struct Dsu {
	int n;
	vector <int> dsu, size;
	int cc;
	Dsu (): n(N) {
		dsu.resize(n);
		size.resize(n);
		cc = 0;
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
		if (size[x] > size[y]) {
			dsu[x] = y;
			size[y] += size[x];
			size[x] = 0;
		} else {
			dsu[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		cc++;
		return true;
	}
};

int main () {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    vector <pii> edge(m);
    fop (i,0,m) {
        scanf("%d %d", &u, &v);
        u--; v--;
        edge[i] = {u, v};
    }
    Dsu l[m+1], r[m+1];
    fop (i,1,m+1) {
        l[i] = l[i-1];
        l[i].Union(edge[i-1].X, edge[i-1].Y);
    }
    FOP (i,m,0) {
        r[i] = r[i+1];
        r[i].Union(edge[i].X, edge[i].Y);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &u, &v);
        Dsu aa = l[u-1];
        fop (i,0,n) aa.Union(i, r[v].dsu[i]);
        cout << n - aa.cc << endl;
    }
}