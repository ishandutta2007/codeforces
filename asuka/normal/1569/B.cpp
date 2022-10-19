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
int T, n, s[1005], ans[105][105];
char str[1005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		// int tot = 0;
		VI vec;
		scanf("%s", str + 1);
		rep(i, 1, n) s[i] = str[i] - '0';
		rep(i, 1, n) {
			// scanf("%d", &s[i]);
			if(s[i] == 2) vec.pb(i);
		}
		if(0 < SZ(vec) && SZ(vec) <= 2) {
			puts("NO");
			continue;
		}
		rep(i, 1, n) rep(j, 1, n) ans[i][j] = -1;
		rep(i, 0, SZ(vec) - 1) {
			int cur = vec[i], nxt = vec[(i + 1) % SZ(vec)];
			ans[cur][nxt] = 1;
			ans[nxt][cur] = 0;
		}
		rep(i, 1, n) rep(j, 1, n) {
			if(s[i] == 1 && s[j] == 1) ans[i][j] = ans[j][i] = 2;
			else if(s[i] == 1 && s[j] == 2) ans[i][j] = 1, ans[j][i] = 0;
			else if(s[i] == 2 && s[j] == 2) {
				if(ans[i][j] == -1 && ans[j][i] == -1) {
					ans[i][j] = ans[j][i] = 2;
				}
			}
		}
		puts("YES");
		rep(i, 1, n) {
			rep(j, 1, n) {
				if(i == j) putchar('X');
				else if(ans[i][j] == 0) putchar('-');
				else if(ans[i][j] == 1) putchar('+');
				else putchar('=');
			}
			printf("\n");
		}
	}
	return 0;
}