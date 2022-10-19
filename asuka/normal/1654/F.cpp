#include<bits/stdc++.h>
#define ll long long
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

vector<int> solve(vector<int> vec) {
	if (SZ(vec) == 1) return vec;

	vector<pii> tmp;

	for (int i = 0; i < SZ(vec); i += 2) {
		tmp.emplace_back(vec[i], vec[i + 1]);
		tmp.emplace_back(vec[i + 1], vec[i]);
	}

	sort(all(tmp)); tmp.erase(unique(all(tmp)));

	vector<int> L, R;

	for (int i = 0; i < SZ(vec); i += 2) {
		L.pb(lower_bound(all(tmp), mp(vec[i], vec[i + 1])) - tmp.begin());
		R.pb(lower_bound(all(tmp), mp(vec[i + 1], vec[i])) - tmp.begin());
	}

	vector<int> res = min(solve(L), solve(R)), res2;

	for (int o : res) {
		res2.pb(tmp[o].fi);
		res2.pb(tmp[o].se);
	}

	return res2;
}

int n;
char s[(1 << 18) + 111];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	vector<int> vec;
	rep(i, 0, (1 << n) - 1) vec.pb(s[i] - 'a');
	vec = solve(vec);
	rep(i, 0, (1 << n) - 1) printf("%c", vec[i] + 'a');
	return 0;
}