#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
char a[N], b[N];

int main(){
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	
	int res = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] == b[i])
			continue;

		++res;
		if(b[i] == a[i + 1] && a[i + 1] != b[i + 1])
			swap(a[i], a[i + 1]);
	}
	
	printf("%d\n", res);
	return 0;
}