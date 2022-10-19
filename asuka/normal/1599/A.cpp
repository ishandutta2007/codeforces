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
int n, a[N];
char s[N];
vector<pii> ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	scanf("%s", s + 1);
	sort(a + 1, a + n + 1);
	int lp = 1, rp = n;
	rep(i, 1, n) if(i == 1 || s[i] != s[i - 1]) rp--;
	lp = rp ++;
	bool flag = 0;
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while(r < n && s[r + 1] == s[l]) r++;
		int len = r - l + 1;
		ans.pb(mp(a[rp++], s[l] == 'R'));
		rep(_, 1, len - 1) {
			ans.pb(mp(a[lp--], (s[1] == 'L') ^ flag));
			flag ^= 1;
		}
	}
	for(auto x : ans) {
		printf("%d %c\n", x.fi, x.se == 0 ? 'L' : 'R');
	}
	return 0;
}