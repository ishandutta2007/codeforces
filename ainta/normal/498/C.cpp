#include<stdio.h>
#include<algorithm>
#include<map>
#define INF 999999999
using namespace std;
map<int, int>Map;
int n, m, cnt, D[101][1010];
int F[110][110], Res;
bool E[110][110], v[110];
void Do(int ord, int num){
	int i;
	for (i = 2; i*i <= num; i++){
		if (num%i == 0){
			if (!Map[i])Map[i] = ++cnt;
			while (num%i == 0)num /= i, D[ord][Map[i]]++;
		}
	}
	if (num != 1){
		if (!Map[num])Map[num] = ++cnt;
		D[ord][Map[num]] = 1;
	}
}
int Flow(int node, int ff){
	v[node] = true;
	if (node == n + 1){
		Res += ff;
		return ff;
	}
	int i, f;
	if (F[node][n + 1]){
		f = Flow(n + 1, min(ff, F[node][n + 1]));
		if (f){
			F[node][n + 1] -= f;
			F[n + 1][node] += f;
			return f;
		}
	}
	for (i = node % 2 + 1; i <= n; i += 2){
		if (!v[i] && F[node][i]){
			f = Flow(i, min(ff, F[node][i]));
			if (f){
				F[node][i] -= f;
				F[i][node] += f;
				return f;
			}
		}
	}
	return 0;
}
int main(){
	int i, a, b, T, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		Do(i, a);
	}
	while (m--){
		scanf("%d%d", &a, &b);
		if (a % 2 == 0)swap(a, b);
		E[a][b] = true;
	}
	for (T = 1; T <= cnt; T++){
		for (i = 1; i <= n; i += 2){
			F[0][i] = D[i][T];
		}
		for (i = 2; i <= n; i += 2){
			F[i][n + 1] = D[i][T];
		}
		for (i = 1; i <= n; i+=2){
			for (j = 2; j <= n; j += 2){
				if (E[i][j])F[i][j] = INF, F[j][i] = 0;
			}
		}
		for (i = 0; i <= n + 1; i++)v[i] = false;
		while (Flow(0, INF)){
			for (i = 0; i <= n + 1; i++)v[i] = false;
		}
	}
	printf("%d\n", Res);
}