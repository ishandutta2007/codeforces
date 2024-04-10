#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int k = 1e9 + 7;

vector< ll > v[10];
ll n, b[1 << 10], p[10], a[10], i, j, m, X, M;
unordered_map<ll, ll> dp[10];
int main()
{
	cin >> n;
	for(i = 0, j; i < (1 << n); i++){
		j = __builtin_popcount(i);
		b[i] = v[j].size();
		v[j].pb(i);
	}
	dp[0][1] = 1;	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cin >> p[j];
			p[j] = p[j] * 570000004 % k;
		}
		for(auto it : dp[i]){
			for(j = 0; j < n; j++)
				a[j] = 0;
			for(auto m : v[i])
				if((it.f >> b[m]) & 1)
					for(j = 0; j < n; j++)
						if(((m >> j) & 1) == 0)
							a[j] |= (1ll << b[m | (1 << j)]);
			for(m = 0; m < (1 << n); m++){
				X = 1, M = 0;
				for(j = 0; j < n; j++)
					if((m >> j) & 1)
						M |= a[j], X = X * p[j] % k;
					else
						X = X * (1 - p[j] + k) % k;										
				dp[i + 1][M] = (dp[i + 1][M] + it.s * X) % k;
			}
		}
	}
	cout << dp[n][1];
	return 0;
}