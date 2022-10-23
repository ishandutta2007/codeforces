# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 21;
const int P = 998244353;
int k;
ll l, r;
int a[MAXN], b[MAXN];
int cnt[1 << 10];
ll p10[MAXN];
bool vis[MAXN][1 << 10][2][2][2];
pair <ll, ll> f[MAXN][1 << 10][2][2][2];
pair <ll, ll> dfs(int nw, int s, bool f0, bool f1, bool f2){
	if (nw == 20) return make_pair(0, 1);
	if (vis[nw][s][f0][f1][f2]) return f[nw][s][f0][f1][f2];
	vis[nw][s][f0][f1][f2] = true;
	int mi = f1 ? a[nw] : 0, mx = f2 ? b[nw] : 9;
	pair <ll, ll> ans = make_pair(0, 0);
	for (int i = mi; i <= mx; i++){
		int ns = (f0 && i == 0) ? s : (s | (1 << i));
		if (cnt[ns] > k) continue;
		pair <ll, ll> na = dfs(nw + 1, ns, f0 && i == 0, f1 && i == mi, f2 && i == mx);
		ans.fst = (ans.fst + na.fst + i * p10[19 - nw] % P * na.snd % P) % P;
		ans.snd = (ans.snd + na.snd) % P;
	}
	// printf("f %d %d %d %d %d %lld %lld\n", nw, s, f0, f1, f2, ans.fst, ans.snd);
	return f[nw][s][f0][f1][f2] = ans;
}
int main(){
	for (int i = 1; i < (1 << 10); i++){
		if (i == (i & (-i))) cnt[i] = 1;
		else cnt[i] = cnt[i ^ (i & (-i))] + 1;
	}
	p10[0] = 1;
	for (int i = 1; i <= 18; i++) p10[i] = p10[i - 1] * 10ll % P;
	scanf("%lld%lld%d", &l, &r, &k);
	for (int i = 19; i >= 1; i--){
		a[i] = l % 10;
		l /= 10;
	}
	for (int i = 19; i >= 1; i--){
		b[i] = r % 10;
		r /= 10;
	}
	// for (int i = 1; i <= 19; i++) printf("ab %d %d %d\n", i, a[i], b[i]);
	printf("%lld\n", dfs(1, 0, true, true, true).fst);
	return 0;
}