# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int P = 998244353;
int t, n;
ll a[MAXN], s[MAXN], s1[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%lld", a + i);
			s[i] = s[i - 1] + a[i];
			if (i <= 2) s1[i] = a[i];
			else s1[i] = s1[i - 2] + a[i];
		}
		ll fnl = 0;
		for (int ss = 0; ss < 4; ss++){
			for (int i = (ss & 1) ? 3 : 0; i <= n; i++){
				if ((ss & 2) && i > n - 3) break;
				ll nw = s[n] - 2 * s[i];
				if (ss & 1) nw += 2 * a[1];
				if (ss & 2) nw -= 2 * a[n];
				// if (ss == 2 && i == 0) printf("nw %lld\n", nw);
				int lft = 0, rgt = (ss & 2) ? (n - 3 - i) / 2 : (n - i) / 2, ans = -1;
				while (lft <= rgt){
					int mid = (lft + rgt) >> 1;
					if (nw - 2 * (s1[i + mid * 2] - s1[i]) > 0){
						ans = mid;
						lft = mid + 1;
					} else rgt = mid - 1;
				}
				fnl += ans + 1;
			}
		}
		for (int i = 2; i <= n - 2; i++) if (s[i] > s[n] - s[i]) fnl++;
		printf("%lld\n", fnl % P);
	}
	return 0;
}