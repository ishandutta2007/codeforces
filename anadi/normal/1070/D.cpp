#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, k;
int in[N];

int main(){
	scanf("%d %d", &n, &k); 
	int Left = 0; LL res = 0;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);

		Left += a;
		res += Left / k;
		
		if(Left > a && Left < k)
			++res, Left = 0;
		Left %= k;
	}
	
	res += Left > 0;
	printf("%lld\n", res);
	return 0;
}