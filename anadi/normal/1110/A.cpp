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
const LL INF = 1e18 + 9LL;

int b, n;

int main(){
	cin >> b >> n; 
	b = b & 1;

	int s = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		
		a = a & 1;
		if(i + 1 < n)
			s += a * b;
		else
			s += a;
	}
	
	puts((s & 1) ? "odd" : "even");
	return 0;
}