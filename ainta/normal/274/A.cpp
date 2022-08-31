#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int w[100100];
int n, K;
set<int>Set;
int main()
{
	int i, R = 0;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++){
		if (w[i] % K != 0){
			R++;
			Set.insert(w[i]);
		}
		else{
			if (Set.empty() || (Set.find(w[i]/K) == Set.end())){
				R++;
				Set.insert(w[i]);
			}
		}
	}
	printf("%d\n", R);
}