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
int t, a, n, b, ans[200015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &a, &b);
		if(a + b > n - 2 || abs(a - b) > 1) {
			puts("-1");
			continue;
		}
		int p = 1, q = 0, tot = 0;
		if(a >= b) {
			ans[++tot] = p++;
			rep(i, 1, n - 1) {
				if(i <= a + b) {
					if(i & 1) ans[++tot] = p++;
					else ans[++tot] = q--;
				} else {
					if((a + b) & 1) ans[++tot] = q--;
					else ans[++tot] = p++;
				}
			}
		} else {
			ans[++tot] = p++;
			rep(i, 1, n - 1) {
				if(i <= a + b) {
					if(!(i & 1)) ans[++tot] = p++;
					else ans[++tot] = q--;
				} else {
					if(!((a + b) & 1)) ans[++tot] = q--;
					else ans[++tot] = p++;
				}
			}
		}
		int o = *min_element(ans + 1, ans + n + 1);
		rep(i, 1, n) printf("%d ", ans[i] - o + 1);
		printf("\n");
	}
	return 0;
}