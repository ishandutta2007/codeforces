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
int n;
char a[100015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s", a + 1);
		int ans = inf;
		rep(c, 0, 25) {
			int l = 1, r = n;
			int res = 0;
			while(l < r) {
				if(a[l] == a[r]) l++, r--;
				else {
					if(a[l] - 'a' == c) {
						l++;
						res++;
					} else if(a[r] - 'a' == c) {
						r--;
						res ++;
					} else {
						res = -1;
						break;
					}
				}
			}
			if(res != -1) ans = min(ans, res);
		}
		printf("%d\n", ans == inf ? -1 : ans);
	}
	return 0;
}