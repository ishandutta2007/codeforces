#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int N = 10;

int main() {
	int d, l, v1, v2;
	cin >> d >> l >> v1 >> v2;
	cout << fixed << setprecision(7);
	cout << (double) (l - d) / (v1 + v2);
}