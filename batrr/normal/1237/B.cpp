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

int n, ans, a[N], b[N], c[N], mn;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		c[b[i]] = i;
	}
	mn = 0;
	for(int i = 1; i <= n; i++){
		if(mn > c[a[i]])
			ans++;
		mn = max(mn, c[a[i]]);
	}
	printf("%d", ans);
			
	return 0;
}