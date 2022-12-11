#include <iostream>
#include <cmath>
#include <numeric>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int der;
	cin >> der;
	
	int g = 0;
	
	for(int i = 1;i < n;i++) {
		int cur;
		cin >> cur;
		g = gcd(der - cur, g);
		der = cur;
	}
	
	for(int j = 0;j < m;j++) {
		int v;
		cin >> v;
		
		cout << gcd(g, der + v) << " ";
	}
	cout << endl;
	return 0;
}