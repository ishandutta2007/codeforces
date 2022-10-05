#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, m, x[N], y[N];
ll ans[N], pre[N], sumy;
vector< int > a;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &x[i], &y[i]);
		a.pb(x[i] - y[i]);
		sumy += y[i];
	}
	sort(a.begin(), a.end());
	pre[0] = a[0];            
	for(int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];

	for(int i = 1; i <= n; i++){
		ans[i] = 1ll * y[i] * n  + sumy;
		int id = lower_bound(a.begin(), a.end(), x[i] - y[i]) - a.begin();
		ans[i] += 1ll * (n - id - 1) * (x[i] - y[i]) + pre[id];
		ans[i] -= x[i] + y[i];
	}
	for(int i = 1; i <= m; i++){
		int v, u;
		scanf("%d%d", &v, &u);                  
		ans[v] -= min(x[v] + y[u], x[u] + y[v]);
		ans[u] -= min(x[v] + y[u], x[u] + y[v]);
	}
	for(int i = 1; i <= n; i++)
		printf("%lld ",ans[i]);
	return 0;
}