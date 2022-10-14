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

struct Seg {
	int l,r,m;
	long long sum,addTag;
	Seg* ch[2];
	Seg (int l, int r, vector <long long> &A): l(l), r(r), m(l + r >> 1) {
		sum = 0;
		addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg(l,m,A);
			ch[1] = new Seg(m,r,A);
			pull();
		} else {
			sum = A[l];
		}
	}
	void pull() {sum = min(ch[0]->sum, ch[1]->sum);}
	void push() {
		if (addTag != 0) {
			if (r - l != 1) {
				ch[0]->sum += addTag;
				ch[0]->addTag += addTag;
				ch[1]->sum += addTag;
				ch[1]->addTag += addTag;
			}
			addTag = 0;
		}
	}
	void set(int p, int v) {
		if (r - l == 1) {
			sum = v;
		} else {
			push();
			if (p < m) {
				ch[0]->set(p,v); 
			} else {
				ch[1]->set(p,v);
			}
			pull();
		}
	}
	long long query(int a, int b) {
		if (a <= l and r <= b) return sum;
		push();
		long long ans = LLONG_MAX;
		if (a < m) ans = min(ans, ch[0]->query(a,b)); 
		if (m < b) ans = min(ans, ch[1]->query(a,b));
		return ans;
	}
	void addQuery(int a, int b, long long v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			sum += v;
			addTag += v;
		} else {
			push();
			if (a < m) ch[0]->addQuery(a,b,v);
			if (m < b) ch[1]->addQuery(a,b,v);
			pull();
		}
	}
};

int main () {
	int n;
	cin >> n;
	int a[n], id[n], val[n];
	vector <long long> b(n);
	fop (i,0,n) {
		cin >> a[i];
		a[i]--;
		id[a[i]] = i;
	}
	fop (i,0,n) cin >> val[i];
	b[0] = val[0];
	fop (i,1,n) b[i] = b[i-1] + val[i];
	Seg tree(0, n, b);
	long long ans = tree.query(0, n - 1);
	fop (i,0,n) {
		tree.addQuery(0, id[i], val[id[i]]);
		tree.addQuery(id[i], n, -val[id[i]]);
		ans = min(ans, tree.query(0, n - 1));
	}
	cout << ans << endl;
}