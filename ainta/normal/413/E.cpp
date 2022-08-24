#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
#define N_ 200010
int S[N_], SS[N_ * 2];
set<int>Set;
set<int>::iterator it;
int n, Q;
char p[2][N_];
int main(){
	int i, tx = 0, ty = 0, x1, y1, x2, y2, xx, r;
	scanf("%d%d", &n, &Q);
	scanf("%s", p[0]+1);
	scanf("%s", p[1]+1);
	for (i = 1; i <= n; i++){
		if (p[0][i] == 'X' && p[1][i] == 'X')SS[i * 2]++;
		if (p[0][i] == 'X' && p[1][i + 1] == 'X')SS[i * 2 + 1]++;
		if (p[1][i] == 'X' && p[0][i + 1] == 'X')SS[i * 2 + 1]++;
		S[i] = S[i - 1] + 1;
		if (p[0][i] != p[1][i]){
			if (p[0][i] == '.') x1 = 0;
			else x1 = 1;
			if (ty != 0 && x1 != tx) S[i]++;
			tx = x1, ty = i;
			Set.insert(i);
		}
	}
	for (i = 1; i <= n*2; i++)SS[i] += SS[i - 1];
	while (Q--){
		scanf("%d%d", &x1, &x2);
		x1--, x2--;
		y1 = x1 % n + 1, x1 /= n;
		y2 = x2 % n + 1, x2 /= n;
		if (y1 > y2) swap(y1, y2), swap(x1, x2);
		if (SS[y2 * 2] != SS[y1 * 2]){
			printf("-1\n");
			continue;
		}
		if (Set.lower_bound(y1) == Set.lower_bound(y2)){
			printf("%d\n",abs(x2 - x1) + abs(y2 - y1));
			continue;
		}
		it = Set.lower_bound(y1);
		if (p[0][*it] == '.')xx = 0; else xx = 1;
		r = abs(xx - x1) + abs(*it - y1);
		y1 = *it;
		it = Set.lower_bound(y2);
		if (it == Set.end() || *it > y2)it--;
		if (p[0][*it] == '.')xx = 0; else xx = 1;
		r += abs(xx - x2) + abs(y2 - *it);
		y2 = *it;
		r += S[y2] - S[y1];
		printf("%d\n", r);
	}
	return 0;
}