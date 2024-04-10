#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 10;
const ll INF = 2e18;

int n, last;
ll dp[N], tmp[N];
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		last = -1000;
		for(int i = 0; i < N; i++)
			dp[i] = 0;
		while(n--){
			int a, b;
			scanf("%d%d", &a, &b);
			for(int i = 0; i < N; i++)
				tmp[i] = INF;
		    for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					if(last + i != a + j)
                    	tmp[j] = min(tmp[j], dp[i] + 1ll * j * b);
			for(int i = 0; i < N; i++)
				dp[i] = tmp[i];
			last = a;
		}
		ll ans = INF;
		for(int i = 0; i < N; i++)
			ans = min(ans, dp[i]);
		printf("%lld\n", ans);
	}
	return 0;
}