#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int N;
int a[MAXN][MAXN];
ll dist[MAXN];
bool bio[MAXN];
int mn = INT_MAX;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++) {
			scanf("%d", a[i] + j);
			a[j][i] = a[i][j];
			mn = min(mn, a[i][j]);
		}
}

void solve() {
	for (int i = 0; i < N; i++)
		a[i][i] = INT_MAX;
		
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] -= mn;
	
	memset(dist, INF, sizeof dist);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!a[i][j])
				dist[i] = dist[j] = 0;
	
	for (int i = 0; i < N; i++)
		if (dist[i]) {
			int tmp = *min_element(a[i], a[i] + N); 
			for (int j = 0; j < N; j++)
				if (!dist[j])
					a[i][j] = a[j][i] = min(a[i][j], 2 * tmp);
		}	
	
	for (int i = 1; i < N; i++) {
		int tmp = -1;
		for (int j = 0; j < N; j++)
			if (!bio[j] && (tmp == -1 || dist[j] < dist[tmp]))
				tmp = j;
		bio[tmp] = true;
		for (int j = 0; j < N; j++)
			if (!bio[j])
				dist[j] = min(dist[j], dist[tmp] + a[tmp][j]);
	}
	
	for (int i = 0; i < N; i++)
		printf("%lld\n", dist[i] + (ll)(N - 1) * mn);
}

int main() {
	load();
	solve();
	return 0;
}