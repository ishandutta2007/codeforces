#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;
const int inf  = 1e9 + 7;

int n, m;

int main(){
	scanf("%d %d", &n, &m);
	int sum = 0, ile = 0, ile2 = 0;
	for(int i = 1; i <= m; ++i){
		int a;	scanf("%d", &a);
		sum += a + a%2;
		if(a%4 == 2)
			++ile;
		if(a%2 == 1)
			++ile2;
	}
	
	ile -= 2 * n + ile2;
	ile = max(ile, 0);
	sum += ile - (ile / 3);
	
	if(sum <= 8 * n)
		puts("YES");
	else
		puts("NO");
	return 0;
}