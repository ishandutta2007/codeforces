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
const int N = 200015, mod = 998244353;
int n, a[N], dp[N];
vector<pii> stk; // (\sum_j (-1)^{j-1}dp_j, a[*])
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	dp[0] = 1;
	stk.emplace_back(mod - 1, a[1]);
	int sum = (ll) (mod - 1) * a[1] % mod;
	rep(i, 1, n) {
		dp[i] = (i & 1 ? mod - sum : sum) % mod;
		int val = (i & 1 ? dp[i] : (mod - dp[i])) % mod;
		if(i < n) {
			while(SZ(stk) && stk.back().se > a[i + 1]) {
				int u, v; tie(u, v) = stk.back(); stk.pop_back();
				(val += u) %= mod;
				(sum += mod - ((ll) u * v % mod)) %= mod;
			}
		}
		(sum += (ll) val * a[i + 1] % mod) %= mod;
		stk.emplace_back(val, a[i + 1]);
	}
	printf("%d\n", dp[n]);
	return 0;
}