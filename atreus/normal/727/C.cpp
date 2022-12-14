#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

const int maxn = 5e3 + 100;
int a[maxn];

int main() {
	ifstream fin("tst.txt");
	ofstream fout("tst.txt");
	int n, x, y, z;
	cin >> n;
	cout << "? 1 2" << endl;
	cin >> x;
	cout << "? 2 3" << endl;
	cin >> y;
	cout << "? 1 3" << endl;
	cin >> z;
	a[1] = (x - y + z) / 2;
	a[2] = x - a[1];
	a[3] = z - a[1];
	for (int i = 4; i <= n; i++){
		cout << '?' << " " << i << " " << i - 1 << endl;
		int k;
		cin >> k;
		a[i] = k - a[i - 1];
	}
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}