# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
int n, m, ans;
ll a[NR], b[NR], s1[NR], s2[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		s1[i] = s1[i - 1] + a[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		scanf("%lld", b + i);
		s2[i] = s2[i - 1] + b[i];
	}
	if (s1[n] != s2[m]){
		printf("-1\n");
		return 0;
	}
	int la = 1, lb = 1;
	for (int ra = 1; ra <= n; ra++){
		ll nm = s1[ra] - s1[la - 1] + s2[lb - 1];
		int pos = lower_bound(s2 + lb, s2 + m + 1, nm) - s2;
		if (s2[pos] == nm){
			lb = pos + 1;
			la = ra + 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}