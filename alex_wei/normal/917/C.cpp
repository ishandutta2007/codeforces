#include <bits/stdc++.h>
using namespace std;
const int N = 70 + 5;
void cmin(long long &x, long long y) {x = x < y ? x : y;}
map <int, int> mp;
int x, k, n, q, sz, c[N], lab[1 << 8], msk[N];
struct mat {
	long long a[N][N];
	mat() {memset(a, 0x3f, sizeof(a));}
	mat operator * (mat x) {
		mat y;
		for(int i = 1; i <= sz; i++)
			for(int j = 1; j <= sz; j++)
				for(int k = 1; k <= sz; k++)
					cmin(y.a[i][k], a[i][j] + x.a[j][k]);
		return y;
	}
	mat operator / (mat x) {
		mat y;
		for(int i = 1; i <= sz; i++)
			for(int j = 1; j <= sz; j++)
				cmin(y.a[1][j], a[1][i] + x.a[i][j]);
		return y;
	}
} tr, pw[27], I;
struct stone {
	int p, w;
	bool operator < (const stone &v) const {return p < v.p;}
} s[N];
int main() {
	// freopen("1.in", "r", stdin);
	cin >> x >> k >> n >> q;
	for(int i = 0; i < 1 << k; i++) if(__builtin_popcount(i) == x) msk[lab[i] = ++sz] = i;
	for(int i = 1; i <= k; i++) cin >> c[i];
	for(int i = 0; i < 1 << k; i++) {
		if(!lab[i]) continue;
		// cerr << "legal " << i << " " << lab[i] << endl;
		if(i & 1 ^ 1) {tr.a[lab[i]][lab[i >> 1]] = 0; continue;}
		for(int p = 1; p <= k; p++) {
			if(i >> p & 1) continue;
			// cerr << i << " " << p << " " << (i | 1 << p) << endl;
			tr.a[lab[i]][lab[(i | 1 << p) >> 1]] = c[p];
		}
	}
	// for(int i = 1; i <= sz; i++, cout << endl)
	// 	for(int j = 1; j <= sz; j++)
	// 		cout << tr.a[i][j] << " ";
	pw[0] = tr;
	for(int i = 1; 1 << i < n; i++) pw[i] = pw[i - 1] * pw[i - 1];
	for(int i = 1; i <= q; i++) cin >> s[i].p >> s[i].w, mp[s[i].p] = s[i].w;
	sort(s + 1, s + q + 1);
	if(s[q].p < n) s[++q] = {n};
	I.a[1][1] = 0;
	for(int i = 1, cur = 1; i <= q; i++) {
		int to = min(n - x + 1, s[i].p);
		for(int j = 26; ~j; j--) {
			if(cur + (1 << j) > to - k) continue;
			cur += 1 << j, I = I / pw[j];
		}
		while(cur < to) {
			// cerr << "chk " << cur << endl;
			// for(int i = 1; i <= sz; i++) cout << I.a[1][i] << " "; cout << endl;
			mat nxt;
			memset(nxt.a, 0x3f, sizeof(nxt.a));
			for(int i = 1; i <= sz; i++) {
				int S = msk[i];
				if(S & 1 ^ 1) {cmin(nxt.a[1][lab[S >> 1]], I.a[1][i]); continue;}
				for(int p = 1; p <= k; p++) {
					if(S >> p & 1) continue;
					long long nv = I.a[1][i] + c[p] + (mp.find(cur + p) == mp.end() ? 0 : mp[cur + p]);
					cmin(nxt.a[1][lab[(S | 1 << p) >> 1]], nv);
				}
			}
			cur++, I = nxt;
		}
	}
	cout << I.a[1][1] << endl;
	return 0;
}

/*
2022/4/28
start thinking at ??:??

.jpg.

start coding at 20:40
finish debugging at 21:10
*/