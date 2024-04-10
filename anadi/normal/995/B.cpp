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
int tab[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n + n; ++i)
		scanf("%d", &tab[i]);
	
	int res = 0;
	for(int i = 1; i <= n + n; i += 2){
		int pl = -1;
		for(int j = i + 1; j <= n + n; ++j)
			if(tab[j] == tab[i]){
				pl = j;
				break;
			}
		
		while(pl > i + 1){
			swap(tab[pl], tab[pl - 1]);
			++res;
			--pl;
		}
	}
	
	printf("%d\n", res);
	return 0;
}