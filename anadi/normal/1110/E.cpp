#include <bits/stdc++.h>

using namespace std;

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
int a[N], b[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	
	for(int i = n; i > 0; --i){
		a[i] -= a[i - 1];
		b[i] -= b[i - 1];
	}
	
	sort(a + 1, a + n);
	sort(b + 1, b + n);
	
	for(int i = 0; i < n; ++i)
		if(a[i] != b[i]){
			puts("No");
			return 0;
		}
	
	puts("Yes");
	return 0;
}