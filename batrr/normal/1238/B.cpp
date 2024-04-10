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

int n, x, a[N];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int ans = 0;
		int last = inf, shift = 0;
		for(int i = n - 1; i >= 0; i--)
			if(last != a[i] && a[i] - shift > 0)
				ans++, last = a[i], shift  += x;
		printf("%d\n", ans);
	}
	return 0;
}