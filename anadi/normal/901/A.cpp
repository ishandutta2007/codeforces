#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int a[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
		scanf("%d", &a[i]);
	
	int nr = -1;
	for(int i = 1; i <= n; ++i)
		if(a[i - 1] > 1 && a[i] > 1)
			nr = i;
	
	if(nr == -1){
		puts("perfect");
		return 0;
	}
	
	puts("ambiguous");
	printf("0 ");
	int sum = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= a[i]; ++j)
			printf("%d ", sum);
		sum += a[i];
	}
	
	puts("");
	printf("0 ");
	
	sum = 1;
	for(int i = 1; i < nr; ++i){
		for(int j = 1; j <= a[i]; ++j)
			printf("%d ", sum);
		sum += a[i];
	}
	
	printf("%d ", sum - 1);
	for(int j = 2; j <= a[nr]; ++j)
		printf("%d ", sum);
	sum += a[nr];
	
	for(int i = nr + 1; i <= n; ++i){
		for(int j = 1; j <= a[i]; ++j)
			printf("%d ", sum);
		sum += a[i];
	}

	return 0;
}