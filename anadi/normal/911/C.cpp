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
const int INF = 1e9 + 9;

int a[10];

int main(){
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	sort(a, a + 3);
	
	if(a[0] == 1){
		puts("YES");
		return 0;
	}
	
	if(a[0] == 2){
		if(a[1] == 2){
			puts("YES");
			return 0;
		}
		
		if(a[1] == 4 && a[2] == 4){
			puts("YES");
			return 0;
		}
		
		puts("NO");
		return 0;
	}

	if(a[0] == 3 && a[2] == 3)
		puts("YES");
	else
		puts("NO");
	return 0;
}