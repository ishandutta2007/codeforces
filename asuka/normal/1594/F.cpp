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
int T;
ll s, n, k;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld", &s, &n, &k);
		ll cnt;
		if(s % k == 0) {
			if((s / k) & 1) {
			    cnt = (s / k + 1) / 2 * k;
			} else cnt = (s / k) / 2 * k + 1;
		} else {
			ll tmp = (s % k) + 1;
			cnt = tmp * ((s / k + 2) / 2) + (k - tmp) * ((s / k + 1) / 2);
		}
		cnt--;
		if(n > cnt || s == k) puts("YES");
		else puts("NO");
	}
	return 0;
}