#include<stdio.h>
#include<algorithm>
#include<map>
#define SZ 131072
using namespace std;
int n, IT[SZ*2+2];
map<int, long long>Map;
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
void UDT(int a){
	while (a > 1){
		a >>= 1;
		if (!IT[a * 2] || !IT[a * 2 + 1])break;
		IT[a] = gcd(IT[a * 2], IT[a * 2 + 1]);
	}
}
void Do(int a, int b){
	if (!IT[a])return;
	int be = a;
	while (1){
		a = (a + 1) >> 1;
		if (IT[a] % b || IT[a] == 0)break;
	}
	while (a < SZ){
		if (IT[a * 2] % b || IT[a * 2] == 0)a = a * 2;
		else a = a * 2 + 1;
	}
	Map[b] += a - be;
	Do(a, gcd(b, IT[a]));
}
int main()
{
	int i, Q, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &IT[SZ + i]);
	}
	for (i = 1; i <= n; i++)UDT(SZ + i);
	for (i = 1; i <= n; i++){
		Do(SZ + i, IT[SZ + i]);
	}
	scanf("%d", &Q);
	while (Q--){
		scanf("%d", &a);
		printf("%lld\n", Map[a]);
	}
}