# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const ll MAXN = 200051;
struct Edge{
	ll u, nxt;
} l[MAXN];
ll t, n, lsz, ans1, ans2;
ll a[MAXN], b[MAXN];
ll ftl[MAXN];
priority_queue <ll> q;
void addl(ll x, ll y){
	l[++lsz] = (Edge){y, ftl[x]};
	ftl[x] = lsz;
}
int main(){
	scanf("%lld", &t);
	while (t--){
		while (!q.empty()) q.pop();
		ans1 = ans2 = 0;
		scanf("%lld", &n);
		for (ll i = 1; i <= n; i++) a[i] = b[i] = ftl[i] = 0;
		for (ll i = 1; i <= n; i++){
			ll u, v;
			scanf("%lld%lld", &u, &v);
			if (v == 0) a[u]++;
			else b[u]++;
		}
		for (ll i = 1; i <= n; i++){
			addl(a[i] + b[i], b[i]);
			// printf("iab %lld %lld %lld\n", i, a[i], b[i]);
		}
		for (ll i = n; i >= 1; i--){
			for (ll j = ftl[i]; j; j = l[j].nxt) q.push(l[j].u);
			if (!q.empty()){
				ans1 += i;
				ans2 += min(i, q.top());
				q.pop();
			}
		}
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}