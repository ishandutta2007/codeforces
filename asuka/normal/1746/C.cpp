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
#ifdef Asuka
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n, 1);

		rep(i, 0, n - 1) {
			scanf("%d", &a[i]);
		}

		priority_queue<pii> q;

		rep(i, 1, n - 1) if (a[i] - a[i - 1] < 0) {
			q.emplace(- a[i] + a[i - 1], i);
		}

		per(i, 1, n) {
			if (q.empty()) break;

			auto [x, y] = q.top();
			q.pop();

			x -= i;
			b[i - 1] = y + 1;
			if (x > 0) q.emplace(x, y);
		}

		rep(i, 0, n - 1) printf("%d ", b[i]);
		printf("\n");
	}

	return 0;
}