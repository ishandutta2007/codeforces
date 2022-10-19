#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

const int MAXN = 50005;
const int MAXM = 1550005;

int N;
int a[MAXN];
vector <int> V;
bool bio[MAXM];
vector <int> anc[MAXN];
vector <int> comp[MAXN];
int sol[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

bool check(int val) {
	memset(bio, false, sizeof bio);
	for (int i = 0; i < N; i++) {
		bool ok = false;
		for (int j = 0; j < anc[i].size(); j++)
			if (anc[i][j] <= val && !bio[comp[i][j]]) {
				sol[i] = anc[i][j];
				bio[comp[i][j]] = true;
				ok = true;
				break;
			}
		if (!ok) return false;
	}
	return true;
}

void solve() {
	sort(a, a + N, greater <int> ());
	for (int i = 0; i < N; i++) 
		for (int x = a[i]; x; x /= 2) {
			anc[i].push_back(x);
			V.push_back(x);
		}
	
	sort(V.begin(), V.end()); 
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < anc[i].size(); j++)
			comp[i].push_back(lower_bound(V.begin(), V.end(), anc[i][j]) - V.begin());
	
	int lo = 0, hi = (int)1e9;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	check(lo);
	
	for (int i = 0; i < N; i++)
		printf("%d ", sol[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}