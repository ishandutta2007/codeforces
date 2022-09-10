#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const int INF = 1e9 + 7;
const int MX = 1e9 + 9;

int n, m;
int a, b, c, d;

int main(){
	scanf("%d %d", &n, &m);
	if(n == 4 || m < n + 1){
		puts("-1");
		return 0;
	}
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	printf("%d %d ", a, c);
	for(int i = 1; i <= n; ++i)
		if(i != a && i != b && i != c && i != d)
			printf("%d ", i);
	printf("%d %d\n", d, b);
	
	printf("%d %d ", c, a);
	for(int i = 1; i <= n; ++i)
		if(i != a && i != b && i != c && i != d)
			printf("%d ", i);
	printf("%d %d\n", b, d);
	return 0;
}