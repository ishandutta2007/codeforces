#include<cstdio>
#include<algorithm>
#include<queue>
#define N_ 201000
#define pli pair<long long, int>
using namespace std;
priority_queue<pli>PQ;
int n, m;
long long D[N_];
vector<int>E[N_];
vector<long long>L[N_];
void Put(int a, long long d) {
	if (D[a] <= d)return;
	D[a] = d;
	PQ.push({ -d,a });
}
int main() {
	int i, a, b;
	long long c;
	scanf("%d%d", &n,&m);
	for (i = 0; i < m; i++) {
		scanf("%d%d%lld", &a, &b, &c);
		E[a].push_back(b);
		L[a].push_back(2*c);
		E[b].push_back(a);
		L[b].push_back(2*c);
	}
	for (i = 1; i <= n; i++)D[i] = 5e18;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &c);
		Put(i, c);
	}
	while (!PQ.empty()) {
		pli tp = PQ.top();
		PQ.pop();
		int x = tp.second;
		if (D[x] != -tp.first)continue;
		for (i = 0; i < E[x].size(); i++) {
			Put(E[x][i], D[x] + L[x][i]);
		}
	}
	for (i = 1; i <= n; i++)printf("%lld ", D[i]);
}