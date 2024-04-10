# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n, cnt;
int a[MAXN];
char s[MAXN];
int work(int nm){
	ll lft = 2, rgt = 100000, ans = 1;
	while (lft <= rgt){
		ll mid = (lft + rgt) >> 1;
		if (mid * (mid - 1) / 2 <= nm){
			ans = mid;
			lft = mid + 1;
		} else rgt = mid - 1;
	}
	return ans;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		cnt = 0;
		while (n > 0){
			a[++cnt] = work(n);
			n -= a[cnt] * (a[cnt] - 1) / 2;
		}
		memset(s, '3', sizeof(s));
		s[1] = '1';
		for (int i = 1; i <= cnt; i++){
			s[a[cnt - i + 1] + i + 1] = '7';
		}
		s[a[1] + cnt + 2] = 0;
		printf("%s\n", s + 1);
	}
	return 0;
}