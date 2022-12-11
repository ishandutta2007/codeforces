#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int a[101], b[101];

int d[2][101][101 * 101];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int sum = 0;
	for(int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
		sum += 2 * b[i];
	}
	
	d[0][0][0] = sum;
	for(int p = 0;p < n;p++) {
		int nM = (p + 1) & 1;
		int M = 1 - nM;
		for(int k = 0;k < n;k++) {
			for(int s = 0;s <= 100 * 100;s++) {
				d[nM][k][s] = max(
					d[nM][k][s],
					d[M][k][s] - b[p]
				);
				
				d[nM][k + 1][s + a[p]] = max(
					d[nM][k + 1][s + a[p]],
					d[M][k][s]
				);
				
				d[M][k][s] = 0;
			}
		}
	}
	
	for(int k = 1;k <= n;k++) {
		int val = 0;
		for(int s = 0;s <= 100 * 100;s++) {
			val = max(min(2 * s, d[n & 1][k][s]), val);
		}
		
		cout << val / 2. << " ";
	}
	cout << endl;
	
	return 0;
}