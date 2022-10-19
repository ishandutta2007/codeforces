#include<bits/stdc++.h>
#define int long long
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
const int N = 50015;
int T, n, a[N], x, dp[N], pre[N];
signed main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]), dp[i] = 0;
		scanf("%lld", &x);
		rep(i, 1, n) a[i] -= x, pre[i] = pre[i - 1] + a[i];
		multiset<int> S, S2;
		int ptr = 1;
		rep(i, 1, n) {
			if(i > 1) S.insert(pre[i - 2]);
			S2.insert(dp[max(0ll, i - 2)] - i);
			while(SZ(S) > 0 && pre[i] - *S.rbegin() < 0) {
				S.erase(S.find(pre[ptr - 1]));
				S2.erase(S2.find(dp[max(0ll, ptr - 2)] - ptr));
				ptr++;
			}
			// printf("[%lld %lld]\n", ptr, i);
			if(SZ(S2) > 0) dp[i] = *S2.rbegin() + i + 1;
			if(ptr == 1) dp[i] = max(dp[i], i);
			dp[i] = max(dp[i], dp[i - 1]);
			// printf("%lld\n", dp[i]);
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}