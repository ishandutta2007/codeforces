#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int a, b;
int ask(int c, int d) {
	//int L = a ^ c;
	//int R = b ^ d;

	////cerr << c << " " << d << " " << L << " " << R << endl;
	//if (L > R)return 1;
	//if (L == R)return 0;
	//if (L < R)return -1;
	
	cout << "? " << c << " " << d << endl;
	cout << flush;
	int x;
	cin >> x;
	return x;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cin >> a >> b;
	int X = ask(0, 0);
	int A = 0;
	int B = 0;
	int k;
	for (int i = 29; i >= 0; i--) {
		k = ask(A ^ (1 << i), B ^ (1 << i));
		if (k == 0 || k == X) {
			k = ask(A ^ (1 << i), B);
			if (k == -1) {
				A ^= (1 << i);
				B ^= (1 << i);
			}
		}
		else {
			if (k == 1) {
				B ^= (1 << i);
			}
			else {
				A ^= (1 << i);
			}
			X = ask(A, B);
		}
	}
	
	cout << "! " << A << " " << B << endl;
	cout << flush;

}