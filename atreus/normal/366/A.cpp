#include <iostream>

using namespace std;

int a[5][5];

int main() {
	int k;
	cin >> k;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			cin >> a[i][j];
	int p = 0, q = 1000000, pq = 1000000, inx = -1;
	for (int i = 1; i <= 4; i++){
		int m = min(a[i][1], a[i][2]);
	      	int n = min(a[i][3], a[i][4]);
		int mn = m + n;
		if (mn <= k && mn < pq){
			pq = mn;
			p = m;
			q = n;
			inx = i;
		}	
	}
	if (inx == -1)
		cout << -1 << endl;
	else 
		cout << inx << " " << p << " " << max(q, k - p) << endl;
	
}