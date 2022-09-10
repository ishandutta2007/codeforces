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

int n, k;

int nwd(int a, int b){
	if(b == 0)
		return a;
	return nwd(b, a%b);
}

int main(){
	scanf("%d %d", &n, &k);
	int sum = k;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);	
		sum = nwd(sum, a%k);
	}
	
	vector <int> res;
	for(int i = 0; i < k; ++i)
		if(i%sum == 0)
			res.push_back(i);
	
	printf("%d\n", (int)res.size());
	for(int v: res)
		printf("%d ", v);
	return 0;
}