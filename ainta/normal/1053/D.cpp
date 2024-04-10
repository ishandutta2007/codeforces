#include<cstdio>
#include<algorithm>
using namespace std;
int p[1000], n, cnt;
int C[2010000], CC[2010000], NN[2010000];
long long res = 1, Mod = 1000000007;
int main() {
	int i, j, a, chk = 0;
	for (i = 2; i <= 1500; i++) {
		for (j = 2; j*j <= i; j++)if (i%j == 0)break;
		if (j*j > i)p[cnt++] = i;
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		C[a]++;
	}
	for (i = 2000000; i >= 1; i--) {
		if (!C[i])continue;
		if (CC[i] == 0)C[i]--, CC[i] = 1;
		if (!C[i])continue;
		if (C[i]) {
			int t = i - 1, ck = 0;
			for (j = 0; j < cnt; j++) {
				if (t%p[j] == 0) {
					int c = 0;
					while (t%p[j] == 0)t /= p[j], c++;
					if (CC[p[j]] < c)ck = 1;
					CC[p[j]] = max(CC[p[j]], c);
				}
			}
			if (t != 1) {
				if (!CC[t])ck = 1;
				CC[t] = max(CC[t], 1);
			}
			if (!ck || C[i] > 1)chk = 1;
		}
	}

	for (i = 2000000; i >= 1; i--) {
		//if(CC[i] == 1)NN[i] += C[i];
		if (C[i]) {
			int t = i - 1;
			for (j = 0; j < cnt; j++) {
				if (t%p[j] == 0) {
					int c = 0;
					while (t%p[j] == 0)t /= p[j], c++;
					if (CC[p[j]] == c)NN[p[j]]++;
				}
			}
			if (t != 1) {
				if (CC[t] == 1)NN[t]++;
			}
		}
	}
	for (i = 2000000; i >= 1; i--) {
		if (C[i]) {
			int t = i - 1, ck = 0;
			for (j = 0; j < cnt; j++) {
				if (t%p[j] == 0) {
					int c = 0;
					while (t%p[j] == 0)t /= p[j], c++;
					if (CC[p[j]] == c && NN[p[j]]==1)ck = 1;
				}
			}
			if (t != 1) {
				if (CC[t] == 1 && NN[t] == 1)ck = 1;
			}
			if (!ck)chk = 1;
		}
	}

	for (i = 2000000; i >= 1; i--) {
		if (C[i]) {
			int t = i - 1;
			for (j = 0; j < cnt; j++) {
				if (t%p[j] == 0) {
					int c = 0;
					while (t%p[j] == 0)t /= p[j], c++;
					if (c == CC[p[j]])NN[p[j]]++;
				}
			}
		}
	}
	for (i = 1; i <= 2000000; i++) {
		if (CC[i]) {
			for (j = 0; j < CC[i]; j++)res = res*i%Mod;
		}
	}
	if (chk)res = (res + 1) % Mod;
	printf("%lld\n", res);
}