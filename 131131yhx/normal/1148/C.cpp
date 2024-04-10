#include <bits/stdc++.h>
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

int n, S[300010], Pr[300010];

vector <PII> V(0);

bool used[300010];

void Do(int x, int y) {
	swap(S[x], S[y]);
	V.push_back(PII(x, y));
}

void calc(int x, int y) {
	if(x > y) swap(x, y);
	if(x <= n / 2 && y <= n / 2) {
		Do(x, n);
		Do(y, n);
		Do(x, n);
	} else if(x > n / 2 && y > n / 2) {
		Do(x, 1);
		Do(y, 1);
		Do(x, 1);
	} else if(x == 1 || y == n) Do(x, y); else {
		Do(x, n);
		Do(1, y);
		Do(1, n);
		Do(x, n);
		Do(1, y);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &S[i]), Pr[S[i]] = i;
	for(int i = 1; i <= n; i++) if(!used[i]) {
		for(int j = i; Pr[j] != i; j = Pr[j]) calc(j, Pr[j]), used[Pr[j]] = 1;
		used[i] = 1;
	}
	printf("%d\n", V.size());
	for(int i = 0; i < V.size(); i++) printf("%d %d\n", V[i].x, V[i].y);
	for(int i = 2; i <= n; i++) if(S[i] < S[i - 1]) assert(0);
	return 0;
}