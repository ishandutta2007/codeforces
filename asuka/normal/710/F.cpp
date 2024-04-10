#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
struct hash_map {
	struct data {
		long long u;
		int v, nex;
	};               
	data e[N << 1];  
	int h[N], cnt;
	int hash(long long u) { return u % N; }
	int& operator[](long long u) {
		int hu = hash(u); 
		for (int i = h[hu]; i; i = e[i].nex)
			if (e[i].u == u) return e[i].v;
		return e[++cnt] = (data) {u, 0, h[hu]}, h[hu] = cnt, e[cnt].v;
	}
	int query(long long u) {
		int hu = hash(u); 
		for (int i = h[hu]; i; i = e[i].nex)
			if (e[i].u == u) return e[i].v;
		return 0;
	}
	hash_map() {
		cnt = 0;
		memset(h, 0, sizeof(h));
	}
} hs;
const int mod[] = {1000000007, 1000000009};
int n, opt, cnt[N], pre[2][N], pd[2][N];
VI lens;
string s;
void geths(const string &s) {
	rep(p, 0, 1) {
		rep(i, 0, SZ(s) - 1) {
			pre[p][i] = 0;
			if (i) pre[p][i] = (ll) pre[p][i - 1] * 233 % mod[p];
			(pre[p][i] += s[i]) %= mod[p];
		}
	}
}
ll getval(int l, int r) {
	int v[2] = {0, 0};
	rep(p, 0, 1) v[p] = (pre[p][r] - (ll) pd[p][r - l + 1] * pre[p][l - 1] % mod[p] + mod[p]) % mod[p];
	return (ll) v[0] * v[1];
}
int main() {
	// freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(p, 0, 1) {
		pd[p][0] = 1;
		rep(i, 1, 300000) pd[p][i] = (ll) pd[p][i - 1] * 233 % mod[p];
	}
	while (n--) {
		cin >> opt >> s;
		int len = SZ(s);
		geths(s);
		ll v = (ll) pre[0][len - 1] * pre[1][len - 1];
		if (opt == 1) {
			if (cnt[len]++ == 0) lens.insert(lower_bound(all(lens), len), len);
			hs[v]++;
		} else if (opt == 2) {
			if (--cnt[len] == 0) lens.erase(lower_bound(all(lens), len));
			hs[v]--;
		} else {
			ll ans = 0;
			for (auto l : lens) {
				rep(i, l - 1, len - 1) {
					ans += hs.query(getval(i - l + 1, i));
				}
			}
			cout << ans << endl;
			cout.flush();
		}
	}
	return 0;
}