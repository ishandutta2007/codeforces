#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<char> ans, qry;
	int ini;

	auto same = [&](int x, int y, int n) {
		return n - __builtin_popcount(x ^ y);
	};

	auto ask = [&]() {
		for (auto c : qry) cout << c;
		cout << endl;
		int x;
		cin >> x;
		if (x == SZ(qry)) exit(0);
		return x;
	};

	auto gao = [&](int l, int n) {
		vector<int> rem;
		rep(s, 0, (1 << n) - 1)
			rem.pb(s);

		while (SZ(rem) > 1) {
			int mn = inf, gs;

			rep(s, 0, (1 << n) - 1) {
				vector<int> buc(n + n + 1, 0);
				for (int o : rem) 
					buc[same(o, s, n) - same(o, 0, n) + n]++;
				int mx = *max_element(all(buc));
				if (mx < mn) mn = mx, gs = s;
			}

			fill(all(qry), 'F');
			rep(i, 0, n - 1) if (gs >> i & 1) qry[l + i] = 'T';
			int res = ask();
			vector<int> nrem;

			for (int o : rem)
				if (same(o, gs, n) - same(o, 0, n) == res - ini)
					nrem.pb(o);

			rem = nrem;
		}

		rep(i, 0, n - 1) if (rem[0] >> i & 1) ans[l + i] = 'T';
	};

	int n, B = 10;
	cin >> n;
	ans.resize(n, 'F');
	qry.resize(n, 'F');
	ini = ask();

	for (int i = 0; i < n; i += B)
		gao(i, min(n - i, B));

	qry = ans;
	ask();
	return 0;
}