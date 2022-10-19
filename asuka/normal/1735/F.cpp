#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
using db = double;

struct P { 
	db x, y;
	P(db _x = 0, db _y = 0) { x = _x, y = _y; }

	P operator + (const P &o) const {
		return P(x + o.x, y + o.y);
	}

	P operator - (const P &o) const {
		return P(x - o.x, y - o.y);
	}

	bool operator < (const P &o) const {
		return x * o.y - y * o.x < 0;
	}
} st, ed;

multiset<P> S;
int n, p[300015], q[300015];

void solve() {
	cin >> n >> st.y >> st.x;
	ed = st;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) cin >> q[i];

	rep(i, 1, n) {
		P o = P(q[i], -p[i]);
		S.insert(o), S.insert(o);
		// for (P w : S) printf("(%lf %lf)\n", w.x, w.y);
		// printf("\n");
		st = st - o, ed = ed + o;

		while (st.x < 0 && st.x + S.begin() -> x <= 0)
			st = st + *S.begin(), S.erase(S.begin());

		// printf("st %lf %lf\n", st.x, st.y);

		if (st.x < 0) {
			db k = (S.begin() -> x + st.x) / S.begin() -> x;
			P ee = *S.begin();
			st = st + ee;
			S.erase(S.begin());
			ee.x *= k, ee.y *= k;
			st = st - ee;
			S.insert(ee);
		}
		// printf("ed %lf %lf\n", ed.x, ed.y);

		while (ed.y < 0 && ed.y - S.rbegin() -> y <= 0)
			ed = ed - *S.rbegin(), S.erase(--S.end());

		if (ed.y < 0) {
			db k = (ed.y - S.rbegin() -> y) / (- S.rbegin() -> y);
			P ee = *S.rbegin();
			ed = ed - ee;
			S.erase(--S.end());
			ee.x *= k, ee.y *= k;
			ed = ed + ee;
			S.insert(ee);
		}

		// for (P w : S) printf("(%lf %lf)\n", w.x, w.y);
		// printf("\n");
		cout << st.y << '\n';
	}

	S.clear();
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#else
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	int t;
	cout << fixed << setprecision(6);
	cin >> t;
	while (t--) solve();
	return 0;
}