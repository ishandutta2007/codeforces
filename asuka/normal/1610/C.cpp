#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int T, n, a[N], b[N], l[N], r[N];
bool check(int x) {
	rep(i, 1, n) l[i] = x - a[i], r[i] = b[i] + 1;
	int need = 1;
	rep(i, 1, n) {
		if(l[i] <= need && need <= r[i]) need++;
	}
	return need > x;
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d%d", &a[i], &b[i]);
		int L = 1, R = n, ans = 1;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (check(mid)) ans = mid, L = mid + 1;
			else R = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}