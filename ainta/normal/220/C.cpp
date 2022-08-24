#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define SZ 131072
using namespace std;
int a[100100], b[100010], n;
int w1[100010], w2[100010];
int IT1[SZ * 2 + 2], IT2[SZ * 2 + 2];
void Ins1(int a, int b, int c){
	a += SZ, b += SZ;
	while (a <= b){
		if (IT1[a] > c)IT1[a] = c;
		if (IT1[b] > c)IT1[b] = c;
		a = (a + 1) >> 1, b = (b - 1) >> 1;
	}
	return;
}
void Ins2(int a, int b, int c){
	a += SZ, b += SZ;
	while (a <= b){
		if (IT2[a] > c)IT2[a] = c;
		if (IT2[b] > c)IT2[b] = c;
		a = (a + 1) >> 1, b = (b - 1) >> 1;
	}
	return;
}
int Gap1(int a){
	int b = a;
	a += SZ;
	int r = 999999999;
	while (a){
		if (IT1[a] < r)r = IT1[a];
		a >>= 1;
	}
	return r + b;
}
int Gap2(int a){
	int b = a;
	a += SZ;
	int r = 999999999;
	while (a){
		if (IT2[a] < r)r = IT2[a];
		a >>= 1;
	}
	return r - b;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		w1[a[i]] = i;
	}
	for (i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		w2[b[i]] = i;
	}
	for (i = 1; i <= SZ * 2; i++){
		IT1[i] = IT2[i] = 999999999;
	}
	for (i = 1; i <= n; i++){
		if (w1[i] <= w2[i]){
			Ins2(0, w2[i] - w1[i], w2[i] - w1[i]);
			Ins1(w2[i] - w1[i], w2[i] - 1, -(w2[i] - w1[i]));
			Ins2(w2[i], n - 1, w2[i] + n - w1[i]);
		}
		else{
			Ins1(0, w2[i] - 1, w1[i] - w2[i]);
			Ins2(w2[i], w2[i] + n - w1[i], w2[i] + n - w1[i]);
			Ins1(w2[i] + n - w1[i], n - 1, -(w2[i] + n - w1[i]));
		}
	}
	for (i = 0; i < n; i++){
		printf("%d\n", min(Gap1(i), Gap2(i)));
	}
}