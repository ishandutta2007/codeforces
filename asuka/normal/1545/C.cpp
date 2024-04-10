#include<bits/stdc++.h>
#define ll long long
#define N 505
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
const int mod = 998244353;
int T, n, a[N << 1][N], cnt[N][N], del[N << 1], chosen[N << 1];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) rep(j, 1, n) cnt[i][j] = 0;
		rep(i, 1, n * 2) del[i] = chosen[i] = 0;
		rep(i, 1, n * 2) {
			rep(j, 1, n) scanf("%d", &a[i][j]), cnt[j][a[i][j]]++;
		}
		int cur = 0, ans = 1;
		while(cur < n) {
			int pos = -1;
			rep(i, 1, n * 2) {
				if(del[i] || chosen[i]) continue;
				rep(j, 1, n) {
					if(cnt[j][a[i][j]] == 1) {
						pos = i;
						break;
					}
				}
				if(~pos) break;
			}
			if(pos == -1) {
				ans = ans * 2 % mod;
				rep(i, 1, n * 2) {
					if(del[i] || chosen[i]) continue;
					pos = i;
					break;
				}
			}
			if(pos != -1) {
				// printf("POS: %d\n", pos);
				chosen[pos] = 1;
				rep(i, 1, n * 2) {
					if(del[i] || i == pos) continue;
					bool flag = 0;
					rep(j, 1, n) if(a[i][j] == a[pos][j]) flag = 1;
					if(flag) {
						// printf("DEL %d\n", i);
						del[i] = 1; cur++;
						rep(j, 1, n) cnt[j][a[i][j]]--;
					}
				}
			}
			
		}
		printf("%d\n", ans);
		rep(i, 1, n * 2) if(!del[i]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}
/*
3
7
1 2 3 4 5 6 7
2 3 4 5 6 7 1
3 4 5 6 7 1 2
4 5 6 7 1 2 3
5 6 7 1 2 3 4
6 7 1 2 3 4 5
7 1 2 3 4 5 6
1 2 3 4 5 7 6
1 3 4 5 6 7 2
1 4 5 6 7 3 2
1 5 6 7 4 2 3
1 6 7 5 2 3 4
1 7 6 2 3 4 5
1 7 2 3 4 5 6
5
4 5 1 2 3
3 5 2 4 1
1 2 3 4 5
5 2 4 1 3
3 4 5 1 2
2 3 4 5 1
1 3 5 2 4
4 1 3 5 2
2 4 1 3 5
5 1 2 3 4
6
2 3 4 5 6 1
3 1 2 6 4 5
6 1 2 3 4 5
5 6 1 3 2 4
4 3 6 5 2 1
5 6 1 2 3 4
4 5 6 1 2 3
3 4 5 6 1 2
1 2 3 4 5 6
2 5 4 1 6 3
3 2 5 4 1 6
1 4 3 6 5 2
*/