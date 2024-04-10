#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ld, int> event;

const int MAXN = 2e5 + 5;
const int ITER = 40;
const int LOG = 18;
const int INF = 1e9;
const ld eps = 1e-12;

int N, M;
pii p[MAXN];
ld dist[MAXN], phi[MAXN];
int jmp[MAXN][LOG];
ld gap[MAXN][LOG];
ld pt[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
}

bool check(ld r) {
	int least = -1;
	vector <event> sweep;
	for (int i = 0; i < N; i++) {
		ld angle = acos(r / dist[i]);
		ld lo = phi[i] - angle;
		ld hi = phi[i] + angle;
		if (lo < 0) {
			lo += 2 * M_PI;
			hi += 2 * M_PI;
		}
		pt[2 * i] = lo;
		pt[2 * i + 1] = hi;
		for (auto it : {2 * i, 2 * i + 1})
			sweep.push_back({pt[it], it});
		if (hi < 2 * M_PI && (least == -1 || hi < pt[least]))
			least = 2 * i + 1;
	}
	
	if (least == -1)
		return true;
	
	sort(sweep.begin(), sweep.end(), greater <event> ());
	
	ld opt = pt[least] + 2 * M_PI;
	for (auto it : sweep) {
		jmp[it.second][0] = least;
		gap[it.second][0] = opt - it.first;
		if (!(it.second % 2) && pt[it.second + 1] < opt) {
			opt = pt[it.second + 1];
			least = it.second + 1;
		}
	}
	
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i < 2 * N; i++) {
			jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
			gap[i][j] = gap[i][j - 1] + gap[jmp[i][j - 1]][j - 1];
		}
	
	for (int i = 0; i < 2 * N; i++) {
		int x = i;
		ld trav = 0;
		for (int j = 0; j < LOG; j++)
			if (M >> j & 1) {
				trav += gap[x][j];
				x = jmp[x][j];
			}
		if (trav > 2 * M_PI - eps)
			return true;
	}
	
	return false;
}

ld solve() {
	sort(p, p + N);
	N = unique(p, p + N) - p;
	for (int i = 0; i < N; i++) {
		dist[i] = sqrt((ld)p[i].first * p[i].first + (ld)p[i].second * p[i].second);
		phi[i] = atan2(p[i].second, p[i].first);
		if (phi[i] < 0)
			phi[i] += 2 * M_PI;
	}
		
	ld lo = 0, hi = *min_element(dist, dist + N);
	for (int i = 0; i < ITER; i++) {
		ld mid = (lo + hi) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	
	return lo;
}

int main() {
	load();
	printf("%.10Lf\n", solve()); 
	return 0;
}