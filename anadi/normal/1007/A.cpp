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
set <int> S;
map <int, int> M;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		M[a]++;
		S.insert(a);
	}
	
	int sum = 0, pref = 0;
	for(int v: S){
		sum += max(0, M[v] - pref);
		if(M[v] > pref)
			pref = M[v];
	}
	
	printf("%d\n", n - sum);
	return 0;
}