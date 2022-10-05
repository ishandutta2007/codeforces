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

vector< int > add[N], del[N];
int n, q, l[N], r[N], cnt[N], a[N], ans;
int main()
{
	for(int i = 0; i < N; i++)
		l[i] = inf, r[i] = -inf;

	scanf("%d%d", &n, &q);
	ans = n;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);       
		cnt[a[i]]++;
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
	}
	for(int i = 0; i < N; i++)
		if(l[i] <= r[i]){
			add[l[i]].pb(i);
			del[r[i]].pb(i);
		}   
	int mx = -inf, c = 0;
	for(int i = 0; i < n; i++){        
		for(auto j : add[i])
	 		c++, mx = max(mx, cnt[j]);
		for(auto j : del[i])
	 		c--, mx = max(mx, cnt[j]);
		if(c == 0 && mx != -inf)	
			ans -= mx, mx = -inf;
	}
	printf("%d", ans);
	return 0;
}