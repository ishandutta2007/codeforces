#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define N_ 201000
#define pii pair<int,int>
using namespace std;
int n, pL[N_];
long long Mod = 998244353;
vector<pii>E[N_];
vector<int>D[N_];
long long S1[N_], S2[N_], Back[N_], SS[N_];
void DFS(int a, int pp) {
	vector<int>Ch;
	for (auto &t : E[a]) {
		if (t.second == pp)continue;
		pL[t.second] = t.first;
		DFS(t.second, a);
		Ch.push_back(t.second);
	}
	D[a].resize(E[a].size() + 1);
	int sz = E[a].size();
	if (Ch.empty()) {
		D[a][0] = 1;
		D[a][sz] = 1;
	}
	else {
		Back[sz] = 1;
		for (int j = sz - 1; j >= 0; j--) {
			Back[j] = Back[j + 1];
			if (E[a][j].second != pp) Back[j] = Back[j] * S2[E[a][j].second] % Mod;
		}
		long long ss = 1;
		for (int j = 0; j < sz; j++) {
			int x = E[a][j].second;
			if (x == pp) {
				D[a][j] = ss * Back[j + 1] % Mod;
			}
			else {
				D[a][j] = ss * (SS[x] - S1[x] + Mod)%Mod * Back[j + 1] % Mod;
				ss = ss * S1[x] % Mod;
			}
		}
		D[a][sz] = ss;
	}
	for (int i = 0; i <= sz; i++) {
		if (i<sz && E[a][i].first <= pL[a]) {
			S1[a] = (S1[a] + D[a][i]) % Mod;
		}
		SS[a] = (SS[a] + D[a][i]) % Mod;
		if (i < sz && E[a][i].second == pp)continue;
		S2[a] = (S2[a] + D[a][i]) % Mod;
	}
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back({ i,b });
		E[b].push_back({ i,a });
	}
	for (i = 1; i <= n; i++) {
		sort(E[i].begin(), E[i].end());
	}
	DFS(1, 0);
	long long res = 0;
	for (i = 0; i <= E[1].size(); i++) {
		res = (res + D[1][i]) % Mod;
	}
	printf("%lld\n", res);
}