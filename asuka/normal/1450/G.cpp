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
int n, a, b, l[26], r[26], p[5555], pre[26][5555], cnt[1 << 20], L[1 << 20], R[1 << 20];
bool dp[1 << 20];
char s[5555];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s + 1);
	memset(l, 0x3f, sizeof l);
	rep(i, 1, n) l[s[i] - 'a'] = min(l[s[i] - 'a'], i), r[s[i] - 'a'] = i;
	vector<char> vec;
	rep(i, 1, n) if(i == l[s[i] - 'a']) vec.pb(s[i]);
	sort(all(vec), [&](char u, char v) {
		return l[u - 'a'] < l[v - 'a'];
	});
	int m = SZ(vec);
	rep(i, 1, n) p[i] = lower_bound(all(vec), s[i], [&](char u, char v) {return l[u - 'a'] < l[v - 'a'];}) - vec.begin();
	rep(i, 1, n) cnt[1 << p[i]]++;
	rep(i, 0, m - 1) {
		L[1 << i] = l[vec[i] - 'a'];
		R[1 << i] = r[vec[i] - 'a'];
	}
	rep(mask, 0, (1 << m) - 1) {
		if(__builtin_popcount(mask) <= 1) continue;
		int o =	lowbit(mask);
		L[mask] = min(L[mask ^ o], L[o]);
		R[mask] = max(R[mask ^ o], R[o]);
		cnt[mask] = cnt[mask ^ o] + cnt[o];
	}
	dp[0] = 1;
	rep(mask, 1, (1 << m) - 1) {
		int pre = 0;
		rep(i, 0, m - 1) {
			if(!(mask >> i & 1)) continue;
			pre |= 1 << i;
			if(a * (R[mask] - L[mask] + 1) <= b * cnt[mask]) dp[mask] |= dp[mask ^ (1 << i)];
			dp[mask] |= dp[mask ^ pre] & dp[pre];
		}
	}
	vector<char> res;
	rep(i, 0, m - 1) if(dp[((1 << m) - 1) ^ (1 << i)]) res.pb(vec[i]);
	sort(all(res));
	printf("%d ", SZ(res));
	for(auto ch : res) printf("%c ", ch);
	return 0;
}