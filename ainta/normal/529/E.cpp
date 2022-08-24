#include<stdio.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
int n, K, Q, w[5010], Res;
unordered_map<int, int>Map;
int main(){
	int i, a, j, k, t;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= K; i++){
		for (j = 1; j <= n; j++){
			if (!Map[i*w[j]])Map[i*w[j]] = i;
		}
	}
	scanf("%d", &Q);
	while (Q--){
		scanf("%d", &a);
		Res = K+1;
		if (Map[a])Res = Map[a];
		for (i = 1; i < K; i++){
			for (j = 1; j <= n; j++){
				if (i*w[j] >= a)continue;
				if (Map[a - i*w[j]]){
					Res = min(Res, Map[a - i*w[j]] + i);
				}
			}
		}
		if (K < Res)printf("-1\n");
		else printf("%d\n", Res);
	}
}