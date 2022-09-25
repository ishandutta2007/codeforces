#include<bits/stdc++.h>

using namespace std;

const int MX = 1000000;

map<int, vector<tuple<int, int, int>>> a;
map<int, int> coord;
int ans[MX], fwt[MX + 1], x[MX], q[MX];

int fwt_get(int x) {
	int res = 0;
	while (x) {
		res += fwt[x];
		x -= x & -x;
	}
	
	return res;
}

void fwt_add(int x, int d) {
	while (x <= MX) {
		fwt[x] += d;
		
		x += x & -x;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t, x;
		scanf("%d %d %d", q + i, &t, &x);
		
		a[x].push_back(make_tuple(q[i], t, i));
	}
	
	for (auto& f : a) {
		coord.clear();
		
		int k = 0;
		for (auto& g : f.second) x[k++] = get<1>(g);
		
		sort(x, x + k);
		for (int i = 0; i < k; i++) coord[x[i]] = i + 1;
		
		for (auto& g : f.second) {
			if (get<0>(g) == 1) fwt_add(coord[get<1>(g)], +1);
			else if (get<0>(g) == 2) fwt_add(coord[get<1>(g)], -1);
			else ans[get<2>(g)] = fwt_get(coord[get<1>(g)]);
		}
		
		for (auto& g : f.second) {
			if (get<0>(g) == 1) fwt_add(coord[get<1>(g)], -1);
			else if (get<0>(g) == 2) fwt_add(coord[get<1>(g)], +1);
		}
	}
	
	for (int i = 0; i < n; i++)
		if (q[i] == 3)
			printf("%d\n", ans[i]);
	
	return 0;
}