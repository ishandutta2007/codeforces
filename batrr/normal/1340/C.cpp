#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 10100, M = 1010;
const ll INF = 1e18;
 
int n, k, m, nk, r, g, a[N], dp[N][M], cur;
pii b[N * M], c[N * M];
bool was[N][M];


void f(int i, int j);
void ff(int i, int j, int x){
	if(dp[i][j] <= x)
		return;
	dp[i][j] = x;
	if(x == cur)
		b[k++] = {i, j};
	else
		f(i, j);
}
void f(int i, int j){
	if(was[i][j])
		return;
	was[i][j] = 1;
	if(i > 0){
		if(j + a[i] - a[i - 1] < g)
			ff(i - 1, j + a[i] - a[i - 1], dp[i][j]);
		if(j + a[i] - a[i - 1] == g)
			ff(i - 1, 0, dp[i][j] + 1);
	}
	if(i + 1 < m){
		if(j + a[i + 1] - a[i] < g)
			ff(i + 1, j + a[i + 1] - a[i], dp[i][j]);
		if(j + a[i + 1] - a[i] == g)
			ff(i + 1, 0, dp[i][j] + 1);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	scanf("%d%d", &g, &r);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < g; j++)
			dp[i][j] = 1e9;
	sort(a, a + m);
	ll ans = INF;
	ff(0, 0, 0);
	while(true){
		nk = 0;
		for(int i = 0; i < k; i++)
			if(dp[b[i].f][b[i].s] == cur)
            	c[nk++] = b[i];		
		if(nk == 0)
			break;		
		cur++;
		k = 0;
		for(int i = 0; i < nk; i++)
			f(c[i].f, c[i].s);
	}
	if(was[m - 1][0])
		ans = min(ans, 1ll * (r + g) * dp[m - 1][0] - r);			
	for(int i = 1; i < g; i++)
		if(was[m - 1][i])
			ans = min(ans, i + 1ll * (r + g) * dp[m - 1][i]);			
	if(ans == INF)
		ans = -1;
	printf("%lld", ans); 
}