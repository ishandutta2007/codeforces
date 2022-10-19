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
int t, n, m, k, ans[105][105];
char res[105][105];
bool solve() {
	if((n * m / 2 % 2) != (k % 2)) return 0;
	int mm = m % 2 == 1 ? m - 1 : m;
	int lef = (n * m / 2) - (n * mm / 2);
	if(k < lef) return 0;
	k -= lef;
	for(int i = 1; i <= n; i += 2) {
		for(int j = 1; j <= m; j += 2) {
			if(j == m) ans[i][j] = 1;
			else if(k > 0) ans[i][j] = 1, k -= 2;
			else ans[i][j] = 2;
		}
	}
	for(int i = 1; i <= n; i += 2) {
		for(int j = 1; j <= m; j += 2) {
			char ch[2];
			if(((i + j) % 4) == 2) ch[0] = 'a', ch[1] = 'b';
			else ch[0] = 'c', ch[1] = 'd';
			if(ans[i][j] == 1) {
				res[i][j] = res[i + 1][j] = ch[0];
				res[i][j + 1] = res[i + 1][j + 1] = ch[1];
			} else {
				res[i][j] = res[i][j + 1] = ch[0];
				res[i + 1][j] = res[i + 1][j + 1] = ch[1];
			}
		}
	}
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &k);
		bool flag = 0;
		if(n % 2 == 1) {
			flag = 1;
			swap(n, m);
		} else {
			k = n * m / 2 - k;
		}
		if(solve()) {
			puts("YES");
			// if(flag) {
			// 	rep(j, 1, m) {
			// 		rep(i, 1, n) {
			// 			printf("%c", res[i][j]);
			// 		}
			// 		printf("\n");
			// 	}
			// } else {
			// 	rep(i, 1, n) {
			// 		rep(j, 1, m) {
			// 			printf("%c", res[i][j]);
			// 		}
			// 		printf("\n");
			// 	}
			// }
		} else {
			puts("NO");
		}
	}
	return 0;
}