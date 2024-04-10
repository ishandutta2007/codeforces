# include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int MAXN = 600051;
int n, m;
char s[MAXN];
int w[MAXN];
int sk[MAXN], tp;
int fail[MAXN];
int f1[26][MAXN];
int fw[MAXN];
void mdfy(int ps, int nm){
	for (; ps < MAXN; ps += (ps & (-ps))) fw[ps] += nm;
}
int gtsm(int ps){
	int res = 0;
	for (; ps; ps ^= (ps & (-ps))) res += fw[ps];
	return res;
}
namespace Qio{
	char ibuf[1 << 20], obuf[1 << 20];
	int pl, pr, po;
	char gc(){
		if (pl == pr) pr = (pl = 0) + fread(ibuf, sizeof(char), (1 << 20), stdin);
		return (pl == pr) ? EOF : ibuf[pl++];
	}
	void fls(){
		fwrite(obuf, sizeof(char), po, stdout);
		po = 0;
	}
	void pc(char x){
		if (po == (1 << 20)) fls();
		obuf[po++] = x;
	}
	ll rdi(){
		ll nm = 0;
		char x = gc();
		while (x < '0' || x > '9') x = gc();
		while (x >= '0' && x <= '9'){
			nm = nm * 10 + x - '0';
			x = gc();
		}
		return nm;
	}
	void pti(ll x){
		if (x < 0){
			pc('-');
			pti(-x);
			return;
		}
		if (x >= 10) pti(x / 10);
		pc(x % 10 + '0');
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	fail[0] = -1;
	ll ans = 0, tol = 0;
	for (int i = 1; i <= n; i++){
		cin >> s[i] >> w[i];
		s[i] = (s[i] - 'a' + ans) % 26 + 'a';
		w[i] = w[i] ^ (ans & ((1ll << 30) - 1));
		// cout << s[i] << ' ' << w[i] << '\n';
		for (int j = f1[s[i] - 'a'][i - 1]; j; j = f1[s[i] - 'a'][j]){
			int ps = lower_bound(sk + 1, sk + tp + 1, i - 1 - j + 1) - sk;
			tol -= w[sk[ps]];
			mdfy(i - 1 - j + 1, -1);
			// cout << "j " << j << ' ' << w[sk[ps]] << '\n';
		}
		while (tp > 0 && w[sk[tp]] >= w[i]){
			tol -= (ll)(gtsm(sk[tp]) - gtsm(sk[tp - 1])) * (w[sk[tp]] - w[i]);
			tp--;
		}
		sk[++tp] = i;
		if (i > 1 && s[i] == s[1]){
			mdfy(i, 1);
			tol += w[i];
		}
		int p = fail[i - 1];
		while (p != -1 && s[p + 1] != s[i]) p = fail[p];
		fail[i] = p + 1;
		for (int j = 0; j < 26; j++) if (j != s[fail[i] + 1] - 'a') f1[j][i] = fail[i];
		f1[s[fail[i] + 1] - 'a'][i] = f1[s[fail[i] + 1] - 'a'][fail[i]];
		ans += tol + w[sk[1]];
		// cout << "tol ";
		// cout.flush();
		// Qio::pti(tol);
		// Qio::pc(' ');
		Qio::pti(ans);
		Qio::pc('\n');
		Qio::fls();
		cout.flush();
	}
	return 0;
}