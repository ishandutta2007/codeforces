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
 
int n;
ll ans;
map<ll, ll> mt;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d", &x);
		y = x - i;
		mt[y] += x;
		ans = max(ans, mt[y]);
	}
	printf("%lld", ans);
}