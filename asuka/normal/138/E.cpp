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
const int N = 111111;
char s[N], tmp[5], c[N];
int sum, n, L, R, k, l[N], r[N], pl[N], pr[N], cnt[N], pre[26][N];
void chk(int x, int v) {if(L <= x && x <= R) sum += v;}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 1, n) rep(ch, 0, 25) pre[ch][i] += pre[ch][i - 1] + (s[i] - 'a' == ch);
	scanf("%d%d%d", &k, &L, &R);
	rep(i, 1, k) {
		scanf("%s%d%d", tmp + 1, &l[i], &r[i]);
		c[i] = tmp[1];
		pl[i] = 1; pr[i] = 0;
	}
	ll ans = 0;
	rep(i, 1, n) {
		chk(cnt[i], 1);
		rep(j, 1, k) {
			while(pr[j] + 1 <= i && pre[c[j] - 'a'][i] - pre[c[j] - 'a'][pr[j]] >= l[j]) {
				chk(cnt[++pr[j]], -1);
				chk(++cnt[pr[j]], 1);
			}
			while(pl[j] <= i && pre[c[j] - 'a'][i] - pre[c[j] - 'a'][pl[j] - 1] > r[j]) {
				if(pl[j]) {
					chk(cnt[pl[j]], -1);
					chk(--cnt[pl[j]++], 1);
				}
			}
			// printf("%d %d\n", pl[j], pr[j]);
		}
		// printf("sum: %d\n", sum);
		// rep(j ,1, n) printf("%d ", cnt[j]);
		// printf("\n");
		ans += sum;
	}
	printf("%lld\n", ans);
	return 0;
}