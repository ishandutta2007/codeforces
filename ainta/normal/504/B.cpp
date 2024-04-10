#include<stdio.h>
int BIT[300000];
int n;
int r[300000];
int Sum(int a){
	int r = 0;
	while (a){
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
void Add(int a, int b){
	while (a <= n){
		BIT[a] += b;
		a += (a&-a);
	}
}
int main()
{
	int i, a, b, e, rr, mid;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)Add(i, 1);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		a++;
		Add(a, -1);
		r[n - i] += Sum(a);
	}
	for (i = 1; i <= n; i++)BIT[i] = 0;
	for (i = 1; i <= n; i++)Add(i, 1);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		a++;
		Add(a, -1);
		r[n - i] += Sum(a);
	}
	for (i = 0; i < n; i++){
		if (r[i] > i){
			r[i] -= (i + 1);
			r[i + 1]++;
		}
	}
	for (i = 1; i <= n; i++)BIT[i] = 0;
	for (i = 1; i <= n; i++)Add(i, 1);
	for (i = 1; i <= n; i++){
		b = 1, e = n;
		while (b <= e){
			mid = (b + e) >> 1;
			if (Sum(mid) >= r[n - i] + 1){
				rr = mid, e = mid - 1;
			}
			else b = mid + 1;
		}
		Add(rr, -1);
		printf("%d ", rr - 1);
	}
}