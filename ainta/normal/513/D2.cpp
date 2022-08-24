#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 1048576
int n, Q, w[1010000][3], P[1010000], L[1010000], Ed[1010000];
int C[1010000][2], ck;
int IT[2100000];
void Add(int a, int b){
	a += SZ;
	IT[a] = b;
	while (a != 1){
		a >>= 1;
		IT[a] = max(IT[a + a], IT[a + a + 1]);
	}
}
int Max(int b, int e){
	b += SZ, e += SZ;
	int r = 0;
	while (b <= e){
		r = max(r, IT[b]);
		r = max(r, IT[e]);
		b = (b + 1) >> 1; e = (e - 1) >> 1;
	}
	return r;
}
void DFS(int a, int ed){
	Ed[a] = ed;
	int t = a + 1;
	if (a == ed)return;
	if (L[a]){
		C[a][0] = a + 1;
		t = Max(a + 1, L[a]);
		if (t > ed){
			ck = 1;
			return;
		}
		DFS(a + 1, t);
		if (ck)return;
		t++;
	}
	if (t != ed + 1){
		C[a][1] = t;
		if (P[t] > ed){
			ck = 1;
			return;
		}
		DFS(C[a][1], ed);
		if (ck)return;
	}
}
bool Par(int a, int b){
	if (!a)return false;
	if (a > b)return false;
	return b <= Ed[a];
}
void DFS2(int a){
	if (C[a][0]){
		DFS2(C[a][0]);
	}
	printf("%d ", a);
	if (C[a][1]){
		DFS2(C[a][1]);
	}
}
int main()
{
	int i;
	char p[20];
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++)P[i] = i;
	for (i = 1; i <= Q; i++){
		scanf("%d%d", &w[i][0], &w[i][1]);
		scanf("%s", p);
		if (p[0] == 'L')w[i][2] = 1;
		else w[i][2] = 2;
		if (w[i][0] >= w[i][1]){
			printf("IMPOSSIBLE\n");
			return 0;
		}
		if (P[w[i][0]] < w[i][1])P[w[i][0]] = w[i][1];
		if (w[i][2] == 1 && L[w[i][0]] < w[i][1])L[w[i][0]] = w[i][1];
	}
	for (i = 1; i <= n; i++){
		Add(i, P[i]);
	}
	for (i = n; i >= 1; i--){
		P[i] = Max(i, P[i]);
		Add(i, P[i]);
	}
	DFS(1, n);
	if (ck){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (i = 1; i <= Q; i++){
		if (w[i][2] == 1){
			if (!Par(C[w[i][0]][0], w[i][1])){
				printf("IMPOSSIBLE\n");
				return 0;
			}
		}
		else{
			if (!Par(C[w[i][0]][1], w[i][1])){
				printf("IMPOSSIBLE\n");
				return 0;
			}
		}
	}
	DFS2(1);
	return 0;
}