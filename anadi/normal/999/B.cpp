#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
string s;

int main(){
	cin >> n >> s;
	for(int i = 1; i <= n; ++i)
		if(n%i == 0)
			reverse(s.begin(), s.begin() + i);
	cout << s;
	return 0;
}