#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int d;

void solve(){
	cin >> d;
	if(d == 1 || d == 2 || d == 3){
		puts("N");
		return;
	}
	
	long double delta = d * d - 4.0 * d;
	long double b = (d - sqrt(delta)) / 2.0;
	long double a = d - b;
	printf("Y %.12Lf %.12Lf\n", a, b);
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	int cases;
	cin >> cases;
	while(cases--)
		solve();
	return 0;
}