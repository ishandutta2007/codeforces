#include <bits/stdc++.h>

using namespace std;

typedef double d;
typedef long long int LL;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PDD pair <d, d>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;

int n;
LL t[505][505];
LL row[505];
LL col[505];
LL diag[2];
int a, b;

int main(){
	scanf("%d", &n);
	
	if(n == 1){
		puts("1");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			scanf("%I64d", &t[i][j]);
			
			if(t[i][j] == 0){
				a = i;
				b = j;
			}
			
			row[i] += t[i][j];
			col[j] += t[i][j];
			if(i == j)
				diag[0] += t[i][j];
			if(i + j == n + 1)
				diag[1] += t[i][j];
		}
	
	LL correct_sum = 0LL;
	if(a == 1)
		correct_sum = row[2];
	else
		correct_sum = row[1];
	
	LL ans = correct_sum - row[a];
	
	if(a == b)
		diag[0] += ans;
	if(a + b == n + 1)
		diag[1] += ans;
	
	row[a] += ans;
	col[b] += ans;
	
	bool ok = true;
	for(int i = 1; i <= n; ++i)
		if(col[i] != correct_sum || row[i] != correct_sum)
			ok = false;
	
	if(diag[0] != correct_sum || diag[1] != correct_sum)
		ok = false;
	
	if(ans <= 0)
		ok = false;
	
	ok ? printf("%I64d\n", ans) : puts("-1");
	return 0;
}