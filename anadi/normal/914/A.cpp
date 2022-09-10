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

int n, m;
int mx = -N;

bool square(int a){
	for(int i = 0; i <= 1000; ++i)
		if(i * i == a)
			return true;
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a; scanf("%d", &a);
		if(a < 0)
			mx = max(mx, a);
		if(!square(a))
			mx = max(mx, a);
	}
	
	printf("%d\n", mx);
	return 0;
}