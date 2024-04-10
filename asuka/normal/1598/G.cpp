#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int qpow(int a, int b, const int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int mod[5] = {1000000007, 1000000009, 1919810, 19260817, 192600817};
int n, m, hs[N][5], ht[N][5], pd[N][5], ipd[N][5];
char s[N], t[N];
bool FLAG;
int get(int l, int r, int p) {
	int val = hs[r][p] + (mod[p] - ((ll) hs[l - 1][p] * pd[r - l + 1][p] % mod[p]));
	val %= mod[p];
	return val;
}
int gett(int l, int r, int p) {
	int val = ht[r][p] + (mod[p] - ((ll) ht[l - 1][p] * pd[r - l + 1][p] % mod[p]));
	val %= mod[p];
	return val;
}
bool bigger(int l1, int r1, int l2, int r2) {
	if(l1 > r1 || l2 > r2) return 0;
	int l = l1, r = r1, ans = l1 - 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		bool eq = 1;
		rep(p, 0, 4) {
			int v1 = get(l1, mid, p);
			int v2 = gett(l2, l2 + (mid - l1 + 1) - 1, p);
			eq &= v1 == v2;
		}
		if(eq) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	if(ans == r1) return 0;
	return s[ans + 1] > t[l2 + (ans + 1 - l1 + 1) - 1];
}
void check(int l1, int r1, int l2, int r2) {
	if(l1 <= 0 || r2 > n) return;
	bool eq = 1;
	rep(p, 0, 4) {
		int v1 = get(l1, r1, p);
		int v2 = get(l2, r2, p);
		int val = (v1 + v2) % mod[p];
		eq &= val == ht[m][p];
	}
	if(eq) {
		printf("%d %d\n%d %d\n", l1, r1, l2, r2);
		exit(0);
	}
}
int getlen(int x, int y) {
	if(y - x + 1 < m) {
		int zero = 0;
		if(t[1] == '1' && t[2] < s[x]) zero++;
		return m - zero;
	}
	assert(y - x + 1 == m);
	int l = x, r = y, ans = x - 1;
	while(l <= r) {
		// if(x == 7 && y == 14) {
		// 	printf("%d %d\n", l, r);
		// }
		int mid = (l + r) >> 1;
		bool eq = 1;
		rep(p, 0, 4) {
			int v1 = get(x, mid, p);
			int v2 = ht[mid - x + 1][p];
			eq &= v1 == v2;
		}
		if(eq) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	if(ans == y) return 0;
	// if(x == 7 && y == 14) {
	// 	printf("lzjakioi %d\n", ans);
	// }
	int zero = ans - x + 1;
	int pos = ans + 1, ppos = ans + 2;
	if(pos <= y) {
		if(s[pos] > t[pos - x + 1]) return -1;
		if(t[pos - x + 1] - s[pos] == 1 && bigger(ppos, y, ppos - x + 1, y - x + 1)) zero++;
	}
	return m - zero;
}
random_device rd;
mt19937 rnd(rd());
bool isPrime(int x) {
	for(int i = 2; i * i <= x; ++i) if(x % i == 0) return 0;
	return 1;
}
int getPrime() {
	int x = uniform_int_distribution <int> (1e8, 1e9)(rnd);
	while(!isPrime(x)) x = uniform_int_distribution <int> (1e8, 1e9)(rnd);
	return x;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s%s", s + 1, t + 1);
	rep(p, 0, 4) mod[p] = getPrime();
	n = strlen(s + 1);
	m = strlen(t + 1);
	rep(p, 0, 4) ipd[0][p] = pd[0][p] = 1, ipd[1][p] = qpow(10, mod[p] - 2, mod[p]);
	rep(i, 2, max(n, m)) rep(p, 0, 4) ipd[i][p] = ((ll) ipd[i - 1][p] * ipd[i][1]) % mod[p];
	rep(i, 1, max(n, m)) rep(p, 0, 4) pd[i][p] = (ll) pd[i - 1][p] * 10 % mod[p];
	rep(i, 1, n) rep(p, 0, 4) hs[i][p] = ((ll) hs[i - 1][p] * 10 % mod[p] + (s[i] - '0')) % mod[p];
	rep(i, 1, m) rep(p, 0, 4) ht[i][p] = ((ll) ht[i - 1][p] * 10 % mod[p] + (t[i] - '0')) % mod[p];
	rep(p, -1, 0) rep(i, 1, n) {
		int len = m + p;
		if(len == 0) break;
		if(i + len - 1 > n) break;
		int mlen = getlen(i, i + len - 1);
		// printf("[%d %d]: %d\n", i, i + len - 1, mlen);
		if(mlen <= 0) continue;
		check(i - mlen, i - 1, i, i + len - 1);
		check(i, i + len - 1, i + len, i + len + mlen - 1);
	}
	// rep(p, 0, 4) printf("%d\n", ht[5][p]);
	// rep(p, 0, 4) printf("%d\n", get(7, 11, p));
	// rep(p, 0, 4) printf("%d\n", ht[m][p]);
	// rep(p, 0, 4) printf("%d %d\n", get(1, 2, p), get(3, 3, p));
	return 0;
}
/*
11451419198112345
19198626
514 + 19198112

1999999811
9999999
*/