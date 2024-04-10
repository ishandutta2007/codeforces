#include <iostream>
using namespace std;

int a[200005];
int mark[200005];
int main() {
	int n, npart = 1, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		m += t;
	}
	for (int i = 1; i <= n; i++) {
		if(mark[i] == 0) {
			mark[i] = npart;
			int x = a[i];
			while (x != i) {
				//cout << i << " " << x << endl;
				mark[x] = npart;
				x = a[x];
			}
			npart ++;
		}
	}
	if (npart == 2)
		npart --;
	npart -= m % 2;
	cout << npart;
	return 0;
}