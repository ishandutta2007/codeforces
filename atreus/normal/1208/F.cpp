#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6 + 10;
const int MAXN = (1 << 21) + 10;

int a[maxn], dp[MAXN], b[MAXN];
pii p[MAXN];

pii merge(pii fi, pii se){
	if (fi.second < se.second)
		swap(fi, se);
	return {max(fi.first, se.second), fi.second};
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	int m = 21;
	for (int mask = 0; mask < (1 << m); mask++)
		p[mask] = {-1, -1};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		p[a[i]] = merge(p[a[i]], {-1, i});
	}
	for (int i = 0; i < m; i++)
		for (int mask = 0; mask < (1 << m); mask++)
			if (!(mask & (1 << i)))
				p[mask] = merge(p[mask], p[mask ^ (1 << i)]);
	for (int mask = 0; mask < (1 << m); mask++)
		b[mask] = p[mask].first;
	for (int mask = (1 << m) - 1; mask >= 0; mask--){
		dp[mask] = b[mask];
		for (int i = 0; i < m; i++)
			if (!(mask & (1 << i)))
				dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
	}
	int answer = 0;
	for (int i = 1; i <= n - 2; i++){
		int mask = (1 << m) - 1;
		mask ^= a[i];
		for (int j = m - 1; b[mask] <= i and j >= 0; j--){
			if (!(mask & (1 << j)))
				continue;
			int newmask = ((1 << m) - 1) ^ ((1 << j) - 1);
			int now = mask & newmask;
			if (dp[now] > i)
				continue;
			mask ^= (1 << j);
		}
		answer = max(answer, a[i] | mask);
	}
	cout << answer << endl;
}