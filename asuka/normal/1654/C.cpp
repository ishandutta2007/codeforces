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
int T;
multiset<ll> S;
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	for (scanf("%d", &T); T; T--) {
		S.clear();
		int n;
		ll sum = 0;
		queue<ll> q;
		scanf("%d", &n);
		rep(i, 1, n) {
			int x;
			scanf("%d", &x);
			S.insert((ll) x);
			sum += x;
		}
		q.push(sum);
		bool fl = 1;

		while (!q.empty()) {
			if (SZ(q) > SZ(S)) {
				fl = 0;
				break;
			}

			ll u = q.front(); q.pop();
			auto it = S.lower_bound(u);

			if (it == S.end() || *it != u) {
				if (u == 1) {
					fl = 0;
					break;

				} else {
					q.push(u / 2);
					q.push((u + 1) / 2);
				}

			} else {
				S.erase(it);
			}
		}

		puts(fl ? "YES" : "NO");
	}

	return 0;
}