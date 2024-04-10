#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int k, n[3], lst[N][3], nxt[N][3];
pll a[N];
ll ans;
ll f(int i, int j, int k){
	if(i == -1 || j == -1 || k == -1)
		return INF;
	return a[i].f * a[i].f + a[j].f * a[j].f + a[k].f * a[k].f - a[i].f * a[j].f - a[i].f * a[k].f - a[j].f * a[k].f;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		k = 0;
		for(int i = 0; i < 3; i++)
			scanf("%d", &n[i]);
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n[i]; j++){
				int x;
				scanf("%d", &x);
				a[k++] = {x, i};
			}
	    sort(a, a + k);
	    for(int i = 0; i < k; i++){
			for(int j = 0; j < 3; j++)
				if(i == 0)
					lst[i][j] = -1;
				else
					lst[i][j] = lst[i - 1][j];
			lst[i][a[i].s] = i;
		}
        for(int i = k - 1; i >= 0; i--){
			for(int j = 0; j < 3; j++)
				if(i == k - 1)
					nxt[i][j] = -1;
				else
					nxt[i][j] = nxt[i + 1][j];
			nxt[i][a[i].s] = i;
		}
		ans = INF;
		for(int i = 1; i + 1 < k; i++){
			for(int j = 0; j < 3; j++){
				if(j == a[i].s)
					continue;
				int q = 3 ^ a[i].s ^ j;
				ans = min(ans, f(lst[i - 1][j], nxt[i + 1][q], i));
				ans = min(ans, f(lst[i - 1][q], nxt[i + 1][j], i));
			}
		}
		printf("%lld\n", ans * 2);
	}	
}