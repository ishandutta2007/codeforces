#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
struct AA {
	long long g;
	int c;
};
vector<AA>G[101000];
long long X[101000], res, Mod = 1000000007;
int n;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
void DFS(int a, int pp) {
	if (!pp) {
		G[a].push_back({ X[a],1 });
	}
	else {
		vector<AA>TP;
		long long t = X[a];
		TP.push_back({ t,1 });
		for (int i = G[pp].size() - 1; i >= 0; i--) {
			t = gcd(t, G[pp][i].g);
			if (TP.back().g == t) {
				TP.back().c += G[pp][i].c;
			}
			else TP.push_back({ t,G[pp][i].c });
		}
		reverse(TP.begin(), TP.end());
		G[a] = TP;
	}
	for (auto &t : G[a]) {
		res = (res + t.g*t.c)%Mod;
	}
	for (auto &x : E[a]) {
		if (x != pp)DFS(x, a);
	}
}
int main() {
	int a, b, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &X[i]);
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	printf("%lld\n", res);
}