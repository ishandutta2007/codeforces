#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 105;
int cnt[N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int k, n, s, p;
	cin >> k >> n >> s >> p;
	int x = (int) ceil((double) n / s);
	cout << (int) ceil((double) k * x / p);
}