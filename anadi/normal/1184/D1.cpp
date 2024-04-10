#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 2e5 + 7;

int n, k, m, t;

int main(){
	cin >> n >> k >> m >> t;
	while(t--){
		int a, b;
		cin >> a >> b;

		if(a == 1){
			if(k >= b)
				++k;
			++n;
		}
		else{
			if(k > b){
				k -= b;
				n -= b;
			}
			else
				n = b;
		}
		
		printf("%d %d\n", n, k);
	}

	return 0;
}