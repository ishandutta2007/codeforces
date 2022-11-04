#include <bits/stdc++.h>
#define PII pair <int, int>
#define x first
#define y second

using namespace std;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	vector <PII> V(0);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) V.push_back(PII(i, j));
	for(int i = -1, j = V.size(); ; ) {
		if(i + 1 < j) i++, printf("%d %d\n", V[i].x, V[i].y); else break;
		if(i + 1 < j) j--, printf("%d %d\n", V[j].x, V[j].y); else break;
	}
	return 0;
}