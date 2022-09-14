#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

#define ll long long

using namespace std;

const int maxn = (int)3e5 + 10;

ll sumx[maxn], sumy[maxn];

int x[maxn], y[maxn];

ll ans[maxn];

bool cmp(int a, int b) {
	return x[a] - y[a] < x[b] - y[b];
}

ll getx(int l, int r) {
	if (r < l) {
		return 0;
	}
	
	return (l == 0 ? sumx[r] : sumx[r] - sumx[l - 1]);
}

ll gety(int l, int r) {
	if (r < l) {
		return 0;
	}
	
	return (l == 0 ? sumy[r] : sumy[r] - sumy[l - 1]);
}

vector <int> ed[maxn];
int wh[maxn];

int main() {
	int n, m;
	
	cin >> n >> m;
	
	vector <int> id;
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		id.push_back(i);
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		
		scanf("%d %d", &a, &b);
		a--;
		b--;
		
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	
	sort(id.begin(), id.end(), cmp);

	ll curx = 0, cury = 0;
	
	for (int i = 0; i < n; i++) {
		curx += x[id[i]];
		cury += y[id[i]];
		wh[id[i]] = i;
		
		sumx[i] = curx;
		sumy[i] = cury;
	}

	for (int it = 0; it < n; it++) {
		int i = id[it];
		
		ans[i] = (ll)it * y[i] + (ll)(n - it - 1) * x[i];
		
		ans[i] += getx(0, it - 1);
		ans[i] += gety(it + 1, n - 1);
		
		for (int j = 0; j < (int)ed[i].size(); j++) {
			int u = ed[i][j];
			
			u = wh[u];
			
			if (u > it) {
				ans[i] -= x[i];
				ans[i] -= y[ed[i][j]];
			} else {
				ans[i] -= y[i];
				ans[i] -= x[ed[i][j]];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%lld ", ans[i]);
	}

	return 0;
}