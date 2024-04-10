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
#define X first
#define Y second
const int N = 200000;

vector <int> adj[N];
int in[N], out[N], t = 0;

void dfs(int v = 0, int pa = -1) {
    in[v] = t++;
    for (int u : adj[v]) {
        if (u == pa) continue;
        dfs(u, v);
    }
    out[v] = t++;
}

struct Seg {
	int l,r,m;
	lli sum, addTag;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		sum = 0;
		addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg(l,m);
			ch[1] = new Seg(m,r);
			pull();
		}
	}
	void pull() {sum = ch[0]->sum + ch[1]->sum;}
	void push() {
		if (addTag) {
			if (r - l != 1) {
				ch[0]->sum += addTag * (m - l);
				ch[0]->addTag += addTag;
				ch[1]->sum += addTag * (r - m);
				ch[1]->addTag += addTag;
			}
			addTag = 0;
		}
	}
	void add(int a, int b, lli v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			sum += v * (r - l);
			addTag += v;
		} else {
			push();
			if (a < m) ch[0]->add(a,b,v);
			if (m < b) ch[1]->add(a,b,v);
			pull();
		}
	}
	lli query(int a, int b) {
		if (a <= l and r <= b) return sum;
		lli ans = 0;
		push();
		if (a < m) ans = ans + ch[0]->query(a,b); 
		if (m < b) ans = ans + ch[1]->query(a,b); 
		return ans;
	}
};

int main () {
    int n, q, u, v, k;
    cin >> n >> q;
    lli input[n];
    fop (i,0,n) cin >> input[i];
    fop (i,0,n-1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    Seg root(0, 2 * n);
    while (q--) {
        cin >> k >> u; u--;
        if (k == 1) {
            cin >> v;
            if (in[u] & 1) v = -v;
            root.add(in[u], out[u] + 1, v);
        } else {
            lli tmp = root.query(in[u], in[u] + 1);
            if (in[u] & 1) tmp = -tmp;
            cout << input[u] + tmp << endl;
        }
    }
}