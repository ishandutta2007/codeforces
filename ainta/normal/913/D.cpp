#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define pii pair<int,int>
#define SZ 16384
using namespace std;
struct Tree {
	int IT[SZ + SZ];
	long long S[SZ + SZ];
	void Add(int a, int x) {
		a += SZ;
		IT[a]+=x;
		S[a] += 1ll*(a-SZ)*x;
		while (a != 1) {
			a >>= 1;
			IT[a] = IT[a * 2] + IT[a * 2 + 1];
			S[a] = S[a * 2] + S[a * 2 + 1];
		}
	}

	long long First(int K) {
		if (IT[1] < K)return 1e18;
		int nd = 1;
		long long s = 0;
		while (nd < SZ) {
			nd *= 2;
			if (K > IT[nd]) {
				K -= IT[nd];
				s += S[nd];
				nd++;
			}
		}
		s += 1ll * K*(nd - SZ);
		return s;
	}

}T1, T2;
int n, L, res;
vector<int>E[201000], Num[201000];
bool Pos(int c1, int c2) {
	if (c1 < 0 || c2 < 0)return false;
	return T1.First(c1) + T2.First(c2) <= L;
}
int w[201000][2];
int main() {
	int i, a, t, j, cc = 0;
	scanf("%d%d", &n, &L);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &a, &t);
		w[i][0] = a, w[i][1] = t;
		E[a].push_back(t);
		T2.Add(t, 1);
	}
	int pv = 0;
	for (i = 1; i <= n; i++) {
		while (pv < i && Pos(i - pv, pv) || Pos(i - pv - 1, pv + 1))pv++;
		while (pv >= 0 && !Pos(i - pv, pv))pv--;
		if (res < pv) {
			res = pv;
			cc = i;
		}
		if (pv == -1)break;
		for (j = 0; j < E[i].size(); j++) {
			T2.Add(E[i][j], -1);
			T1.Add(E[i][j], 1);
		}
	}
	printf("%d\n", res);
	if (res == 0) {
		printf("0\n\n");
		return 0;
	}
	set<pii>Set1, Set2;
	for (i = 1; i <= n; i++) {
		if (w[i][0] < cc) {
			Set1.insert({ w[i][1],i });
		}
		else {
			Set2.insert({ w[i][1],i });
		}
	}
	printf("%d\n", cc);
	for (i = 0; i < cc - res; i++) {
		printf("%d ", Set1.begin()->second);
		Set1.erase(Set1.begin());
	}
	for (i = 0; i < res; i++) {
		printf("%d ", Set2.begin()->second);
		Set2.erase(Set2.begin());

	}
}