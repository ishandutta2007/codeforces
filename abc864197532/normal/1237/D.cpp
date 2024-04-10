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

struct Seg {
	int l,r,m,minn,maxx;
	Seg* ch[2];
	Seg (int l, int r, vector <int> &A): l(l), r(r), m(l + r >> 1) {
		minn = maxx = 0;
		if (r - l != 1) {
			ch[0] = new Seg(l,m,A);
			ch[1] = new Seg(m,r,A);
			pull();
		} else {
			minn = maxx = A[l];
		}
	}
	void pull() {minn = min(ch[0]->minn, ch[1]->minn); maxx = max(ch[0]->maxx, ch[1]->maxx);};
	int queryMin(int a, int b) {
		if (a <= l and r <= b) return minn;
		int ans = 1 << 30;
		if (a < m) ans = min(ans, ch[0]->queryMin(a,b)); 
		if (m < b) ans = min(ans, ch[1]->queryMin(a,b));
		return ans;
	}
	int queryMax(int a, int b) {
		if (a <= l and r <= b) return maxx;
		int ans = 0;
		if (a < m) ans = max(ans, ch[0]->queryMax(a,b)); 
		if (m < b) ans = max(ans, ch[1]->queryMax(a,b));
		return ans;
	}
};

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, minn = 1 << 30, maxx = 0;
	cin >> n;
	vector <int> a(3 * n);
	fop (i,0,n) {
		cin >> a[i];
		minn = min(minn, a[i]);
		maxx = max(maxx, a[i]);
	}
	fop (i,0,n) a[i+n] = a[i];
	fop (i,0,n) a[i+n*2] = a[i];
	Seg root(0, 3 * n, a);
	vector <int> ans(3 * n, 864197532);
	FOP (i,3*n,0) {
		if (a[i] * 2 >= maxx) continue;
		int k = 0;
		FOP (j,19,0) {
			if (k + (1 << j) >= i) continue;
			if (root.queryMax(k + (1 << j), i) > a[i] * 2) k += (1 << j);
		}
		if (root.queryMax(k, i) > a[i] * 2) ans[k] = i;
	}
	FOP (i,3*n,0) {
		ans[i] = ans[i] - i;
		if (i != 3 * n - 1) {
			ans[i] = min(ans[i+1] + 1, ans[i]);
		}
	}
	if (minn * 2 >= maxx) {
		fop (i,0,n) ans[i] = -1;
	}
	fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}
//11 5 2 7 11 5 2 7 11 5 2 7