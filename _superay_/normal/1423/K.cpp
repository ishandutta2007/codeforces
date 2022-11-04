#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int pri[N],tot,zhi[N], ps[N], sq[N];
void sieve(int n = 1000000) {
    zhi[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!zhi[i]) pri[++tot]=i;
        for (int j=1;j<=tot&&i*pri[j]<=n;j++)
        {
            zhi[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
    for (int i = 1; i <= tot; i++) ps[pri[i]]++;
    for (int i = 1; i <= n; i++) ps[i] += ps[i - 1];
    for (int i = 1; i <= 1000; i++) {
    	for (int j = i * i; j <= n && j < (i + 1) * (i + 1); j++) {
    		sq[j] = i;
    	}
    }
}
int main() {
	sieve();
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ps[n] - ps[sq[n]] + 1);
	}
	return 0;
}