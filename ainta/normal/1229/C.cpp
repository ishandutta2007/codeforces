#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int n, m, U[101000], Deg[101000], w[301000], Last[101000], Q;
long long sum;
vector<int>E[101000];
unordered_map<int, int>Map[101000];
void Add(int a, int b) {
	sum -= (long long)U[a] * (Deg[a] - U[a]);
	U[a] += b;
	sum += (long long)U[a] * (Deg[a] - U[a]);
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, a, b, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		Map[a][b] = Map[b][a] = 1;
		Deg[a]++, Deg[b]++;
		U[min(a, b)]++;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		sum += 1ll * U[i] * (Deg[i] - U[i]);
		Last[i] = i;
		w[i] = i;
	}
	printf("%lld\n", sum);
	scanf("%d", &Q);
	for (int T = n + 1; T <= n + Q; T++) {
		scanf("%d", &a);
		Add(a, -U[a]);
		if (T - Last[a] <= Deg[a] + 1) {
			for (j = Last[a] + 1; j < T; j++) {
				if (Last[w[j]] == j && Map[w[j]][a]) {
					Add(w[j], 1);
				}
			}
		}
		else {
			for (auto &x : E[a]) {
				if (Last[x] > Last[a]) {
					Add(x, 1);
				}
			}
		}
		Last[a] = T;
		w[T] = a;
		printf("%lld\n", sum);
	}
}