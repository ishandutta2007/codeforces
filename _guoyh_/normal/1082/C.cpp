# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const ll NR = 100051;
struct Node{
	ll nm, id;
} b[NR];
ll n, m, ans;
ll c[NR];
vector <ll> a[NR];
vector <ll> d[NR];
ll mx[NR];
bool cmp(Node x, Node y){
	return x.nm > y.nm;
}
bool cmp2(ll x, ll y){
	return x > y;
}
int main(){
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++){
		ll s, r;
		scanf("%lld%lld", &s, &r);
		a[s].push_back(r);
		b[s].nm++;
	}
	for (ll i = 1; i <= m; i++) b[i].id = i;
	sort(b + 1, b + m + 1, cmp);
	for (ll i = 1; i <= m; i++) c[b[i].id] = i;
	for (ll i = 1; i <= m; i++){
		ll sz = a[b[i].id].size();
		sort(a[b[i].id].begin(), a[b[i].id].end(), cmp2);
		ll s = 0;
		for (ll j = 0; j < sz; j++){
			s += a[b[i].id][j];
			d[i].push_back(mx[j] + s);
			ans = max(ans, d[i][j]);
			mx[j] = max(mx[j], d[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}