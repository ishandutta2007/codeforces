#include<stdio.h>
int n, D[4010000], be[4010000], ed[4010000];
char p[4010000];
int main(){
	int i, pv, mid, t, a, b;
	long long Mod = 51123987, Sum = 0, Res = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++){
		p[i + i + 1] = getchar();
		p[i + i + 2] = ' ';
	}
	pv = -1;
	for (i = 1; i < n + n; i++){
		t = i;
		if (pv >= i){
			t = i + D[mid + mid - i];
			if (t > pv) t = pv;
		}
		while (t + 1 < n + n && t + 1 < i + i && p[t + 1] == p[i + i - t - 1])t++;
		D[i] = t - i;
		if (t > pv)pv = t, mid = i;
	}
	for (i = 1; i < n + n; i++){
		a = i - D[i], b = i + D[i];
		a = a / 2 + 1; b = (b + 1) / 2;
		be[a]++, be[(i + 1) / 2 + 1]--;
		ed[i / 2 + 1]++, ed[b + 1]--;
	}
	for (i = 1; i <= n; i++){
		be[i] += be[i - 1], ed[i] += ed[i - 1];
		Res = (Res + Sum * be[i]) % Mod;
		Sum += ed[i];
	}
	Sum %= Mod;
	Res = (Sum*(Sum - 1) / 2 - Res + Mod) % Mod;
	printf("%lld\n", Res);
	return 0;
}