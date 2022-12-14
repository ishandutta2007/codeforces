#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 2e5 + 10;

ll g[maxn];

bool check(int n, int x, int t){
	ll time = 0;
	for (int i = 1; i <= n; i++){
		if (g[i] > x)
			return 0;
		ll now = 2ll * g[i];
		if (g[i] * 2 <= x){
			time += g[i];
			continue;
		}
		ll rem = x - g[i];
		time += 2ll * g[i] - rem;
	}
	return time <= t;
}

pair<int, int> car[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, s, t;
	cin >> n >> k >> s >> t;
	for (int i = 1; i <= n; i++)
		cin >> car[i].first >> car[i].second;
	for (int i = 1; i <= k; i++)
		cin >> g[i];
	sort(g + 1, g + k + 1);
	g[k + 1] = s;
	for (int i = k + 1; i >= 1; i--)
		g[i] = g[i] - g[i - 1];
	k ++;
	
	if (s > t)
		return cout << -1 << endl, 0;
	int lo = 0, hi = 2 * s;
	while (hi - lo > 1){
		int mid = (1ll * lo + hi) >> 1;
		if (check(k, mid, t))
			hi = mid;
		else
			lo = mid;
	}
	int answer = -1;
	for (int i = 1; i <= n; i++)
		if (car[i].second >= hi)
			if (answer == -1 or answer > car[i].first)
				answer = car[i].first;
	cout << answer << endl;
}