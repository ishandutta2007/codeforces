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
const int mod = 998244353;
int n, x[N], y[N], s[N], f[N], sum[N];
void inc(int &x, int y) {
	x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d%d", &x[i], &y[i], &s[i]);
	rep(i, 1, n) {
		int pos = lower_bound(x + 1, x + n + 1, y[i]) - x;
		inc(f[i], x[i]);
		inc(f[i], mod - y[i]);
		inc(f[i], sum[i - 1]);
		inc(f[i], mod - sum[pos - 1]);
		sum[i] = sum[i - 1];
		inc(sum[i], f[i]);
	}
	int ans = 1;
	rep(i, 1, n) {
		if(s[i]) inc(ans, f[i]);
		inc(ans, x[i]);
		inc(ans, mod - x[i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}