#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const LL INF = 1e9 + 7LL;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int i = 1;
	while(k > 0){
		k -= i;
		++i;
	}
	
	--i;
	i += k;

	for(int j = 1; j <= n; ++j){
		int a;
		scanf("%d", &a);
		if(j == i)
			printf("%d\n", a);
	}
	
	return 0;
}