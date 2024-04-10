#include <bits/stdc++.h> 

using namespace std;

const int N = 1010;
const int M = 10010;

int q;
long double k;
long double dp[M][N];
bool vis[M][N];

long double call (int day, int orb) {
	// cout << day << " " << orb << endl;
	if (day < orb) return 0.0;
	if (orb == 0) {
		if (day == 0) return 2000.0;
		else return 0.0;
	}
	if (vis[day][orb]) return dp[day][orb];
	vis[day][orb] = 1;
	return dp[day][orb] = call(day - 1, orb) * orb/k + call(day - 1, orb - 1) * (k - orb + 1)/k;
}

int main (int argc, char const *argv[]) {
	scanf("%Lf %d", &k, &q);
	// cout << call(1, 1) << endl;
	while (q--) {
		long double p;
		scanf("%Lf", &p);
		int lo = 0, hi = M - 10;
		while (lo < hi) {
			int mid = lo + hi >> 1;
			long double prob = call(mid, (int) k);
			if (prob < p) lo = mid + 1;
			else hi = mid; 
		}
		printf("%d\n", lo);
	}
	return 0;
}