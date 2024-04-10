#include<bits/stdc++.h>
#define ll long long
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
int n, a[200015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n * 2) scanf("%d", &a[i]);
	sort(a + 1, a + n * 2 + 1);
	ll ans = (ll) (a[n] - a[1]) * (a[n * 2] - a[n + 1]);
	rep(i, 2, n) ans = min(ans, (ll) (a[n * 2] - a[1]) * (a[i + n - 1] - a[i]));	
	printf("%lld\n", ans);
	return 0;
}