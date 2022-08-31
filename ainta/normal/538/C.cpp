#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, a, b, ta, tb, r, da, db;
int main(){
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		if (i == m){
			r = max(r, b + n - a);
		}
		if (i == 1){
			r = max(r, b + a - 1);
			ta = a, tb = b;
			continue;
		}
		if (a - ta < b - tb || a - ta < tb - b){
			printf("IMPOSSIBLE\n");
			return 0;
		}
		da = a - ta;
		if (tb < b){
			db = b - tb;
			r = max(b + (da - db) / 2, r);
		}
		else{
			db = tb - b;
			r = max(tb + (da - db) / 2, r);
		}
		ta = a, tb = b;
	}
	printf("%d\n", r);
}