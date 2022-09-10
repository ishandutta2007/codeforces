#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int mxn = 2e5 + 7;

int n, m;

int main(){
	scanf("%d", &n);
	int ile = 0;
	int x = 10;
	int add = 1;
	int now = 1;
	while(ile < n){
		if(now == x){
			x *= 10;
			++add;
		}			
		ile += add;
		++now;
	}
	
	now--;
	while(ile > n){
		now /= 10;
		--ile;
	}
	
	printf("%d\n", now %10);
	return 0;
}