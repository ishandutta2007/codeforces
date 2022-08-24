#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, Q, w[201000], D[501000];
bool v[201000];
long long Res;
bool pri[501000];
vector<int>E[501000];
void Do(int a, int x, int num, int cc, bool ck){
	if (num == E[a].size()){
		if (ck){
			D[x]--;
			if (cc & 1){
				Res += D[x];
			}
			else{
				Res -= D[x];
			}
		}
		else{
			if (cc & 1){
				Res -= D[x];
			}
			else{
				Res += D[x];
			}
			D[x]++;
		}
		return;
	}
	Do(a, x, num + 1, cc, ck);
	Do(a, x*E[a][num], num + 1, cc + 1, ck);
}
int main(){
	int i, a, j;
	for (i = 2; i <= 500000; i++){
		if (pri[i])continue;
		for (j = i; j <= 500000; j+=i){
			pri[j] = true;
			E[j].push_back(i);
		}
	}
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	while (Q--){
		scanf("%d", &a);
		Do(w[a], 1, 0, 0, v[a]);
		v[a] = !v[a];
		printf("%lld\n", Res);
	}
}