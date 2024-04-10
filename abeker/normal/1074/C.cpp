#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int INF = 1e9;

int N;
pii p[MAXN];
int plo[MAXN], phi[MAXN], slo[MAXN], shi[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
}

int dist(int a, int b) {
	return abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second);
}

void solve() {
	int four = 0;
	for (int i = 0; i < N; i++)
		four += dist(i, (i + 1) % N);
	
	sort(p, p + N);
	
	int mxlo = -INF, mxhi = -INF;
	for (int i = 0; i < N; i++) {
		if (-p[i].first - p[i].second > mxlo) {
			mxlo = -p[i].first - p[i].second;
			plo[i] = i;
		}
		else
			plo[i] = plo[i - 1];
		if (-p[i].first + p[i].second > mxhi) {
			mxhi = -p[i].first + p[i].second;
			phi[i] = i;
		}
		else
			phi[i] = phi[i - 1];
	}
	
	mxlo = -INF, mxhi = -INF;
	for (int i = N - 1; i >= 0; i--) {
		if (p[i].first - p[i].second > mxlo) {
			mxlo = p[i].first - p[i].second;
			slo[i] = i;
		}
		else
			slo[i] = slo[i + 1];
		if (p[i].first + p[i].second > mxhi) {
			mxhi = p[i].first + p[i].second;
			shi[i] = i;
		}
		else
			shi[i] = shi[i + 1];
	}
	
	int three = 0;
	for (int i = 1; i < N - 1; i++) 
		for (auto lft : {0, plo[i - 1], phi[i - 1]})
			for (auto rig : {N - 1, slo[i + 1], shi[i + 1]})
				three = max(three, dist(lft, i) + dist(i, rig) + dist(rig, lft));
	
	printf("%d", three);
	for (int i = 3; i < N; i++)
		printf(" %d", four);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}