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
int t, cnt[2601], n;
char s[N];
string ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--){
		ans.clear();
		scanf("%s", s + 1);
		n = strlen(s + 1);
		rep(i, 0, 25) cnt[i] = 0;
		rep(i, 1, n) cnt[s[i] - 'a'] ++;
		int Min = inf;
		rep(i, 0, 25) if(cnt[i] > 0) Min = min(cnt[i], Min);
		if(Min == 1) {
			int pos = 0;
			rep(i, 0, 25) if(cnt[i] == 1) {
				pos = i;
				cnt[i]--;
				break;
			}
			ans += 'a' + pos;
			rep(i, 0, 25) {
				rep(j, 1, cnt[i]) ans += 'a' + i;
			}
		} else {
			int st = 0;
			while(cnt[st] == 0) st++;
			if(cnt[st] - 2 <= n - cnt[st]) {
				ans += 'a' + st;
				ans += 'a' + st;
				cnt[st] -= 2;
				int nxt = st + 1;
				while(nxt < 26) {
					while(cnt[nxt] == 0 && nxt < 26) nxt++;
					if(cnt[nxt] > 0) ans += 'a' + nxt, cnt[nxt]--;
					if(cnt[st] > 0) ans += 'a' + st, cnt[st]--;
					else break;
					// printf("%d\n", nxt);
				}
				rep(i, 0, 25) rep(j, 1, cnt[i]) ans += 'a' + i;
			} else {
				int tot = 0;
				rep(i, 0, 25) if(cnt[i] > 0) tot++;
				if(tot == 1) {
					rep(i, 0, 25) rep(j, 1, cnt[i]) ans += 'a' + i;
				} else if(tot == 2) {
					int fst = 0;
					while(cnt[fst] == 0) fst++;
					int scd = fst + 1;
					while(cnt[scd] == 0) scd++;
					ans += 'a' + fst; cnt[fst]--;
					rep(i, 1, cnt[scd]) ans += 'a' + scd;
					rep(i, 1, cnt[fst]) ans += 'a' + fst;
				} else {
					int fst = 0;
					while(cnt[fst] == 0) fst++;
					int scd = fst + 1;
					while(cnt[scd] == 0) scd++;
					int thd = scd + 1;
					while(cnt[thd] == 0) thd++;
					ans += 'a' + fst; cnt[fst]--;
					ans += 'a' + scd; cnt[scd]--;
					rep(i, 1, cnt[fst]) ans += 'a' + fst;
					cnt[fst] = 0;
					ans += 'a' + thd; cnt[thd]--;
					rep(i, 0, 25) rep(j, 1, cnt[i]) ans += 'a' + i;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}