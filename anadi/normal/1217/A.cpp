#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--){
		int a, b, c;
		cin >> a >> b >> c;
		
		if(a + c <= b){
			puts("0");
			continue;
		}
		
		int s = 0, e = c;
		while(s < e){
			int m = (s + e) / 2;
			if(a + m <= b + c - m)
				s = m + 1;
			else
				e = m;
		}
		
		printf("%d\n", c - s + 1);
	}

	return 0;
}