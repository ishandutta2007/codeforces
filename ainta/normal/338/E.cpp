#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 262144
int n, m, h, w1[150001], w2[150001];
struct IdxTree{
	int S, M;
}IT[SZ*2+2];
void UDT(int node){
	IT[node].M = min(IT[node * 2].M, IT[node * 2].S + IT[node * 2 + 1].M);
	IT[node].S = IT[node * 2].S + IT[node * 2 + 1].S;
}
void init(int node, int b, int e){
	if (b == e){
		if (b <= m)IT[node].M = IT[node].S = -1;
		else IT[node].M = IT[node].S = 0;
		return;
	}
	int mid = (b + e) >> 1;
	init(node * 2, b, mid);
	init(node * 2 + 1, mid + 1, e);
	UDT(node);
}
int Gap(int a){
	int be = 1, ed = m, res = m + 1, mid;
	while (be <= ed){
		mid = (be + ed) >> 1;
		if (w1[mid] + a >= h){
			res = mid;
			ed = mid - 1;
		}
		else{
			be = mid + 1;
		}
	}
	return res;
}
void Add(int node, int b, int e, int x, int y){
	if (b == e){
		IT[node].M += y;
		IT[node].S += y;
		return;
	}
	int m = (b + e) >> 1;
	if (x <= m)Add(node * 2, b, m, x, y);
	else Add(node * 2 + 1, m + 1, e, x, y);
	UDT(node);
}
int main()
{
	int i, R = 0;
	scanf("%d%d%d", &n, &m, &h);
	for (i = 1; i <= m; i++){
		scanf("%d", &w1[i]);
	}
	sort(w1 + 1, w1 + m + 1);
	for (i = 1; i <= n; i++){
		scanf("%d", &w2[i]);
		w2[i] = Gap(w2[i]);
	}
	init(1, 1, SZ);
	for (i = 1; i < m; i++){
		Add(1, 1, SZ, w2[i], 1);
	}
	for (i = m; i <= n; i++){
		Add(1, 1, SZ, w2[i], 1);
		if (IT[1].M == 0)R++;
		if (i == n)break;
		Add(1, 1, SZ, w2[i - m + 1], -1);
	}
	printf("%d\n", R);
}