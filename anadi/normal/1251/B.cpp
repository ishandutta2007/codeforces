#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int sum[5];
int oddPalind;

void solve(){
	cin >> n;
	sum[0] = sum[1] = oddPalind = 0;

	for(int i = 1; i <= n; ++i){
		string a;
		cin >> a;
		
		for(auto v: a)
			sum[v - '0']++;
		
		if(a.size() & 1)
			oddPalind++;
	}
	
	int sub = (sum[0] & 1) + (sum[1] & 1);
	if(sub > oddPalind)
		cout << n - 1 << "\n";
	else
		cout << n << "\n";
}

int main(){
	int cases;
	cin >> cases;
	
	while(cases--)
		solve();
	return 0;
}