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
int t, n, cnt[26];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		rep(i, 0, 25) cnt[i] = 0;
		rep(i, 1, n) cnt[s[i] - 'a'] ++;
		int ans, tot;
		ans = tot = 0;
		rep(i, 0, 25) {
			if(cnt[i] >= 2) {
				ans++;
			} else {
				tot += cnt[i];
			}
		}
		ans += (tot / 2);
		printf("%d\n", ans);
	}
	return 0;
}