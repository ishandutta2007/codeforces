#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[100010];
long long Res;
int C[101000], cnt;
void Add(int a, int x){
	if (!C[a])cnt++;
	C[a]+=x;
	if (!C[a])cnt--;
}
long long C2(int a){
	return (long long)a*(a - 1) / 2;
}
void Do(int be){
	int i;
	for (i = 1; i <= n; i++)C[i] = 0;
	cnt = 0;
	for (i = be; i <= n - be + 1; i++){
		if (!C[w[i]])cnt++;
		C[w[i]]++;
	}
	for (i = be;; i++){
		if (C[w[i]] > 0 && C[w[i]] <= 2)cnt--;
		C[w[i]] -= 2;
		if (!cnt)break;
	}
	Res += (long long)(n - be - i + 1) * be;
}
int main()
{
	int i, be, ed;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		C[w[i]]++;
		if (C[w[i]]&1)cnt++;
		else cnt--;
	}
	if (cnt >= 2){
		printf("0\n");
		return 0;
	}
	for (i = 1; i <= n; i++){
		if (w[i] != w[n + 1 - i])break;
	}
	if (i == n + 1){
		printf("%lld\n", C2(n + 1));
		return 0;
	}
	Res = (long long)i*i;
	be = i;
	for (i = n / 2;; i--){
		if (w[i] != w[n + 1 - i])break;
	}
	ed = i;
	for (i = 1; i <= n; i++)C[i] = 0;
	cnt = 0;
	for (i = be; i <= ed; i++){
		Add(w[i], 1);
		Add(w[n-i+1], -1);
	}
	if (!cnt){
		Res += (long long)be * (n - be - ed + 1) * 2;
		printf("%lld\n", Res);
		return 0;
	}
	Do(be);
	for (i = 1; i <= n / 2; i++)swap(w[i], w[n + 1 - i]);
	Do(be);
	printf("%lld\n", Res);
}