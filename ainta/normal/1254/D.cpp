#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
int n, Q, C[151000], Heavy[151000], PPP[151000], Num[151000], Ed[151000], par[151000];
long long Tot, Mod = 998244353;
vector<int>E[151000], Ch[151000], G[151000];
long long BIT[151000];
void Add(int a, long long b) {
	while (a <= n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
long long Sum(int a) {
	long long r = 0;
	while (a) {
		r = (r+BIT[a])%Mod;
		a -= (a&-a);
	}
	return r;
}
int cnt, Dep[151000], ppp[151000][20];
void DFS(int a, int pp) {
	C[a] = 1;
	ppp[a][0] = pp;
	for (int i = 0; i < 18; i++)ppp[a][i + 1] = ppp[ppp[a][i]][i];
	par[a] = pp;
	Num[a] = ++cnt;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
		Ch[a].push_back(x);
		C[a] += C[x];
	}
	Ed[a] = cnt;
}

long long SS[151000], InvN, Ans[151000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
void Add2(int b, int e, long long x) {
	if (b > e)return;
	Add(b, x);
	Add(e + 1, Mod-x);
}

int Up(int a, int d) {
	for (int i = 0; i < 18; i++) {
		if ((d >> i) & 1)a = ppp[a][i];
	}
	return a;
}

int main() {
	int i, a, b, ck;
	scanf("%d%d", &n, &Q);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	InvN = Pow(n, Mod - 2);
	DFS(1, 0);
	vector<int>T;
	for (i = 1; i <= n; i++) {
		if (E[i].size() >= 300) {
			T.push_back(i);
		}
	}
	while (Q--) {
		scanf("%d%d", &ck, &a);
		if (ck == 1) {
			scanf("%d", &b);
			Ans[a] = (Ans[a]+b)%Mod;
			if (E[a].size() < 300) {
				long long zz = InvN * b%Mod;
				Add2(1, Num[a]-1, zz*C[a] % Mod);
				Add2(Ed[a] + 1, n, zz*C[a] % Mod);
				for (auto &x : Ch[a]) {
					long long t = (n - C[x]) * zz%Mod;
					Add2(Num[x], Ed[x], t);
				}
			}
			else {
				SS[a] = (SS[a]+b)%Mod;
			}
		}
		else {
			long long res = Sum(Num[a]) % Mod;
			for (auto &t : T) {
				if (t == a)continue;
				if (Num[t]<=Num[a] && Num[a]<=Ed[t]) {
					res = (res + InvN * (n - C[Up(a,Dep[a]-Dep[t]-1)]) % Mod*SS[t]) % Mod;
				}
				else {
					res = (res + InvN * C[t] % Mod*SS[t]) % Mod;
				}
			}
			printf("%lld\n", (res+Ans[a])%Mod);
		}
	}
}