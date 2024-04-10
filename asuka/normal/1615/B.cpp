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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int calc(int k, int x) { // [1, x] % 2^{k + 1} >= 2^k
	if(x == 0) return 0;
	int o = (1 << (k + 1)), oo = x / o * o;
	return oo / o * (1 << k) + max(0, (x - oo) - (1 << k) + 1);
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = r - l;
		// printf("%d\n", calc(0, r));
		rep(k, 0, 19) {
			int num = calc(k, r) - calc(k, l - 1);
			ans = min(ans, (r - l + 1) - num);
		}
		printf("%d\n", ans);
	}
	return 0;
}