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
#define MAXN 300000

struct Seg {
	int l,r,m,minn,maxx,addTag;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		minn = maxx = 0;
		addTag = 0;
		if (r - l != 1) {
			ch[0] = new Seg(l,m);
			ch[1] = new Seg(m,r);
			pull();
		}
	}
	void pull() {
		minn = min(ch[0]->minn, ch[1]->minn);
		maxx = max(ch[0]->maxx, ch[1]->maxx);
	}
	void push() {
		if (addTag != 0) {
			if (r - l != 1) {
				ch[0]->minn += addTag;
				ch[0]->maxx += addTag;
				ch[0]->addTag += addTag;
				ch[1]->minn += addTag;
				ch[1]->maxx += addTag;
				ch[1]->addTag += addTag;
			}
			addTag = 0;
		}
	}
	void set(int p, int v) {
		if (r - l == 1) {
			minn = maxx = v;
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
	int queryMin(int a, int b) {
		if (a <= l and r <= b) return minn;
		push();
		int ans = INT_MAX;
		if (a < m) ans = min(ans, ch[0]->queryMin(a,b)); 
		if (m < b) ans = min(ans, ch[1]->queryMin(a,b));
		return ans;
	}
	int queryMax(int a, int b) {
		if (a <= l and r <= b) return maxx;
		push();
		int ans = 0;
		if (a < m) ans = max(ans, ch[0]->queryMax(a,b)); 
		if (m < b) ans = max(ans, ch[1]->queryMax(a,b));
		return ans;
	}
	void addQuery(int a, int b, int v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			minn += v;
			maxx += v;
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
	int n, p = 0, now = 0;
	string s;
	cin >> n >> s;
	vector <char> now_char(n, ' ');
	Seg tree(0, n);
	fop (i,0,n) {
		if (s[i] == 'L') {
			p = max(0, p - 1);
		} else if (s[i] == 'R') {
			p++;
		} else {
			if (now_char[p] == '(') {
				tree.addQuery(p, n, -1);
				now--;
			}
			if (now_char[p] == ')') {
				tree.addQuery(p, n, 1);
				now++;
			}
			now_char[p] = s[i];
			if (now_char[p] == '(') {
				tree.addQuery(p, n, 1);
				now++;
			}
			if (now_char[p] == ')') {
				tree.addQuery(p, n, -1);
				now--;
			}
		}
		if (now != 0 or tree.queryMin(0, n) < 0) cout << -1 << ' ';
		else cout << tree.queryMax(0, n) << ' ';
	}
	cout << endl;
}