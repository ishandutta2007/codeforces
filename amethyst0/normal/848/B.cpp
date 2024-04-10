#include <bits/stdc++.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10, sd = maxn / 2;

vector <int> a;
deque <int> b[maxn];
int y[maxn], tim[maxn];

bool cmp(int a, int b) {
	if (y[a] != y[b]) {
		return y[a] < y[b];
	}
	
	return tim[a] < tim[b];
}

pii ans[maxn];
vector <int> g[maxn];

int main() {
	int n, w, h;
	
	cin >> n >> w >> h;
	
	for (int i = 0; i < n; i++) {
		int gg, x, t;
		
		scanf("%d %d %d", &gg, &x, &t);
		y[i] = x;
		tim[i] = t;
		
		if (gg == 1) {
			a.push_back(i);
		} else {
			b[x - t + sd].push_back(i);
			g[x - t + sd].push_back(i);
		}
	}
	
	sort(a.begin(), a.end(), cmp);
	
	for (int i = 0; i < maxn; i++) {
		if (!b[i].empty()) {
			sort(b[i].begin(), b[i].end(), cmp);
			sort(g[i].begin(), g[i].end(), cmp);
		}
	}
	
	for (int i = 0; i < (int)a.size(); i++) {
		int num = a[i];
		int d = y[num] - tim[num] + sd;
		
		if (b[d].empty()) {
			ans[num] = mp(y[num], h);
		} else {
			ans[b[d].back()] = mp(y[num], h);
			b[d].pop_back();
			b[d].push_front(num);
		}
	}
	
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < (int)b[i].size(); j++) {
			int num = b[i][j];
			int num1 = g[i][j];
			
			ans[num] = mp(w, y[num1]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
	return 0;
}