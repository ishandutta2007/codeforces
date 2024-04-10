/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
// 0 is right direction
// 1 is left direction
int n, pos[maxn];
pair<int, int> x[maxn];

int dis(int fi, int se){
	return abs(x[fi].first - x[se].first);
}

int nex(int idx, int len, bool direction){
	if (direction == 0){
		int lo = idx, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (dis(idx, mid) <= len)
				lo = mid;
			else
				hi = mid;
		}
		return lo;
	}
	int lo = 0, hi = idx;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (dis(idx, mid) <= len)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int findans(int idx, int len, bool direction){
	int next_one = nex(idx, len, direction);
	if (next_one == idx)
		return x[idx].second;
	int Distance = dis(idx, next_one);
	if ((len / Distance) & 1)
		return findans(next_one, len % Distance, direction ^ 1);
	return findans(idx, len % Distance, direction);
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> x[i].first;
		x[i].second = i;
	}
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++)
		pos[x[i].second] = i;
	for (int i = 0; i < m; i++){
		int idx, l;
		cin >> idx >> l;
		idx = pos[idx];
		int next_one = nex(idx, l, 0);
		cout << findans(next_one, l - dis(idx, next_one), 1) << '\n';
	}
}