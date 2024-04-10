#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010, INF = 1000000000;

int n, m;
int a[MAXN], b[MAXN], lo[MAXN], hi[MAXN];
int t[MAXN], x[MAXN], y[MAXN], u[MAXN];

int main() {
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) 
		b[i] = INF;
		
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &t[i], &x[i], &y[i], &u[i]);
		x[i]--; y[i]--;
		for (int j = x[i]; j <= y[i]; j++) 
			if (t[i] == 1) {
				a[j] += u[i];
				lo[j] = min(lo[j], a[j]);
				hi[j] = max(hi[j], a[j]);
			}
			else b[j] = min(b[j], u[i] - a[j]);
	}
	
	memcpy(a, b, sizeof a);
	
	bool ok = true;
	
	for (int i = 0; i < m; i++) {
		int maks = -INF;
		for (int j = x[i]; j <= y[i]; j++) 
			if (t[i] == 1) b[j] += u[i];
			else maks = max(maks, b[j]);
		if (t[i] == 2 && maks != u[i]) {
			ok = false;
			break;
		}
	}
	
	for (int i = 0; i < n; i++) 
		if (-INF - lo[i] > INF - hi[i]) {
			ok = false;
			break;
		}
		
	if (ok) {
		puts("YES");
		for (int i = 0; i < n; i++) 
			printf("%d ", a[i]);
		puts("");
	}		
	else puts("NO");
	
	return 0;
}