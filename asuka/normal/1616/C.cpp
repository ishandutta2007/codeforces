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
int T, n, a[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int ans = max(0, n - 2);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(l, 1, n) rep(r, l + 1, n) {
			int cur = n - 2;
			rep(i, 1, n) if(i ^ l && i ^ r) {
				if((a[i] - a[l]) * (i - r) == (a[i] - a[r]) * (i - l)) cur--;
			}
			ans = min(ans, cur);
		}
		printf("%d\n", ans);
	}
	return 0;
}