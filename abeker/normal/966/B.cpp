#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;

int N, x[2];
pii p[MAXN];

void load() {
	scanf("%d%d%d", &N, x, x + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
}

void work(int k) {
	int pos1 = N;
	for (int i = 0; i < N; i++)
		if ((ll)(i + 1) * p[i].first >= x[k]) {
			pos1 = i;
			break;
		}
	
	int pos2 = N;
	for (int i = pos1 + 1; i < N; i++)
		if ((ll)(i - pos1) * p[i].first >= x[k ^ 1]) {
			pos2 = i;
			break;
		}
	
	if (pos2 >= N)
		return;
	
	puts("Yes");
	
	vector <int> v1, v2;
	for (int i = 0; i <= pos1; i++)
		v1.push_back(p[i].second);
		
	for (int i = pos1 + 1; i <= pos2; i++)
		v2.push_back(p[i].second);
	
	if (k) 
		swap(v1, v2);
	
	printf("%d %d\n", v1.size(), v2.size());
	for (auto it : v1)
		printf("%d ", it + 1);
	puts("");
	for (auto it : v2)
		printf("%d ", it + 1);
	puts("");
	
	exit(0);
	
}

void solve() {
	sort(p, p + N, greater <pii> ());
	
	for (int k = 0; k < 2; k++)
		work(k);
	
	puts("No");
}

int main() {
	load();
	solve();
	return 0;
}