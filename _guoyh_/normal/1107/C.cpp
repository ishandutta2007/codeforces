# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
priority_queue <ll> q;
int n, k;
ll a[NR];
char s[NR];
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	ll ans = 0;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++){
		if (s[i] != s[i - 1]){
			while (!q.empty()){
				ans += -q.top();
				q.pop();
			}
			q.push(-a[i]);
		} else {
			if (q.size() < k) q.push(-a[i]);
			else if (-q.top() < a[i]){
				q.pop();
				q.push(-a[i]);
			}
		}
	}
	while (!q.empty()){
		ans += -q.top();
		q.pop();
	}
	printf("%lld\n", ans);
	return 0;
}