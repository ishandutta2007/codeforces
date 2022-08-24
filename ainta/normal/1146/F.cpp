#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long D1[201000], D2[201000], Mod = 998244353;
vector<int>E[201000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
void DFS(int a) {
	if (E[a].empty()) {
		D1[a] = D2[a] = 1;
		return;
	}
	long long t1 = 1, t2 = 1;
	for (auto &x : E[a]) {
		DFS(x);
		t1 = t1 * (D1[x] + D2[x]) % Mod;
		t2 = t2 * D1[x]%Mod;
	}
	D1[a] = t1;
	for (auto &x : E[a]) {
		long long t = (Pow(D1[x], Mod - 2)*D2[x] % Mod)*t2%Mod;
		D1[a] = (D1[a] + Mod - t) % Mod;
	}
	D2[a] = (t1 - t2 + Mod) % Mod;
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(1);
	printf("%lld\n", D1[1]);
}