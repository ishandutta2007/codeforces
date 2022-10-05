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
 
vector< int > v[N];
int n;
ll pw(ll x, ll p){
	ll res = 1;
	while(p--)
		res = res * x;
	return res;
}
int main()
{
	scanf("%d", &n);
	for(int j = 0; j < n; j++){	
		int x;
		scanf("%d", &x);
		for(int i = 2; i * i <= x; i++){
			int y = 0;
			while(x % i == 0)
				x /= i, y++;
			v[i].pb(y);
		}
		if(x > 1)
			v[x].pb(1);
	}
	ll ans = 1;
	for(int i = 1; i < N; i++){
		sort(v[i].begin(), v[i].end());
		if(v[i].size() == n)
			ans = ans * pw(i, v[i][1]);
		if(v[i].size() == n - 1)
			ans = ans * pw(i, v[i][0]);
	}
	printf("%lld", ans);
}