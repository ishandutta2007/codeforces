#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

const ll mod = (119 << 23) + 1, root = 62;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

char s[200001], t[200001];
int p[26];
ll val[26];

int main(){
	rep(i,0,26) val[i] = rand();
	rep(i,0,26){
		scanf("%d", p+i);
		--p[i];
	}

	scanf("%s %s", s, t);

	int ss = (int)strlen(s), tt = (int)strlen(t);

	vl a(ss), b(tt);
	rep(i,0,ss) a[i] = val[s[i]-'a'] + val[p[s[i]-'a']];
	rep(i,0,tt) b[i] = val[t[i]-'a'];
	reverse(all(a));
	ll goal = 0;
	rep(i,0,ss) goal = (goal + val[s[i]-'a'] * val[p[s[i]-'a']]) % mod;
	vl pre(tt+1);
	rep(i,0,tt) pre[i+1] = (pre[i] + val[t[i]-'a'] * val[t[i]-'a']) % mod;
	vl c = conv(a, b);
	rep(i,0,tt-ss+1)
		if( (c[i+ss-1] - pre[i+ss] + pre[i] - goal) % mod == 0)
			putchar('1');
		else putchar('0');
	puts("");
}