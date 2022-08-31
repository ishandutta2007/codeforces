#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<iostream>
#include<cassert>
using namespace std;
int TC, A[1010], B[1010], n;
void Solve() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)scanf("%d", &A[i]);
	for (i = 0; i < n; i++)scanf("%d", &B[i]);
	sort(A, A + n);
	sort(B, B + n);
	for (i = 0; i < n; i++)printf("%d ", A[i]);
	puts("");
	for (i = 0; i < n; i++)printf("%d ", B[i]);
	puts("");
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}