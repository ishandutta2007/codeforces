#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[8][6][3], w[8][3], chk;
long long D[40];
long long dis2(int a, int b, int x){
	return (long long)(w[a][x] - w[b][x])*(w[a][x] - w[b][x]);
}
long long dis(int a, int b){
	return dis2(a, b, 0) + dis2(a, b, 1) + dis2(a, b, 2);
}
bool Pos(){
	int i, j, c = 0, c1 = 0, c2 = 0, c3 = 0;
	long long a;
	for (i = 0; i < 8; i++){
		for (j = i + 1; j < 8; j++){
			D[c++] = dis(i, j);
		}
	}
	sort(D, D + c);
	a = D[0];
	if (a == 0)return false;
	for (i = 0; i < c; i++){
		if (D[i] == a)c1++;
		if (D[i] == a * 2)c2++;
		if (D[i] == a * 3)c3++;
	}
	if (c1 == 12 && c2 == 12 && c3 == 4)return true;
	return false;
}
void DFS(int a){
	if (chk)return;
	if (a == 8){
		if (Pos()){
			printf("YES\n");
			for (int i = 0; i < 8; i++){
				for (int j = 0; j < 3; j++){
					printf("%d ", w[i][j]);
				}
				printf("\n");
			}
			chk = 1;
		}
		return;
	}
	int i, j;
	for (i = 0; i < 6; i++){
		for (j = 0; j < 3; j++){
			w[a][j] = inp[a][i][j];
		}
		DFS(a + 1);
		if (chk)return;
	}
}
int cnt, p[3], pp[3], v[3];
void DFS2(int pv, int a){
	if (a == 3){
		for (int i = 0; i < 3; i++){
			inp[pv][cnt][i] = p[i];
		}
		cnt++;
		return;
	}
	for (int i = 0; i < 3; i++){
		if (!v[i]){
			p[a] = pp[i];
			v[i] = true;
			DFS2(pv, a + 1);
			v[i] = false;
		}
	}
}
int main()
{
	int i, j;
	for (i = 0; i < 8; i++){
		scanf("%d%d%d", &pp[0], &pp[1], &pp[2]);
		cnt = 0;
		for (j = 0; j < 3; j++)v[j] = false;
		DFS2(i, 0);
	}
	for (i = 0; i < 3; i++)w[0][i] = inp[0][0][i];
	DFS(1);
	for (i = 0; i < 3; i++)w[0][i] = inp[0][1][i];
	DFS(1);
	if (!chk)printf("NO\n");
}