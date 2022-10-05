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

int n, ans;
vector< ll > v[N];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		ll x, y, cur = 0;
		scanf("%lld", &x);
		y = x;
		while(x % 2 == 0)
			cur++, x /= 2;
		v[cur].pb(y);
	}
	for(int i = 0; i < N; i++)
		if(v[ans].size() < v[i].size())
			ans = i;
	printf("%d\n", n - v[ans].size());
	for(int i = 0; i < N; i++){
		if(ans != i){
			for(auto it : v[i])
				printf("%lld ", it);
		}
	}
	return 0;
}