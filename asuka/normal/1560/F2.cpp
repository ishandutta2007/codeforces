#include<bits/stdc++.h>
#define int long long
#define N
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
int T, n, a[11], k;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld", &T);
	// printf("%lld\n", __builtin_ctz(0));
	while(T--) {
		char ch = getchar();
		while(!isdigit(ch)) ch = getchar();
		n = 0;
		while(isdigit(ch)) a[++n] = ch - '0', ch = getchar();
		scanf("%lld", &k);
		int mask = 0, pre = 0, ans = infll;
		rep(i, 1, n) {
			rep(x, a[i] + 1, 9) {
				if(__builtin_popcount(mask | (1 << x)) < k) {
					int val = pre * 10 + x;
					rep(j, i + 1, n) val *= 10;
					ans = min(ans, val);
				} else if(__builtin_popcount(mask | (1 << x)) == k) {
					int y = __builtin_ctz(mask | (1 << x));
					if(y <= 9) {
						int val = pre * 10 + x;
						rep(j, i + 1, n) val = val * 10 + y;
						ans = min(ans, val);
					}
				}
			} 
			pre = pre * 10 + a[i];
			mask |= (1 << a[i]);
		}
		if(__builtin_popcount(mask) <= k) {
			ans = 0;
			rep(i, 1, n) ans = ans * 10 + a[i];
		}
		printf("%d\n", ans);
	}	
	return 0;
}