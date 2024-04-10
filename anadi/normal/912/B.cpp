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

int main(){
	LL n, k;
	cin >> n >> k;
	
	if(k == 1){
		cout << n;
		return 0;
	}
	
	LL cur = 1LL;
	while(cur <= n)
		cur *= 2LL;
	cout << cur - 1LL;
	return 0;
}