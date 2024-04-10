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

int main(){
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	
	if(abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3 <= abs(x - y) * t1)
		puts("YES");
	else
		puts("NO");
	return 0;
}