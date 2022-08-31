#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[50], p[50];
bool chk;
void Do(int M, int a);
void DFS(int i, int c, int pv, int ck){
	if (i == c){
		if (ck && p[i]){
			p[i]--;
			Do(w[pv], pv + 1);
			if (chk)return;
			p[i]++;
		}
		return;
	}
	if (p[i] && c - i >= i){
		p[i]--;
		DFS(i, c - i, pv, 1);
		if (chk)return;
		p[i]++;
	}
	DFS(i + 1, c, pv, ck);
	if (chk)return;
}
void Do(int M, int a){
	if (a == n){
		chk = true;
		return;
	}
	int i, tp[50];
	p[w[a]]++;
	DFS(1, w[a] - 1, a, 0);
	if (chk)return;
	p[w[a]]--;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &w[i]);
	}
	sort(w, w + n);
	if (w[n / 2] != 1 || w[n - 1] != n){
		printf("NO\n");
		return 0;
	}
	if (n == 1){
		printf("YES\n");
		return 0;
	}
	for (i = 0; w[i] == 1; i++){
		p[1]++;
	}
	Do(1, i);
	printf(chk ? "YES\n" : "NO\n");
}