#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5, bzmax = 19;
const int inf = (~0u >> 2);

#define ll long long
#define pii pair<int, int>

int n;
char s[N];
int h[30];
int cnt[26][N];
int pre[N], suf[N];
int bzl[N][bzmax], bzr[N][bzmax];

boolean have(int l, int r, int c) {
	return cnt[c][r] ^ cnt[c][l - 1];
}
int get_tpl(int p, int c) {
	if (!cnt[c][p])
		return inf;
	if (have(pre[p], p, c))
		return 0;
	int t = 0, x = p;
	for (int i = bzmax - 1; ~i; i--) {
		int q = bzl[x][i];
		if (!have(pre[q], p, c)) {
			x = q;
			t |= 1 << i;
		}
	}
	return t + 1;
}
int get_tpr(int p, int c) {
	if (cnt[c][n] == cnt[c][p])
		return inf;
	if (have(p, suf[p], c))
		return 0;
	int t = 0, x = p;
	for (int i = bzmax - 1; ~i; i--) {
		int q = bzr[x][i];
		if (!have(p, suf[q], c)) {
			x = q;
			t |= 1 << i;
		}
	}
	return t + 1;
}

int jump(int bz[][bzmax], int p, int step) {
	for (int i = 0; step; step >>= 1, i++) {
		if (step & 1) {
			p = bz[p][i];
		}
	}
	return p;
}

ll fl[N], fr[N];
int ipre[N], isuf[N];
ll eval(int l, int r, int lastl, int lastr) {
	if (suf[r] > n && !pre[l])
		return 0;
	int tmin = inf, idc = -1, t, tl, tr;
	for (int c = 0; c < 26; c++) {
		if (!have(lastl, lastr, c) && ((tl = get_tpl(l, c)) ^ (tr = get_tpr(r, c)))) {
			t = min(tl, tr);
			if (t < tmin)	 {
				tmin = t;
				idc = c;
			}
		}
	}
	if (idc == -1)
		return fl[l] + fr[r];
//	cerr << l << " " << pre[l] << " " << r << " " << suf[r] << " " << idc << " " << tmin << '\n';
	int nl = jump(bzl, l, tmin);
	int nr = jump(bzr, r, tmin);
	if (!nl || nr > n)
		return fl[l] + fr[r];
	assert(nl && nr <= n);
	ll ret = fl[l] + fr[r] - fl[bzl[nl][0]] - fr[bzr[nr][0]];
	int sl = ((pre[bzl[nl][0]] < pre[ipre[nr]]) ? (bzl[nl][0]) : (ipre[nr]));
	int sr = ((suf[bzr[nr][0]] > suf[isuf[nl]]) ? (bzr[nr][0]) : (isuf[nl]));
	return ret + eval(sl, sr, pre[l], suf[r]);	
}

ll ans = 0;
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		cnt[(int) (s[i] -= 'a')][i]++;
	}
	for (int c = 0; c < 26; c++) {
		for (int i = 1; i <= n + 1; i++) {
			cnt[c][i] += cnt[c][i - 1];
		}
	}
	memset(h, 0, sizeof(h));
	for (int i = 1; i <= n; i++) {
		pre[i] = h[(int) s[i]];
		h[(int) s[i]] = i;
	}
	for (int i = 0; i < 26; i++)
		h[i] = n + 1;
	for (int i = n; i; i--) {
		suf[i] = h[(int) s[i]];
		h[(int) s[i]] = i;
	}
	pre[0] = 0, suf[n + 1] = n + 1;
	for (int i = 0; i < bzmax; i++)
		bzl[0][i] = 0, bzr[n + 1][i] = n + 1;
	for (int i = 1; i <= n; i++) {
		int& id = bzl[i][0], mi = inf;
		for (int j = pre[i]; j < i; j++) {
			if (pre[j] < mi) {
				mi = pre[j];
				id = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int& id = bzr[i][0], mx = -1;
		for (int j = i + 1; j <= suf[i]; j++) {
			if (suf[j] > mx) {
				mx = suf[j];
				id = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int& id = ipre[i], mi = inf;
		for (int j = i; j <= suf[i] && j <= n; j++) {
			if (pre[j] < mi) {
				mi = pre[j];
				id = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int& id = isuf[i], mx = -1;
		for (int j = max(pre[i], 1); j <= i; j++) {
			if (suf[j] > mx) {
				mx = suf[j];
				id = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		fl[i] = fl[bzl[i][0]] + max(0, pre[i] - 1);
		for (int j = 1; j < bzmax; j++) {
			bzl[i][j] = bzl[bzl[i][j - 1]][j - 1];
		} 
	}
	for (int i = n; i; i--) {
		fr[i] = fr[bzr[i][0]] + max(0, n - suf[i]);
		for (int j = 1; j < bzmax; j++) {
			bzr[i][j] = bzr[bzr[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		ll tmp = eval(i, i, i, i) + n - 1;
		ans += tmp;
//		cerr << "tmp: " << tmp << " (" << i << ")\n"; 
	}
	printf("%lld\n", ans);
	return 0;
}