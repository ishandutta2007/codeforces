#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
char p[201000];
int n, S[201000], w[201000], C[88888888], K =400;
vector<int>G;
long long res;
void Go(int K) {
	int i;
	S[0] = n;
	C[S[0]]++;
	for (i = 1; i <= n; i++) {
		S[i] = S[i - 1];
		if (w[i] == 1)S[i] += K - 1;
		else S[i]--;
		res += C[S[i]];
		C[S[i]]++;
	}
	for (i = 0; i <= n; i++)C[S[i]]--;
}
int main() {
	int i, j, k;
	scanf("%s", p + 1);
	for (i = 1; p[i]; i++);
	n = i - 1;
	for (i = 1; i <= n; i++)w[i] = p[i] - '0';
	for (i = 1; i <= min(n,K); i++) {
		Go(i);
	}
	for (i = 1; i <= n; i++) {
		S[i] = S[i-1];
		if (w[i] == 1)S[i]++;
	}
	int sz = G.size();
	for (i = 1; i <= n / (K+1); i++) {
		int p1 = 0, p2 = 0;
		for (j = 0; j <= n; j++) {
			while (p1 <= n && S[p1] < S[j] + i)p1++;
			while (p2 <= n && S[p2] <= S[j] + i)p2++;
			int bb = j + (K + 1)*i;
			bb = max(bb, p1);
			int ee = p2 - 1;
			if (bb > ee)continue;
			bb -= j, ee -= j;
			res += ee/i - (bb + i - 1) / i + 1;
		}
	}
	printf("%lld\n", res);
}