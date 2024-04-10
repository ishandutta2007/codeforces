#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 9;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

LL a, b, x, y, z;

int main(){
	cin >> a >> b;
	cin >> x >> y >> z;
	
	LL d = 2 * x + y, e = y + 3 * z;
	cout << max(d - a, 0LL) + max(e - b, 0LL);
	return 0;
}