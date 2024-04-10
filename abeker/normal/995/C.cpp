#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
int x[MAXN], y[MAXN];
set <int> S;
pii who[MAXN];
int dp[MAXN];

ll norm(ll cx, ll cy) {
	return cx * cx + cy * cy;
}

int rec(int x) {
	if (dp[x])
		return dp[x];
	return dp[x] = rec(who[x].first) * who[x].second;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", x + i, y + i);	
	
	for (int i = 0; i < N; i++)
		S.insert(i);
	
	int curr = N;
	while (S.size() >= 4) {
		auto it = S.begin();
		vector <int> tmp;
		for (int i = 0; i < 4; i++) {
			tmp.push_back(*it);
			it++;
		}
		
		int a = -1, b = -1;
		int c = 0, d = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < i; j++)
				for (int k = -1; k <= 1; k += 2)
					for (int l = -1; l <= 1; l += 2)
						if (norm(k * x[tmp[i]] + l * x[tmp[j]], k * y[tmp[i]] + l * y[tmp[j]]) <= 1e12) {
							a = tmp[i];
							b = tmp[j];
							c = k;
							d = l;
						}
		
		assert(a != -1 && b != -1);
		
		who[a] = {curr, c};
		who[b] = {curr, d};
		x[curr] = c * x[a] + d * x[b];
		y[curr] = c * y[a] + d * y[b];
		S.erase(a);
		S.erase(b);
		S.insert(curr++);
	}
	
	vector <int> rest;
	for (auto it : S)
		rest.push_back(it);
	
	int sz = rest.size();
	for (int i = 0; i < 1 << sz; i++) {
		int cx = 0, cy = 0;
		for (int j = 0; j < sz; j++)
			if (i >> j & 1) {
				cx += x[rest[j]];
				cy += y[rest[j]];
			}
			else {
				cx -= x[rest[j]];
				cy -= y[rest[j]];
			}
		if (norm(cx, cy) <= 2.25e12) {
			for (int j = 0; j < sz; j++)
				dp[rest[j]] = (i >> j & 1) ? 1 : -1;
			break;
		}
	}
	
	for (int i = 0; i < N; i++)
		printf("%d ", rec(i));
	puts("");
	
	ll cx = 0, cy = 0;
	for (int i = 0; i < N; i++) {
		cx += dp[i] * x[i];
		cy += dp[i] * y[i];
	}
	
	assert(norm(cx, cy) <= 2.25e12);
	
	return 0;
}