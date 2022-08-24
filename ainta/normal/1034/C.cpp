#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1010000
using namespace std;
int w[N_], n, Res[N_], Mod = 1000000007;
long long S[N_], K;
vector<int>E[N_], G[N_], d;
void DFS(int a) {
	S[a] = w[a];
	for (auto &x : E[a]) {
		DFS(x);
		S[a] += S[x];
	}
}
void Go(int a) {
	int i, c = 0;
	for (i = 1; i*i < a; i++) {
		if (a%i == 0) {
			c += G[i].size();
			c += G[a / i].size();
		}
	}
	if (i*i == a)c += G[i].size();
	if (c == a) {
		Res[a] = 1;
		for (auto &x : d) {
			if (x%a == 0)Res[a] = (Res[a] + Res[x]) % Mod;
		}
		d.push_back(a);
	}
}
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(1);
	for (i = 1; i <= n; i++) {
		long long g = gcd(S[1], S[i]);
		if (S[1] / g <= n) {
			G[S[1] / g].push_back(i);
		}
	}
	for (i = n; i >= 1; i--) {
		if(S[1]%i==0) Go(i);
	}
	printf("%d\n", Res[1]);
}