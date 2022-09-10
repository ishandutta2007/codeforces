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
	int q;
	cin >> q;
	while(q--){
		LL n, m, k;
		cin >> n >> m >> k;
		
		if(max(n, m) > k){
			cout << "-1\n";
			continue;
		}
		
		if(n%2 == m%2){
			LL d = max(n, m);
			if(d%2 == k%2)
				cout << k << "\n";
			else
				cout << k - 2 << "\n";
		}
		else
			cout << k - 1 << "\n";
	}

	return 0;
}