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
 
int n, m, k, a[N], ans;
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	k = min(k, m - 1);
	ans = 0;
	for(int i = 0; i <= k; i++){
		int l = i;
		int r = n - 1 - (k - i);
		int lst = m - k - 1;
		int cur = inf;
		for(int j = 0; j <= lst; j++)
			cur = min(cur, max(a[l + j], a[r - (lst - j)]));
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}