#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 500500;
 
int t, n, m, p[N], cnt[N];
ll a[N];
pair< pll, pll > h[N], val[N];
bool cmp(int i, int j){
	return h[i] < h[j];
}
int main()
{
	for(int i = 0; i < N; i++){
		val[i].f.f = rand() + 1;
		val[i].f.s = rand() + 1;
		val[i].s.f = rand() + 1;
		val[i].f.s = rand() + 1;
	}
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			p[i] = i;
			cnt[i] = 0;
			h[i].f.f = 0;
			h[i].f.s = 0;
			h[i].s.f = 0;
			h[i].s.s = 0;
		}
		for(int i = 0; i < m; i++){
			int v, u;
			scanf("%d%d", &v, &u);             
			cnt[u]++;
			h[u].f.f = (h[u].f.f + val[v].f.f);
			h[u].f.s = (h[u].f.s + val[v].f.s);
			h[u].s.f = (h[u].s.f + val[v].s.f);
			h[u].s.s = (h[u].s.s + val[v].s.s);
		}
		for(int i = 1; i <= n; i++)
			if(cnt[i] == 0)
				a[i] = 0;
		sort(p + 1, p + 1 + n, cmp);
		ll g = 0;
		for(int i = 1, j = 1; i <= n; i = j){
			ll s = 0;
			while(j <= n && h[p[i]] == h[p[j]])
				s += a[p[j]], j++;
			g = __gcd(g, s);
		}
		printf("%lld\n", g);
	}
}