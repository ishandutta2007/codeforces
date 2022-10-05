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

int n, m, a[N];
ll ans[N];
void upd(int l, int r, int k){                
	if(l <= r)
		ans[l] += k, ans[r + 1] -= k;		
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for(int i = 2; i <= m; i++){
		int x = a[i - 1], y = a[i];
		if(x == y)
			continue;
		if(x > y)
			swap(x, y);      
		
		upd(1, x - 1, y - x);
		upd(x, x, y - 1);
		upd(x + 1, y - 1, y - x - 1);
		upd(y, y, x);
		upd(y + 1, n, y - x);
	}
	for(int i = 1; i <= n; i++){
		ans[i] += ans[i - 1];
		printf("%lld ", ans[i]);
	}
		
	return 0;
}