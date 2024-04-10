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
const LL IxNF = 1e18 + 9LL;

int main(){
	LL n, k;
	cin >> n >> k;
	cout << (k + n - 1) / n;
	return 0;
}