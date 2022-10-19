#include<bits/stdc++.h>
const int N = 1e5 + 5;
const int magic = 300;
using namespace std;

struct query{
	int l, r, id;

	bool operator < (const query& a) const {
		int x = l / magic, y = a.l / magic;
		if (x != y) return (x < y);
		return r < a.r;
	}
} q[N];

int n, m, l = 1, r = 0, cnt[N], a[N], ans[N], res;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > n) a[i] = N-1;
	}
	for (int i = 1; i <= m; i++){
		q[i].id = i;
		cin >> q[i].l >> q[i].r;
	}
	sort(q+1, q+1+m);
	for (int i = 1; i <= m; i++){
		while (r < q[i].r) r++, res -= (cnt[a[r]] == a[r]), cnt[a[r]]++, res += (cnt[a[r]] == a[r]);
		while (l > q[i].l) l--, res -= (cnt[a[l]] == a[l]), cnt[a[l]]++, res += (cnt[a[l]] == a[l]);
		while (r > q[i].r) res -= (cnt[a[r]] == a[r]), cnt[a[r]]--, res += (cnt[a[r]] == a[r]), r--;
		while (l < q[i].l) res -= (cnt[a[l]] == a[l]), cnt[a[l]]--, res += (cnt[a[l]] == a[l]), l++;
		ans[q[i].id] = res;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}