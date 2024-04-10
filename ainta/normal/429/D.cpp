#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define INF 100000000000000LL
using namespace std;
int n, S[100100];
long long dist(int a, int b){
	long long x = a - b, y = S[a] - S[b];
	return x*x + y*y;
}
struct point{
	int x, y;
	bool operator <(const point &p)const{
		return y < p.y;
	}
}w1[101000], w2[101000];
long long Gap(int be, int ed){
	long long R = INF;
	if (ed - be <= 10){
		int i, j;
		for (i = be; i < ed; i++){
			for (j = i + 1; j <= ed; j++){
				R = min(R, dist(i, j));
			}
		}
		return R;
	}
	int mid = (be + ed) >> 1, c1 = 0, c2 = 0, pv = 0, j;
	R = min(Gap(be, mid), Gap(mid + 1, ed));
	int i, d = (int)sqrt((double)R);
	for (i = max(mid - d, be); i <= mid; i++){
		w1[c1].x = i, w1[c1].y = S[i];
		c1++;
	}
	for (i = mid + 1; i <= min(mid + d + 1, ed); i++){
		w2[c2].x = i, w2[c2].y = S[i];
		c2++;
	}
	sort(w1, w1 + c1);
	sort(w2, w2 + c2);
	for (i = 0; i < c1; i++){
		while (pv < c2 && w1[i].y > w2[pv].y)pv++;
		for (j = pv - 7; j < pv + 7; j++){
			if (j < 0 || j >= c2)continue;
			R = min(R, dist(w1[i].x, w2[j].x));
		}
	}
	return R;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &S[i]);
		S[i] += S[i - 1];
	}
	printf("%lld\n",Gap(1, n));
}