#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char s[501];
struct node {
	int ls, rs;
	int res[1<<16];
}nd[501];
int cnt, len = 1 << 16;
void fwtand(int a[], int op) {
	for (int L = 2, p = 1; L <= len; L <<= 1, p <<= 1)
		for (int i = 0; i < len; i += L)
			for (int j = i; j < i + p; j++)
				a[j] = op==1?(a[j]+a[j+p])%mod:(mod+a[j]-a[j+p])%mod;
}
void fwtor(int a[], int op) {
	for (int L = 2, p = 1; L <= len; L <<= 1, p <<= 1)
		for (int i = 0; i < len; i += L)
			for (int j = i; j < i + p; j++)
				a[j+p] = op==1?(a[j+p]+a[j])%mod:(mod+a[j+p]-a[j])%mod;
}
int tmp[1<<16];
void build(int &p, int l, int r) {
	p = ++cnt;
	if (l == r) {
		switch(s[l]) {
			case 'A': nd[p].res[0xff00] = 1; break;
			case 'B': nd[p].res[0xf0f0] = 1; break;
			case 'C': nd[p].res[0xcccc] = 1; break;
			case 'D': nd[p].res[0xaaaa] = 1; break;
			case 'a': nd[p].res[0x00ff] = 1; break;
			case 'b': nd[p].res[0x0f0f] = 1; break;
			case 'c': nd[p].res[0x3333] = 1; break;
			case 'd': nd[p].res[0x5555] = 1; break;
			default: nd[p].res[0xff00]=nd[p].res[0xf0f0]=nd[p].res[0xcccc]=nd[p].res[0xaaaa]=nd[p].res[0x00ff]=nd[p].res[0x0f0f]=nd[p].res[0x3333]=nd[p].res[0x5555]=1;
		}
		return;
	}
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (isalpha(s[i])) continue;
		if (s[i] == '(') ++cnt;
		else if (s[i] == ')') --cnt;
		else if (!cnt) {
			build(nd[p].ls, l + 1, i - 2), build(nd[p].rs, i + 2, r - 1);
			if (s[i] != '|') {
				fwtand(nd[nd[p].ls].res, 1), fwtand(nd[nd[p].rs].res, 1);
				for (int i = 0; i < len; i++) tmp[i] = 1ll * nd[nd[p].ls].res[i] * nd[nd[p].rs].res[i] % mod;
				fwtand(nd[nd[p].ls].res, -1), fwtand(nd[nd[p].rs].res, -1), fwtand(tmp, -1);
				for (int i = 0; i < len; i++) nd[p].res[i] = (nd[p].res[i] + tmp[i]) % mod;
			}
			if (s[i] != '&') {
				fwtor(nd[nd[p].ls].res, 1), fwtor(nd[nd[p].rs].res, 1);
				for (int i = 0; i < len; i++) tmp[i] = 1ll * nd[nd[p].ls].res[i] * nd[nd[p].rs].res[i] % mod;
				fwtor(nd[nd[p].ls].res, -1), fwtor(nd[nd[p].rs].res, -1), fwtor(tmp, -1);
				for (int i = 0; i < len; i++) nd[p].res[i] = (nd[p].res[i] + tmp[i]) % mod;
			}
			return;
		}
	}
	assert(0);
}
int main() {
	cin >> s + 1;
	int rt;
	build(rt, 1, strlen(s + 1));
	int n, ans = 0;
	cin >> n;
	int tmp = 0, lock = 0;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int x = (a<<3)|(b<<2)|(c<<1)|d;
		lock |= 1 << x, tmp |= e << x;
	}
	for (int i = 0; i < len; i++)
		if (!(i & lock)) ans = (ans + nd[1].res[tmp|i]) % mod;
	cout << ans << endl;
}