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

char ans[1005][7];

void ustaw(int i){
	if(ans[i][0] == ans[i][1] && ans[i][0] == 'O')
		ans[i][0] = ans[i][1] = '+';
	else
		ans[i][3] = ans[i][4] = '+';
}

int main(){
	int n;
	scanf("%d", &n);
	bool yes = false;
	
	for(int i = 1; i <= n; ++i){
		scanf("%s", ans[i]);
		if(yes)
			continue;
		if((ans[i][0] == ans[i][1] && ans[i][0] == 'O') || (ans[i][3] == ans[i][4] && ans[i][3] == 'O')){
			yes = true;
			ustaw(i);
		}
	}
	
	if(yes){
		puts("YES");
		for(int i = 1; i <= n; ++i)
			printf("%s\n", ans[i]);
	}
	else
		puts("NO");
	return 0;
}