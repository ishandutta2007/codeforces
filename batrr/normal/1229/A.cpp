#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector<int > g[N];
int n;
pll a[N];
ll ans, cur;
int col[N], good[N];
void dfs(int v){
	if(col[v] == 2)
		return;
	col[v] = 1;
	good[v] = 0;
	for(auto to : g[v]){
		if(col[to] == 1)
			good[v] = 1;
		else if(col[to] == 0)
			dfs(to);
		good[v] |= good[to];
	}
	if(good[v])
		ans += a[v].s;
	col[v]= 2;
}
int main()
{
	cin >> n;         
	for(int i = 1; i <= n; i++)
		cin >> a[i].f;
	for(int i = 1; i <= n; i++)
		cin >> a[i].s;
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			if(i != j && (a[j].f | a[i].f) == a[i].f)
				g[j].pb(i);
	}
	for(int i = 1; i <= n; i++){
		if(col[i] == 2)
			continue;
		dfs(i);
	}
	cout << ans;
	return 0;
}