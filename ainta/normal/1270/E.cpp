#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point {
	int x, y;
};
vector<point>w;
vector<int>Get() {
	int n = w.size();
	int i;
	vector<int>G[2],P[2];
	for (i = 0; i < n; i++) {
		int t = abs(w[i].x + w[i].y);
		G[t % 2].push_back(i);
	}
	if (!G[0].empty() && !G[1].empty())return G[0];
	if (G[0].empty()) {
		for (i = 0; i < n; i++) {
			w[i].x++;
		}
		return Get();
	}
	for (i = 0; i < n; i++) {
		P[abs(w[i].x) % 2].push_back(i);
	}
	if (!P[0].empty() && !P[1].empty()) return P[0];
	if (P[0].empty()) {
		for (i = 0; i < n; i++) {
			w[i].x++;
			w[i].y++;
		}
		return Get();
	}
	for (i = 0; i < n; i++) {
		w[i].x /= 2, w[i].y /= 2;
	}
	return Get();
}
void Solve() {
	int i, ck =0, n, Mn = 1e9;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		Mn = min(Mn, x);
		Mn = min(Mn, y);
		w.push_back({ x,y });
	}
	for (i = 0; i < n; i++) {
		w[i].x -= Mn;
		w[i].y -= Mn;
	}
	vector<int>A = Get();
	printf("%d\n", A.size());
	for (auto &t : A)printf("%d ", t+1);
}
int main() {
	int TC = 1, t;
	while (TC--) {
		Solve();
	}
}