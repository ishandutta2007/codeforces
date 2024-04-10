#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


const int N = 55;
int a[N][N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	cout << n / 2 + 1;
}