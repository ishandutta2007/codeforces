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
int T, n;
ll a[114];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		int cnt = 0;
		rep(i, 1, n) {
			while(a[i] % 2 == 0) a[i] /= 2, cnt++;
		}
		sort(a + 1, a + n + 1);
		a[n] *= (1ll << cnt);
		ll sum = 0;
		rep(i, 1, n) sum += a[i];
		printf("%lld\n", sum);
	}
	return 0;
}