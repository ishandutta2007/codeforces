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
const int N = 300015;
ll x;
int n, a[N], pre[N];
ll ans;
void solve(int l, int r, int c) {
	if(l > r || c < 0) return;
	int lst = l - 1, ptr = l - 1, cnt[2] = {0, 0};
	rep(i, l, r) {
		if(a[i] == c) {
			solve(lst + 1, i - 1, c - 1);
			lst = i;
		}
		while(ptr < lst && pre[i] - pre[ptr] >= 2 * c) cnt[pre[ptr++] & 1]++;
		ans += cnt[pre[i] & 1];
	}
	solve(lst + 1, r, c - 1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%lld", &x), a[i] = __builtin_popcountll(x);
	rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
	solve(1, n, 60);
	printf("%lld\n", ans);
	return 0;
}