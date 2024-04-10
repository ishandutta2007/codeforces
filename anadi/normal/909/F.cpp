#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int tab[N];

void rek(int l, int k){
	int c = k - l;
	if(c <= 0)
		return;
	
	int m = 1;
	while(m <= c)
		m *= 2;
	m /= 2;
	--m;
	
	for(int i = l + 1; i < m + l; ++i)
		tab[i] = (i - l) ^ m;

	tab[m + l] = m + 1;
	tab[m + l + 1] = m;
	
	for(int i = l + m + 2; i <= k; ++i)
		swap(tab[i], tab[((i - l - m - 1) ^ m) + l]);	
	rek(l + m + 1, k);
}

void solve(){
	if(n == 4){
		puts("YES");
		puts("2 1 4 3");
		return;
	}
	
	if(n == 5){
		puts("NO");
		return;
	}
	
	if(n == 6){
		puts("YES");
		puts("6 5 4 3 2 1");
		return;
	}
	
	if(n%2 == 1){
		puts("NO");
		return;
	}
	
	for(int i = 1; i <= n; ++i)
		tab[i] = i;
	
	rek(0, n);
	
	puts("YES");
	for(int i = 1; i <= n; ++i)
		printf("%d ", tab[i]);
	puts("");
}

int main(){
	scanf("%d", &n);
	if(n == 1){
		puts("NO");
		puts("NO");
		return 0;
	}
	
	if(n == 2){
		puts("YES");
		puts("2 1");
		puts("NO");
		return 0;
	}
	
	if(n == 3){
		puts("NO");
		puts("NO");
		return 0;
	}
	
	solve();
	int k = 1;
	while(k < n)
		k *= 2;
	
	if(n == k || n == 5){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	if(n == 6){
		puts("5 3 2 6 1 4");
		return 0;
	}
	
	printf("5 3 2 6 7 4 1 ");
	
	int l = 8;
	for(int i = 8; i < n; i *= 2){
		int to = min(2 * i - 1, n);
		for(int j = l; j <= to; ++j)
			printf("%d ", j == to ? l : j + 1);
		l = to + 1;
	}

	return 0;
}