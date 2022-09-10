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

int a[10];
int sum(int from, int to){
	int ret = 0;
	for(int i = from; i <= to; ++i)
		ret += i;
	return ret;
}

int main(){
	for(int i = 0; i < 6; ++i)
		cin >> a[i];
	
	int d = min(a[2], a[4]);
	int res = sum(a[3], a[3] + d - 1) + sum(a[3] + 1, a[3] + d);
	
	a[3] += d;
	a[2] -= d, a[4] -= d;
	d = max(a[4], a[2]);
	
	res += a[3] * 2 * d;
	d = min(a[1], a[5]);
	
	res += sum(a[0], a[0] + d - 1) + sum(a[0] + 1, a[0] + d);
	cout << res << "\n";
	return 0;
}