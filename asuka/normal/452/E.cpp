#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
const int mod = 1e9 + 7;
int dp[N << 1][4];
namespace SAM {
int len[N << 1], link[N << 1], ch[N << 1][27], last, sz;
void init() {
	link[0] = -1;
}
void insert(int c, int id) {
	int cur = ++sz;
	dp[cur][id]++;
	len[cur] = len[last] + 1;
	int p = last;
	while (~p && !ch[p][c]) ch[p][c] = cur, p = link[p];
	if (p == -1) link[cur] = 0;
	else {
		int q = ch[p][c];
		if (len[q] == len[p] + 1) link[cur] = q;
		else {
			int clone = ++sz;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			rep(i, 0, 26) ch[clone][i] = ch[q][i];
			while (~p && ch[p][c] == q) ch[p][c] = clone, p = link[p];
		}
	}
	last = cur;
}
}
using namespace SAM;
string s1, s2, s3;
int ori[N << 1], d[N];
void add(int l, int r, int v) {
	d[l] = (d[l] + v) % mod;
	d[r + 1] = (d[r + 1] + mod - v) % mod;
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> s1 >> s2 >> s3;
	init();
	for (auto x : s1) insert(x - 'a', 1);
	insert(26, 0);
	for (auto x : s2) insert(x - 'a', 2);
	insert(26, 0);
	for (auto x : s3) insert(x - 'a', 3);
	rep(i, 1, sz) ori[i] = i;
	sort(ori + 1, ori + sz + 1, [] (int x, int y) {return len[x] > len[y];});
	rep(i, 1, sz) rep(id, 1, 3) dp[link[ori[i]]][id] += dp[ori[i]][id];
	rep(i, 1, sz) {
		ll res = 1;
		rep(id, 1, 3) res = (ll) res * dp[i][id] % mod;
		add(len[link[i]] + 1, len[i], res);
	}
	rep(i, 1, (int) min({s1.length(), s2.length(), s3.length()})) printf("%d ",(d[i] += d[i - 1]) %= mod);
	return 0;
}