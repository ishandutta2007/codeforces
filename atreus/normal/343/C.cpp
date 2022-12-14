#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;

int n, m;
ll h[maxn], p[maxm];

ll dis(ll now, ll L, ll R){
	return min(abs(now - L) + R - L, abs(now - R) + R - L);
}

bool check(ll mid){
	int last = 1, ptr = 0;
	for (int i = 1; i <= n; i++){
		while (ptr < m and dis(h[i], p[last], p[ptr + 1]) <= mid)
			ptr ++;
		if (ptr == m)
			return 1;
		last = ptr + 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= m; i++)
		cin >> p[i];

	ll lo = -1, hi = 20ll * 1000 * 1000 * 1000 + 1;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
}