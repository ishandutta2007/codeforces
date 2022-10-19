#include<bits/stdc++.h>
#define ll long long
#define N 500015
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
int n, d, s[N], a[N], ord[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &d);
	rep(i, 1, n) scanf("%d%d", &s[i], &a[i]);
	rep(i, 1, n) ord[i] = i;
	sort(ord + 1, ord + n + 1, [&](int u, int v) {
		bool f1 = s[u] < a[u], f2 = s[v] < a[v];
		if(f1 == f2) {
			if(f1) return a[u] != a[v] ? a[u] < a[v] : s[u] < s[v];
			return s[u] != s[v] ? s[u] < s[v] : a[u] < a[v];
		}
		if(f1) return a[u] != s[v] ? a[u] < s[v] : s[u] < a[v];
		else return s[u] != a[v] ? s[u] < a[v] : a[u] < s[v];
	});
	int ans = 0;
	rep(i, 1, n) {
		int u = ord[i];
		if(s[u] >= d) {
			ans++;
			d = max(d, a[u]);
		}
	}
	printf("%d\n", ans);
	return 0;
}