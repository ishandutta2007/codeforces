#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define pll pair<long long, long long>
#define MMAX 1000000000000LL
long long n, m, w[10010], LCM, G, TP;
int K, cnt, p2[100];
long long p[100], pp[100], r[100];
long long aa, bb;
long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}
void UDT(long long &a, long long &b, long long c, long long d){
	if (b < d){
		swap(b, d);
		swap(a, c);
	}
	while (a%d != c) a += b;
	b *= d;
}
int main()
{
	int i, j, c;
	scanf("%lld%lld%d", &n, &m, &K);
	LCM = 1;
	for (i = 1; i <= K; i++){
		scanf("%lld", &w[i]);
		G = gcd(LCM, w[i]);
		if (LCM / G > MMAX / w[i])break;
		LCM = LCM / G *w[i];
	}
	if (i != K + 1 || LCM > n){
		printf("NO\n");
		return 0;
	}
	TP = LCM;
	for (i = 2; (long long)i*i <= TP; i++){
		if (TP%i == 0){
			p[++cnt] = i;
			while (TP%i == 0){
				TP /= i;
				p2[cnt]++;
			}
		}
	}
	if (TP != 1){
		p[++cnt] = TP;
		p2[cnt] = 1;
	}
	for (i = 1; i <= cnt; i++){
		pp[i] = 1;
		for (j = 1; j <= p2[i]; j++){
			pp[i] *= p[i];
		}
	}
	for (i = 1; i <= K; i++){
		TP = w[i];
		for (j = 1; j <= cnt; j++){
			c = 0;
			while (TP % p[j] == 0){
				TP /= p[j];
				c++;
			}
			if (p2[j] == c){
				r[j] = (i / pp[j] * pp[j] + pp[j] - i) % pp[j];
			}
		}
	}
	pll t;
	long long MD;
	aa = r[1], bb = pp[1];
	for (i = 2; i <= cnt; i++){
		UDT(aa, bb, r[i], pp[i]);
	}
	if (aa + K > m){
		printf("NO\n");
		return 0;
	}
	for (i = 1; i <= K; i++){
		if (gcd(aa + i, LCM) != w[i])break;
	}
	if (i == K + 1)printf("YES\n");
	else printf("NO\n");
}