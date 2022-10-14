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
vector <pii> A;
vector <pair <int, pii>> M;

struct Seg {
	int l,r,m;
	lli sum, addTag;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		sum = -1ll << 60;
		addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg(l,m);
			ch[1] = new Seg(m,r);
			pull();
		}
	}
	void pull() {sum = max(ch[0]->sum, ch[1]->sum);}
	void push() {
		if (addTag) {
			if (r - l != 1) {
				ch[0]->sum += addTag;
				ch[0]->addTag += addTag;
				ch[1]->sum += addTag;
				ch[1]->addTag += addTag;
			}
			addTag = 0;
		}
	}
	void add(int a, int b, lli v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			sum += v;
			addTag += v;
		} else {
			push();
			if (a < m) ch[0]->add(a,b,v);
			if (m < b) ch[1]->add(a,b,v);
			pull();
		}
	}
	void set(int p, lli v) {
		if (r - l == 1) {
			sum = max(sum, v);
		} else {
			if (p < m) {
				ch[0]->set(p,v); 
			} else {
				ch[1]->set(p,v);
			}
			pull();
		}
	}
	lli query(int a, int b) {
		if (a <= l and r <= b) return sum;
		lli ans = -1ll << 60;
		push();
		if (a < m) ans = max(ans, ch[0]->query(a,b)); 
		if (m < b) ans = max(ans, ch[1]->query(a,b)); 
		return ans;
	}
};

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	A.resize(n);
	M.resize(q);
	Seg root(0, 300000);
	vector <int> b(m), v(m);
	fop (i,0,n) cin >> A[i].X >> A[i].Y;
	fop (i,0,m) cin >> b[i] >> v[i];
	vector <int> tmp = b;
	sort(A.begin(), A.end());
	sort(tmp.begin(), tmp.end());
	tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
	fop (i,0,m) {
		root.set(lower_bound(tmp.begin(), tmp.end(), b[i]) - tmp.begin(), -v[i]);
	}
	fop (i,0,q) {
		cin >> M[i].X >> M[i].Y.X >> M[i].Y.Y;
	}	
	sort(M.begin(), M.end());
	int now = 0;
	lli ans = -1ll << 60;
	fop (i,0,n) {
		while (now < q and M[now].X < A[i].X) {
			root.add(upper_bound(tmp.begin(), tmp.end(), M[now].Y.X) - tmp.begin(), 300000, M[now].Y.Y);
			now++;
		}
		ans = max(ans, root.query(0, 300000) - A[i].Y);
	}
	cout << ans << endl;
}