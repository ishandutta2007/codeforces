#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 35;

int N, L;
int cost[MAXN];
vector <int> good;

int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++)
		scanf("%d", cost + i);	
		
	for (int i = 0; i < N; i++) {
		bool ok = true;
		for (int j = 0; j < i; j++)
			ok &= cost[i] < (ll)(1 << i - j) * cost[j];
		if (ok)	
			good.push_back(i);
	}
	
	reverse(good.begin(), good.end());
	
	ll sol = 1ll << 60;
	ll curr = 0;	
	for (auto it : good) {
		int tmp = 1 << it;
		sol = min(sol, curr + (ll)(L + tmp - 1) / tmp * cost[it]);
		curr += (ll)L / tmp * cost[it];
		L %= tmp;
	}
	
	printf("%lld\n", sol);
	
	return 0;
}