#pragma warning(disable:4996)
#include<stdio.h>
int A[100][2], B[100][2], c1, c2, ck;
void chk(int x1, int y1, int x2, int y2){
	if (x1 == x2 || y1 == y2)return;
	if (ck == 1)return;
	if (x1*x1 + y1*y1 + x2*x2 + y2*y2 == (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)){
		ck = 1;
		printf("YES\n");
		printf("0 0\n%d %d\n%d %d\n", x1, y1, x2, y2);
	}
}
int main()
{
	int a, b, i, j;
	scanf("%d%d", &a, &b);
	a *= a, b *= b;
	for (i = 1; i*i < a; i++){
		for (j = 1; j*j < a - i*i; j++);
		if (i*i + j*j == a){
			A[c1][0] = i;
			A[c1++][1] = j;
		}
	}
	for (i = 1; i*i < b; i++){
		for (j = 1; j*j < b - i*i; j++);
		if (i*i + j*j == b){
			B[c2][0] = i;
			B[c2++][1] = j;
		}
	}
	for (i = 0; i < c1; i++){
		for (j = 0; j < c2; j++){
			chk(A[i][0], -A[i][1], -B[j][0], -B[j][1]);
			chk(A[i][0], -A[i][1], B[j][0], -B[j][1]);
			chk(A[i][0], A[i][1], -B[j][0], -B[j][1]);
			chk(A[i][0], A[i][1], B[j][0], -B[j][1]);
			chk(A[i][0], -A[i][1], -B[j][0], B[j][1]);
			chk(A[i][0], -A[i][1], B[j][0], B[j][1]);
			chk(A[i][0], A[i][1], -B[j][0], B[j][1]);
			chk(A[i][0], A[i][1], B[j][0], B[j][1]);
		}
	}
	if (!ck)printf("NO\n");
}