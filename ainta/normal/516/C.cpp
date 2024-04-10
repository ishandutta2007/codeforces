#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 262144
struct SegT{
	long long M1, M2, R;
}IT[SZ+SZ+1];
int n, m, H[101000];
long long S[101000];
SegT Pro(SegT t1, SegT t2){
	SegT tp;
	tp.M1 = max(t1.M1, t2.M1);
	tp.M2 = max(t1.M2, t2.M2);
	tp.R = max(max(t1.R, t2.R), t1.M1 + t2.M2);
	return tp;
}
void init(int nd, int b, int e){
	if (b > n * 2)return;
	if (b == e){
		IT[nd].R = 0;
		if (b > n){
			IT[nd].M1 = 2 * H[b - n] - (S[n + 1] + S[b - n]);
			IT[nd].M2 = 2 * H[b - n] + (S[n + 1] + S[b - n]);
		}
		else{
			IT[nd].M1 = 2 * H[b] - S[b];
			IT[nd].M2 = 2 * H[b] + S[b];
		}
		return;
	}
	int m = (b + e) >> 1, c1 = nd * 2, c2 = nd * 2 + 1;
	init(c1, b, m);
	init(c2, m + 1, e);
	IT[nd] = Pro(IT[c1], IT[c2]);
}
SegT Calc(int nd, int b, int e, int s, int l){
	if (b == s&&e == l)return IT[nd];
	int m = (b + e) >> 1;
	if (l <= m)return Calc(nd * 2, b, m, s, l);
	if (s > m)return Calc(nd * 2 + 1, m + 1, e, s, l);
	SegT t1, t2;
	t1 = Calc(nd * 2, b, m, s, min(m, l));
	t2 = Calc(nd * 2 + 1, m + 1, e, max(m + 1, s), l);
	return Pro(t1, t2);
}
int main()
{
	int i, d, m, a, b;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++){
		scanf("%d", &d);
		S[i + 1] = S[i] + d;
	}
	for (i = 1; i <= n; i++)scanf("%d", &H[i]);
	init(1, 1, SZ);
	while (m--){
		scanf("%d%d", &a, &b);
		if (a <= b)printf("%lld\n", Calc(1, 1, SZ, b + 1, a + n - 1).R);
		else printf("%lld\n", Calc(1, 1, SZ, b + 1, a - 1).R);
	}
}