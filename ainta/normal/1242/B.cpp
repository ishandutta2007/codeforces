#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define pii pair<int,int>
using namespace std;
int n, m, D[101000];
long long res;
set<int>E[101000];
priority_queue<pii>PQ;
void Put(int a, int d) {
	if (D[a] <= d)return;
	D[a] = d;
	PQ.push({ -d,a });
}
set<int>SET;
int main() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].insert(b);
		E[b].insert(a);
	}
	for (i = 1; i <= n; i++)D[i] = 1e9;
	for (i = 2; i <= n; i++) {
		SET.insert(i);
	}
	Put(1, 0);
	while (!PQ.empty()) {
		pii tp = PQ.top();
		PQ.pop();
		int x = tp.second;
		if (D[x] != -tp.first)continue;
		res += D[x];
		vector<int>VV;
		for (auto &t : SET) {
			if (E[x].find(t) != E[x].end()) {
				Put(t, 1);
			}
			else {
				Put(t, 0);
				VV.push_back(t);
			}
		}
		for (auto &t : VV)SET.erase(t);
	}
	printf("%lld\n", res);
}