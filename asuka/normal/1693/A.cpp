#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

void solve() {
	int n, x, fl = 1;
	ll sum = 0;
	scanf("%d", &n);
	vector<int> o(n + 1, 0);

	rep(i, 1, n) {
		scanf("%d", &x);
		sum += x;
		fl &= sum >= 0;
		o[i] = sum == 0;
	}

	fl &= sum == 0;
	per(i, 2, n) {
		if (o[i - 1] && !o[i]) fl = 0;
	}
	puts(fl ? "YES" : "NO");
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;

	for (scanf("%d", &T); T--;) solve();

	return 0;
}