#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1000];
double P[1000][1000];
double R[1000], TP[1000];
bool v[1000][1000];
int n, K, w[110], cnt, L[110];
void Inverse(int b, int e){
	int i;
	for (i = b; i <= (b + e) / 2; i++){
		swap(L[i], L[b + e - i]);
	}
}
int Num(int a, int b){
	return a * 31 + b;
}
int main(){
	int i, j, k, l, c1, c2, x;
	double t, Res = 0.0;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		L[i] = i;
	}
	t = 1.0 / (n*(n + 1) / 2);
	for (i = 1; i <= n; i++){
		for (j = i; j <= n; j++){
			Inverse(i, j);
			for (k = 1; k <= n; k++){
				for (l = k+1; l <= n; l++){
					c1 = Num(k,l);
					c2 = Num(L[k],L[l]);
					if (!v[c1][c2]){
						v[c1][c2] = true;
						E[c1].push_back(c2);
					}
					P[c1][c2] += t;
				}
			}
			Inverse(i, j);
		}
	}
	for (i = 1; i <= n; i++){
		for (j = i + 1; j <= n; j++){
			if (w[i] < w[j])R[Num(j, i)] = 1.0;
			else R[Num(i, j)] = 1.0;
		}
	}
	while (K--){
		for (i = 1; i <= n; i++){
			for (k = i + 1; k <= n; k++){
				c1 = Num(i, k);
				TP[c1] = 0.0;
				for (j = 0; j < E[c1].size(); j++){
					x = E[c1][j];
					TP[c1] += R[x] * P[c1][x];
				}
				TP[Num(k, i)] = 1.0 - TP[c1];
			}
		}
		for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (i != j)R[Num(i, j)] = TP[Num(i, j)];
	}
	for (i = 1; i < n; i++){
		for (j = i + 1; j <= n; j++){
			Res += R[Num(i, j)];
		}
	}
	printf("%.11lf\n", Res);
	return 0;
}