#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], dp[N], l[N], id[N];
map<int, int> mt[N];

int get(int pos, int val){
	pos--;
	if(pos <= 0)
		return -1;
	if(id[pos] != -1 && mt[id[pos]].count(val))
		return mt[id[pos]][val];
	return -1;
}
void solve(){
	ll ans = 0;
	scanf("%d", &n);
	
	for(int i = 0; i <= n; i++)
		mt[i].clear(), dp[i] = 0;
    id[0] = 0;

    for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		l[i] = get(i, a[i]);
		if(l[i] == -1)
			id[i] = i;          
		else
			id[i] = id[l[i] - 1];
        mt[id[i]][a[i]] = i;
		if(l[i] != -1)
			dp[i] = dp[l[i] - 1] + 1;
		ans += dp[i];
	}
	printf("%lld\n", ans);
}
int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
		solve();
	return 0;
}