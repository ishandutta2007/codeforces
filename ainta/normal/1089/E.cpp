#include<cstdio>
#include<algorithm>
using namespace std;
void Print(int x, int y) {
	printf("%c%d ", x + 'a', y+1);
}
int A[20][2] = {
	{0,0},{0,7},{1,7},{1,0},{2,0},{2,7},{3,7},{3,0},{4,0},{4,7},{5,7},{5,0},{6,0},{6,7},{7,7}
};
int B[50][2] = {
	{ 0,0 },{ 0,7 },{ 1,7 },{ 1,0 },{ 2,0 },{ 2,7 },{ 3,7 },{ 3,0 },{ 4,0 },{ 4,7 },{ 5,7 },{ 5,0 },{ 7,0 },{7,1},{6,1},{6,2},{7,2},{7,3},{6,3},{6,4},{7,4},{7,5},{6,5},{6,7},{6,6},{7,6},{7,7}
};
int main() {
	int n, i, j;
	scanf("%d", &n);
	if (n <= 8) {
		for (i = 0; i < n - 1; i++) {
			Print(0, i);
		}
		Print(0, 7);
		Print(7, 7);
		return 0;
	}
	if (n <= 14) {
		for (i = 0; i < 8; i++) {
			Print(0, i);
		}
		for (i = 1; i <= n - 8; i++)Print(i, 7);
		Print(7, 7);
		return 0;
	}
	if (n <= 40) {
		int c = n-14;
		for (i = 0; i < 14; i+=2) {
			Print(A[i][0], A[i][1]);
			int t = A[i][1];
			int ck = 1;
			if (A[i + 1][1] < A[i][1])ck = -1;
			for (j = 0; j < 6 && c; j++) {
				t += ck;
				c--;
				Print(A[i][0], t);
			}
			Print(A[i+1][0], A[i+1][1]);
		}
		Print(A[14][0], A[14][1]);
	}
	else {
		int c = n - 26;
		for (i = 0; i < 26; i++) {
			Print(B[i][0], B[i][1]);
			int x = B[i][0], y = B[i][1];
			int x2 = B[i+1][0], y2 = B[i+1][1];
			int dx = 0, dy = 0;
			if (x == x2) {
				if (y < y2)dy = 1;
				else dy = -1;
			}
			else {
				if (x < x2)dx = 1;
				else dx = -1;
			}
			while (c) {
				x += dx;
				y += dy;
				if (x == x2 && y == y2)break;
				c--;
				Print(x, y);
			}
		}
		Print(B[26][0], B[26][1]);
	}
}