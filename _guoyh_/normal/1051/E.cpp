# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1000051;
const int P = 998244353;
int n, lsz, rsz;
char a[MAXN], l[MAXN * 2], r[MAXN * 2];
int zl[MAXN * 2], zr[MAXN * 2];
int lcp[MAXN], rcp[MAXN];
ll f[MAXN], s[MAXN];
void getlcp(){
	memcpy(l + lsz + 1, a + 1, n * sizeof(char));
	memcpy(r + rsz + 1, a + 1, n * sizeof(char));
	int lp = 0, rp = 0;
	for (int i = 2; i <= lsz + n; i++){
		if (i > rp) zl[i] = 0;
		else zl[i] = min(zl[i - lp + 1], rp - i + 1);
		while (i + zl[i] <= lsz + n && l[1 + zl[i]] == l[i + zl[i]]) zl[i]++;
		if (i + zl[i] - 1 > rp){
			lp = i;
			rp = i + zl[i] - 1;
		}
	}
	lp = rp = 0;
	for (int i = 2; i <= rsz + n; i++){
		if (i > rp) zr[i] = 0;
		else zr[i] = min(zr[i - lp + 1], rp - i + 1);
		while (i + zr[i] <= rsz + n && r[1 + zr[i]] == r[i + zr[i]]) zr[i]++;
		if (i + zr[i] - 1 > rp){
			lp = i;
			rp = i + zr[i] - 1;
		}
	}
	memcpy(lcp + 1, zl + lsz + 1, n * sizeof(int));
	memcpy(rcp + 1, zr + rsz + 1, n * sizeof(int));
}
bool checkl(int pos){
	return lcp[pos] >= lsz || a[pos + lcp[pos]] > l[1 + lcp[pos]];
}
bool checkr(int pos){
	return rcp[pos] < rsz && a[pos + rcp[pos]] > r[1 + rcp[pos]];
}
int main(){
	// freopen("1.in", "r", stdin);
	scanf("%s%s%s", a + 1, l + 1, r + 1);
	n = strlen(a + 1);
	lsz = strlen(l + 1);
	rsz = strlen(r + 1);
	getlcp();
	// for (int i = 1; i <= n; i++) printf("lrcp %d %d %d\n", i, lcp[i], rcp[i]);
	int lp = 0, rp = -1;
	f[0] = s[0] = 1;
	for (int i = 1; i <= n; i++){
		while (i - (rp + 1) > lsz) rp++;
		if (rp + 1 + lsz == i && checkl(rp + 2)) rp++;
		while (i - lp > rsz) lp++;
		if (lp + rsz == i && checkr(lp + 1)) lp++;
		if (lp <= 0) f[i] = s[rp];
		else f[i] = (s[rp] - s[lp - 1]) % P;
		if (l[1] == '0' && a[i] == '0') f[i] = (f[i] + f[i - 1]) % P;
		s[i] = s[i - 1];
		if (a[i + 1] != '0') s[i] = (s[i] + f[i]) % P;
		// printf("f %d %lld %lld\n", i, f[i], s[i]);
		// printf("lr %d %d\n", lp, rp);
	}
	printf("%lld\n", (f[n] + P) % P);
	return 0;
}